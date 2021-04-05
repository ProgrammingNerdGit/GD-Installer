#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "String/String.h"

#ifdef __unix__
    #define OS_WIN 0
#elif
    #define OS_WIN 1
#endif
using vs = std::vector<std::string>;

bool zip(vs files){
    bool flag(false);
    system("mkdir tmp");
   

    if(OS_WIN){
        std::string com("@echo off && copy /Y \"{f}\" tmp");
        for(std::string file: files){
            std::ifstream tst(file);
            if(!tst.is_open()){return 0;}
            system(spp::replace(com,"{f}",file).c_str());
            tst.close();
        }
        system("zip.vbs");
        system("del /F /Q tmp");
    }else{
        system("sudo apt-get install zip");
        std::string com("cp \"{f}\" tmp");
        for(std::string file: files){
            std::ifstream tst(file);
            if(!tst.is_open()){return 0;}
            system(spp::replace(com,"{f}",file).c_str());
            std::cout << spp::replace(com,"{f}",file) << "\n";
            tst.close();
        }
        system("zip tmp.zip tmp/*");
        system("rm -f tmp/*");
    }
    
    system("rmdir tmp");

    

    return 1;
    
}