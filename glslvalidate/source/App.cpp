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
* App.cpp                                                               *
* Author:  Philip Rideout                                               *
* Maintained By:  Joshua Doss                                           *
* Last Changed Date: 01/04/2006                                         *
************************************************************************/

#include "App.h"
#include "Frame.h"
#include <wx/cmdline.h>

const wxCmdLineEntryDesc TApp::CommandLineDescription[] =
{
    {wxCMD_LINE_OPTION, wxT("v"), wxT("vertex"), wxT("bypass the GUI, parse the specified vertex shader (wildcards are allowed), dump results to vertex.log")},
    {wxCMD_LINE_OPTION, wxT("f"), wxT("fragment"), wxT("bypass the GUI, parse the specified fragment shader (wildcards are allowed), dump results to fragment.log")},
    {wxCMD_LINE_NONE }
};

bool TApp::OnInit()
{
    m_retval = 0;
    wxCmdLineParser parser(argc, argv);
    parser.SetDesc(CommandLineDescription);
    m_retval = parser.Parse();
    parser.Found((wxChar*)"v", &m_vertfile);
    parser.Found((wxChar*)"f", &m_fragfile);
    new TFrame((wxChar*)"GLSL Syntax Validator", wxDefaultPosition, wxSize(500,500));
    if (m_vertfile.empty() && m_fragfile.empty())
        m_frame->Show(true);
    else {
        SetTopWindow(m_frame);
        if (!m_vertfile.empty())
            m_retval = m_frame->CompileVertex(m_vertfile, (wxChar*)"vertex.log") ? 0 : 1;
        if (!m_fragfile.empty())
            m_retval = m_frame->CompileFragment(m_fragfile, (wxChar*)"fragment.log") ? 0 : 1;
        m_frame->Close();
    }
    SetTopWindow(m_frame);
    return true;
}

void TApp::Errorf(const char* format, ...)
{
    wxString message;

    va_list marker;
    va_start(marker, format);
    message.PrintfV((const wxChar*)format, marker);
    m_frame->SetColor(const_cast<wxColour*>(wxRED));
    m_frame->Printf(L"%s\n", message.c_str());
    const char* tmp = message.mb_str();
    printf("%s\n", tmp);
    m_frame->SetColor(const_cast<wxColour*>(wxBLACK));
}

IMPLEMENT_APP(TApp)
