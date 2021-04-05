#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "String/String.h"

using vs = std::vector<std::string>;

bool zip(vs files){
    bool flag(false);
    system("mkdir tmp");
    std::string com("@echo off && copy /Y \"{f}\" tmp");
    for(std::string file: files){
        std::ifstream tst(file);
        if(!tst.is_open()){return 0;}
        system(spp::replace(com,"{f}",file).c_str());
        tst.close();
    }

    system("zip.vbs");

    system("del /F /Q tmp");
    system("rmdir tmp");

    return 1;
    
}