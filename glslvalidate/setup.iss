[Setup]
AppName=OpenGL Shader Validator
OutputBaseFilename=glslvalidate-1.9
AppVerName=GLSL Validate v1.9
UninstallDisplayName=3Dlabs GLSL Validate v1.9
AppVersion=1.9
VersionInfoVersion=1.9
AppPublisher=3Dlabs
AppPublisherURL=http://developer.3dlabs.com/
DefaultDirName={pf}\3Dlabs\GLSL Validate
DefaultGroupName=3Dlabs\GLSL Validate
UninstallDisplayIcon={app}\glslvalidate.exe
Compression=lzma
SolidCompression=yes

[Files]
Source: "vs7.0\Release\glslvalidate.exe"; DestDir: "{app}"
Source: "vs7.0\Release\glslang.dll"; DestDir: "{app}"

;
; Microsoft KB Article 326922: msvcp70.dll is NOT a system file and should reside in the app folder.
; Ideally we would use a merge module (msm file) but Inno Setup does not support them.
;
Source: "msvcp70.dll"; DestDir: "{app}"

Source: "sample.vert"; DestDir: "{app}"
Source: "sample.frag"; DestDir: "{app}"

[Icons]
Name: "{group}\GLSL Validate"; Filename: "{app}\glslvalidate.exe"; WorkingDir: "{app}"
Name: "{group}\Program Folder"; Filename: "{app}"
Name: "{group}\Uninstall"; Filename: "{uninstallexe}"

[Run]
Filename: "{app}\glslvalidate.exe"; WorkingDir: "{app}"; Description: "Launch application"; Flags: postinstall nowait skipifsilent unchecked

