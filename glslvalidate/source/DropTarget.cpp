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
* DropTarget.cpp                                                        *
* Author:  Matthew 'MWDD' Williams                                      *
* Last Changed Date: 01/04/2006                                         *
************************************************************************/

#include "DropTarget.h"
#include "Frame.h"

TDropTarget::TDropTarget(TFrame* theFrame)
    : wxFileDropTarget()
    , frame(theFrame)
{
}

TDropTarget::~TDropTarget()
{
}

bool TDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString &filenames)
{
    for (unsigned int i = 0; i < filenames.GetCount(); i++)
    {
      //
      // Try to determine if the file is a vertex or fragment shader using common filename extensions
      //
      wxString filename = filenames[i];
      size_t extPos = filename.rfind('.');
      wxString ext = filename.substr(extPos);

      //
      // Common vertex shader extensions
      //
      if (ext == wxT(".vert") ||
          ext == wxT(".vsh")  ||
		  ext == wxT(".vs"))
      {
        frame->Compile(filename, EShLangVertex);
      }
      //
      // Common fragment shader extensions
      //
      else if (ext == wxT(".frag") ||
               ext == wxT(".fsh")  ||
			   ext == wxT(".psh")  ||
			   ext == wxT(".ps")   ||
			   ext == wxT(".fs"))
      {
        frame->Compile(filename, EShLangFragment);
      }
	  else
	  {
		wxString unsupportedExtensionString(wxString(wxT(" does not have a supported file extension for use with drag and drop validation.\n\nPlease append the appropriate extension to the filename and try again or use the File menu to select your shader(s).\n\nThe supported extensions include .vsh, .vert, .vs, .fsh, .frag, .psh, .ps, .fs")));
		unsupportedExtensionString = wxT("The file ") + filename + unsupportedExtensionString;
		wxMessageDialog unsupportedExtension(frame, unsupportedExtensionString, wxT("Unsupported Filename Extension(s)"), wxOK | wxICON_EXCLAMATION, wxDefaultPosition);
	    unsupportedExtension.ShowModal();
	  }
    }
    return true;
}
