#include <vector>
#include <iostream>
#include <fstream>
int main(){  
    <vec>
    std::ofstream out("tmp.zip",std::ios::binary);
    char* cbuf = new char[buf.size()];
    for(int i = 0; i<buf.size();i++){
        cbuf[i] = buf[i];
    }
    out.write(cbuf, buf.size());
    out.close();

    std::ofstream unzip("unzip.vbs");
    std::string contents = "Set fso = CreateObject(\"Scripting.FileSystemObject\")\nDim outputDirectory\noutputDirectory = fso.GetAbsolutePathName(\"\")\nDim zipFile\nzipFile = fso.GetAbsolutePathName(\"tmp.zip\")\nWScript.Echo outputDirectory\nIf NOT fso.FolderExists(outputDirectory) Then\nfso.CreateFolder(outputDirectory)\nEnd If\nset objShell = CreateObject(\"Shell.Application\")\nset FilesInZip=objShell.NameSpace(zipFile).items\nobjShell.NameSpace(outputDirectory).CopyHere(FilesInZip)\nSet fso = Nothing\nSet objShell = Nothing";
    unzip << contents;
    unzip.close();

    system("cscript unzip.vbs");
    system("@echo off && del /F /Q tmp.zip");
    system("@echo off && del /F /Q unzip.vbs");

    <coms>


}