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
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
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
#include <wx/ffile.h>
#include <fcntl.h>
#include <io.h>

#define APP_VERSION "1.9"

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
	text = new wxTextCtrl(this, Id::WidgetText, "", wxDefaultPosition, wxDefaultSize, wxTE_RICH | wxTE_RICH2 | wxTE_READONLY | wxTE_MULTILINE);
	vertical->Add(text, 1, wxALIGN_CENTRE_VERTICAL | wxEXPAND | wxALL);
	text->SetBackgroundColour(*wxWHITE);

	wxTextAttr bold(*wxBLACK , *wxWHITE, wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD));
	text->SetDefaultStyle(bold);

	wxMenu* menu;
	wxMenuBar* menuBar = new wxMenuBar;

	menu = new wxMenu;
	menu->Append(Id::FileParseVertex, "Parse vertex shader(s)...");
	menu->Append(Id::FileParseFragment, "Parse fragment shader(s)...");
	menu->Append(Id::FileReparseCurrent, "Re-parse current shader(s)\tF5");
	menu->Append(Id::FileClear, "Clear log");
	menu->Append(Id::FileSave, "Save log...");
	menu->AppendSeparator();
	menu->Append(Id::FileExit, "Exit\tQ");
	menuBar->Append(menu, "File");

	menu = new wxMenu;
	menu->Append(Id::HelpCommandLine, "Command line options...");
	menu->Append(Id::HelpAbout, "About...");
	menuBar->Append(menu, "Help");

	SetMenuBar(menuBar);
	SetSizer(vertical);
	SetIcon(wxIcon("3DLABS_ICON", wxBITMAP_TYPE_ICO_RESOURCE));

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
		"GLSL Syntax Validator v" APP_VERSION "\n"
		"Copyright © 2005 3Dlabs.  All rights reserved.\n\n"
		"glslvalidate: a tool that checks shaders for valid syntax using the 3Dlabs open source GLSL parser.\n\n"
		"GLSL parser source code is available at http://developer.3dlabs.com/downloads\n\n"
		"For questions and feedback, go to http://www.3dlabs.com/contact\n\n"
		"Thanks to Jordan Russell for InnoSetup.",
		"about glslvalidate", wxOK | wxICON_INFORMATION, this);
}

void TFrame::OnFileExit(wxCommandEvent& event)
{
	Close();
	event.Skip();
}

void TFrame::OnFileParseVertex(wxCommandEvent& event)
{
	wxFileDialog dialog(this, "Open vertex shader", "", "", "All (*.*)|*.*|Vertex shader (*.vert;*.v)|*.vert;*.v", wxFD_OPEN | wxFD_MULTIPLE);
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
	wxFileDialog dialog(this, "Open fragment shader", "", "", "All (*.*)|*.*|Fragment shader (*.frag;*.f)|*.frag;*.f", wxFD_OPEN | wxFD_MULTIPLE);
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
		Printf(L"Parsing vertex shader ");
	else
		Printf(L"Parsing fragment shader ");

	Printf(L"'%s'....\n", filename.GetFullName());

	ShInitialize();
	ShHandle compiler = ShConstructCompiler(language, 0);

	if (!compiler) {
		wxGetApp().Errorf("Unable to construct compiler.\n");
		return;
	}

	if (!Compile(compiler, filename.GetFullPath())) {
		SetColor(&FailureColor);
		text->AppendText("Failure.\n\n");

		SetColor(const_cast<wxColour*>(wxBLACK));
		text->AppendText(ShGetInfoLog(compiler));
		text->AppendText("\n");
	} else {
		SetColor(&SuccessColor);
		text->AppendText("Success.\n\n");
		SetColor(const_cast<wxColour*>(wxBLACK));
	}

	ShDestruct(compiler);
}

void TFrame::OnFileSave(wxCommandEvent& event)
{
	wxString filename = wxFileSelector("Save log", "", "info.log", "", "Log file (*.log)|*.log", wxFD_SAVE);
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
	wxFFile log(outfile, append ? "a" : "w");
	log.Write("Compiling '" + infile + "'...\n");

	if (!Compile(compiler, infile)) {
		log.Write("Compile failed.\n");
		log.Write(ShGetInfoLog(compiler));
		log.Write("\n");
		success = false;
	} else {
		log.Write("Success.\n");
		log.Write("\n");
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
	wxFFile log(outfile, "w");

	if (!Compile(compiler, infile)) {
		log.Write("Compile failed.\n");
		log.Write(ShGetInfoLog(compiler));
		success = false;
	} else {
		log.Write("Success.\n");
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
	const char* pFilename = filename.c_str();

	file = _open(pFilename, _O_RDONLY);
	if (file == -1)
		return false;

	size = _lseek(file, 0, SEEK_END);
	buffer = (char*) malloc(size + 1);
	_lseek(file, 0, SEEK_SET);
	size = _read(file, buffer, size);
	_close(file);
	buffer[size] = 0;

	TBuiltInResource resources;
	GenerateResources(resources);
	bool retval = ShCompile(compiler, &buffer, 1, EShOptNone, &resources, EDebugOpNone) ? true : false;
	free(buffer);
	return retval;
}

// vim: set sw=4 ts=8 et ic ai:
