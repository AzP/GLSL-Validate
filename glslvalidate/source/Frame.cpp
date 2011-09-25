/************************************************************************
*                                                                       *
*               Copyright (C) 2002-2006  3Dlabs Inc. Ltd.               *
*                                                                       *
*                        All rights reserved.                           *
*                                                                       *
* Redistribution and use in source and binary forms, with or without    *
* modification, are permitted provided that the following conditions    *
* are met:                                                              *
*                                                                       *
*     Redistributions of source code must retain the above copyright    *
*     notice, this list of conditions and the following disclaimer.     *
*                                                                       *
*     Redistributions in binary form must reproduce the above           *
*     copyright notice, this list of conditions and the following       *
*     disclaimer in the documentation and/or other materials provided   *
*     with the distribution.                                            *
*                                                                       *
*     Neither the name of 3Dlabs Inc. Ltd. nor the names of its         *
*     contributors may be used to endorse or promote products derived   *
*     from this software without specific prior written permission.     *
*                                                                       *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
* wxT("AS IS") AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
* COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, *
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN     *
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                       *
************************************************************************/
/************************************************************************
* Frame.cpp                                                             *
* Author:  Philip Rideout                                               *
* Maintained By:  Joshua Doss                                           *
* Community Contributor(s):  Sebastian Schuberth                        *
* Last Changed Date: 01/04/2006                                         *
************************************************************************/

#include "Frame.h"
#include "Tables.h"
#include "App.h"
#include "DropTarget.h"
#include "labs_icon.xpm"
#include <wx/ffile.h>
#include <wx/gdicmn.h>
#include <fcntl.h>
#include <sys/io.h>
#include <sys/types.h>
#include <string>

#define APP_VERSION wxT("1.9")

BEGIN_EVENT_TABLE(TFrame, wxFrame)
	EVT_SIZE(TFrame::OnSize)
	EVT_MENU(Id::FileParseVertex, TFrame::OnFileParseVertex)
	EVT_MENU(Id::FileParseFragment, TFrame::OnFileParseFragment)
	EVT_MENU(Id::FileReparseCurrent, TFrame::OnFileReparseCurrent)
	EVT_MENU(Id::FileClear, TFrame::OnFileClear)
	EVT_MENU(Id::FileSave, TFrame::OnFileSave)
	EVT_MENU(Id::FileExit, TFrame::OnFileExit)
	EVT_MENU(Id::HelpCommandLine, TFrame::OnHelpCommandLine)
	EVT_MENU(Id::HelpAbout, TFrame::OnHelpAbout)
END_EVENT_TABLE()

wxColour MessageColor(0, 0, 160);
wxColour SuccessColor(0, 80, 0);
wxColour FailureColor(160, 0, 0);

TFrame::TFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(0, -1, title, pos, size, wxDEFAULT_FRAME_STYLE | wxCLIP_CHILDREN)
{
	wxGetApp().SetFrame(this);

	wxBoxSizer* vertical = new wxBoxSizer(wxVERTICAL);
	text = new wxTextCtrl(this, Id::WidgetText, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_RICH | wxTE_RICH2 | wxTE_READONLY | wxTE_MULTILINE);
	vertical->Add(text, 1, wxALIGN_CENTRE_VERTICAL | wxEXPAND | wxALL);
	text->SetBackgroundColour(*wxWHITE);

	wxTextAttr bold(*wxBLACK , *wxWHITE, wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD));
	text->SetDefaultStyle(bold);

	wxMenu* menu;
	wxMenuBar* menuBar = new wxMenuBar;

	menu = new wxMenu;
	menu->Append(Id::FileParseVertex, wxT("Parse vertex shader(s)..."));
	menu->Append(Id::FileParseFragment, wxT("Parse fragment shader(s)..."));
	menu->Append(Id::FileReparseCurrent, wxT("Re-parse current shader(s)\tF5"));
	menu->Append(Id::FileClear, wxT("Clear log"));
	menu->Append(Id::FileSave, wxT("Save log..."));
	menu->AppendSeparator();
	menu->Append(Id::FileExit, wxT("Exit\tQ"));
	menuBar->Append(menu, wxT("File"));

	menu = new wxMenu;
	menu->Append(Id::HelpCommandLine, wxT("Command line options..."));
	menu->Append(Id::HelpAbout, wxT("About..."));
	menuBar->Append(menu, wxT("Help"));

        SetMenuBar(menuBar);
        SetSizer(vertical);
        wxIcon icon(wxICON(labs));
        SetIcon(icon);
        //SetIcon(wxIcon(wxT("3DLABS_ICON"), wxBITMAP_TYPE_ICO_RESOURCE));

	SetDropTarget( new TDropTarget(this) );
}

void TFrame::SetColor(wxColour* color)
{
	text->SetDefaultStyle(wxTextAttr(*color, *wxWHITE));
}

void TFrame::OnHelpCommandLine(wxCommandEvent& event)
{
	wxCmdLineParser parser(TApp::CommandLineDescription);
	parser.Usage();
}

void TFrame::OnHelpAbout(wxCommandEvent& event)
{
	wxMessageBox(
		wxT("GLSL Syntax Validator v") APP_VERSION wxT("\n")
		wxT("Copyright © 2005 3Dlabs.  All rights reserved.\n\n")
		wxT("glslvalidate: a tool that checks shaders for valid syntax using the 3Dlabs open source GLSL parser.\n\n")
		wxT("GLSL parser source code is available at http://developer.3dlabs.com/downloads\n\n")
		wxT("For questions and feedback, go to http://www.3dlabs.com/contact\n\n")
		wxT("Thanks to Jordan Russell for InnoSetup."),
		wxT("about glslvalidate"), wxOK | wxICON_INFORMATION, this);
}

void TFrame::OnFileExit(wxCommandEvent& event)
{
	Close();
	event.Skip();
}

void TFrame::OnFileParseVertex(wxCommandEvent& event)
{
	wxFileDialog dialog(this, wxT("Open vertex shader"), wxT(""), wxT(""), wxT("All (*.*)|*.*|Vertex shader (*.vert;*.v)|*.vert;*.v"), wxFD_OPEN | wxFD_MULTIPLE);
	if (dialog.ShowModal() == wxID_OK)
	{
		dialog.GetPaths(filenames);
		language = EShLangVertex;
		for (unsigned int i = 0; i < filenames.Count(); ++i)
		{
			Compile(filenames[i], language);
		}
	}
}

void TFrame::OnFileParseFragment(wxCommandEvent& event)
{
	wxFileDialog dialog(this, wxT("Open fragment shader"), wxT(""), wxT(""), wxT("All (*.*)|*.*|Fragment shader (*.frag;*.f)|*.frag;*.f"), wxFD_OPEN | wxFD_MULTIPLE);
	if (dialog.ShowModal() == wxID_OK)
	{
		dialog.GetPaths(filenames);
		language = EShLangFragment;
		for (unsigned int i = 0; i < filenames.Count(); ++i)
		{
			Compile(filenames[i], language);
		}
	}
}

void TFrame::OnFileReparseCurrent(wxCommandEvent& event)
{
	for(unsigned int i = 0; i < filenames.Count(); ++i)
	{
		Compile(filenames[i], language);
	}
}

void TFrame::OnFileClear(wxCommandEvent& event)
{
	text->Clear();
}

void TFrame::Printf(const wchar_t* format, ...)
{
	wxString message;

	va_list marker;
	va_start(marker, format);
	text->AppendText(message.wx_str());
}

void TFrame::Compile(const wxFileName& filename, EShLanguage language)
{
	SetColor(&MessageColor);
	if (language == EShLangVertex)
		Printf(wxT("Parsing vertex shader "));
	else
		Printf(wxT("Parsing fragment shader "));

	Printf(L"'%s'....\n", filename.GetFullName().c_str());

	ShInitialize();
	ShHandle compiler = ShConstructCompiler(language, 0);

	if (!compiler) {
		wxGetApp().Errorf("Unable to construct compiler.\n");
		return;
	}

	if (!Compile(compiler, filename.GetFullPath().c_str())) {
		SetColor(&FailureColor);
		text->AppendText(wxT("Failure.\n\n"));

		SetColor(const_cast<wxColour*>(wxBLACK));

                wxString tmpText(wxString::FromAscii(ShGetInfoLog(compiler)));
		text->AppendText(tmpText);
		text->AppendText(wxT("\n"));
	} else {
		SetColor(&SuccessColor);
		text->AppendText(wxT("Success.\n\n"));
		SetColor(const_cast<wxColour*>(wxBLACK));
	}

	ShDestruct(compiler);
}

void TFrame::OnFileSave(wxCommandEvent& event)
{
	wxString filename = wxFileSelector(wxT("Save log"), wxT(""), wxT("info.log"), wxT(""), wxT("Log file (*.log)|*.log"), wxFD_SAVE);
	if (!filename.empty())
		text->SaveFile(filename);
}

bool TFrame::CompileVertex(const wxString& infile, const wxString& outfile, bool append)
{
	// are there wildcards in the filename?
	if (::wxIsWild(infile) && !append)
	{
		bool success = true;
		bool first = true;
		wxString f = wxFindFirstFile(infile);
		while (!f.IsEmpty())
		{
			success = CompileVertex(f, outfile, !first) && success;
			first = false;
			f = wxFindNextFile();
		}
		return success;
	}

	bool success;
	ShInitialize();
	ShHandle compiler = ShConstructCompiler(EShLangVertex, 0);
	wxFFile log(outfile, append ? wxT("a") : wxT("w"));
	log.Write(wxT("Compiling '") + infile + wxT("'...\n"));

	if (!Compile(compiler, infile)) {
		log.Write(wxT("Compile failed.\n"));
		log.Write(wxString::FromAscii(ShGetInfoLog(compiler)));
		log.Write(wxT("\n"));
		success = false;
	} else {
		log.Write(wxT("Success.\n"));
		log.Write(wxT("\n"));
		success = true;
	}
	log.Close();

	ShDestruct(compiler);
	return success;
}

bool TFrame::CompileFragment(const wxString& infile, const wxString& outfile)
{
	bool success;
	ShInitialize();
	ShHandle compiler = ShConstructCompiler(EShLangFragment, 0);
	wxFFile log(outfile, wxT("w"));

	if (!Compile(compiler, infile)) {
		log.Write(wxT("Compile failed.\n"));
		log.Write(wxString::FromAscii(ShGetInfoLog(compiler)));
		success = false;
	} else {
		log.Write(wxT("Success.\n"));
		success = true;
	}

	ShDestruct(compiler);
	return success;
}

//
// Set up the per compile resources
//
void GenerateResources(TBuiltInResource& resources)
{    
	resources.maxLights = 32;
	resources.maxClipPlanes = 6;
	resources.maxTextureUnits = 32;
	resources.maxTextureCoords = 32;
	resources.maxVertexAttribs = 64;
	resources.maxVertexUniformComponents = 4096;
	resources.maxVaryingFloats = 64;
	resources.maxVertexTextureImageUnits = 32;
	resources.maxCombinedTextureImageUnits = 32;
	resources.maxTextureImageUnits = 32;
	resources.maxFragmentUniformComponents = 4096;
	resources.maxDrawBuffers = 32;
}

bool TFrame::Compile(ShHandle compiler, const wxString& filename)
{
	int file, size;
	char* buffer;
	const char* pFilename = filename.mb_str();

	file = open(pFilename, O_RDONLY);
	if (file == -1)
		return false;

	size = lseek(file, 0, SEEK_END);
	buffer = (char*) malloc(size + 1);
	lseek(file, 0, SEEK_SET);
	size = read(file, buffer, size);
	close(file);
	buffer[size] = 0;

	TBuiltInResource resources;
	GenerateResources(resources);
	bool retval = ShCompile(compiler, &buffer, 1, EShOptNone, &resources, EDebugOpNone) ? true : false;
	free(buffer);
	return retval;
}

// vim: set sw=4 ts=8 et ic ai:
