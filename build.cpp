#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "String/String.h"
#include "zipper.h"

using vs = std::vector<std::string>;

void error(std::string err){
    std::string _;
    std::cout<<err; std::getline(std::cin,_);exit(-1);
}

std::string c2s(char* c){
    const char* t = c;
    std::string _t = t;
    return _t;
}

int main(int argc, char** argv){
    if(argc < 2){error("error too few arguments, you need to supply a config file");}
    std::string configFile(c2s(argv[1]));

    std::cout << "parsing config file...\n";

    /* parse config file */
    std::ifstream cfg(configFile);
    if(!cfg.is_open()){error("error cant find config file");}
    std::ostringstream ss;
    ss << cfg.rdbuf();
    std::string contents(ss.str());
    std::string op("\n");
    std::string op2("=");
    vs lines = spp::split(contents,op);

    vs deps;
    vs coms;

    for(std::string q: lines){
        vs sp = spp::split(q,"=");
        if(sp[0] == "dep"){deps.push_back(sp[1]);}
        if(sp[0] == "com"){coms.push_back(sp[1]);}

    }
    std::cout << "zipping file...\n";
    if(zip(deps)){
        std::cout << "reading zip file...\n";
        std::ifstream zipFile("tmp.zip", std::ios::binary);

        long size;
        zipFile.seekg(0, std::ios::end);
        size=zipFile.tellg();
        zipFile.seekg(0, std::ios::beg);

        char* buf = new char[size];
        zipFile.read(buf,size);

        zipFile.close();

        std::cout << "makeing cpp file...\n";

        std::string sv = "std::vector<char> buf = {<chrs>};";
        std::string chrs = "";
        for(int i = 0; i<size;i++){
            int in = static_cast<int>(buf[i]);
            chrs += std::to_string(in) + ',';
        }
        chrs.pop_back();
        sv = spp::replace(sv,"<chrs>",chrs);

        std::string comsStr("");
        for(std::string com: coms){
            comsStr += "system(\""+com+"\""+");";
        }
        
        std::ofstream out("out.cpp");

        std::cout << "reading template.cpp...\n";
        std::ostringstream ss = std::ostringstream{};
        std::ifstream tmp("template.cpp");
        ss << tmp.rdbuf();

        std::string tmplate = ss.str();
        tmplate = spp::replace(tmplate,"<vec>",sv);
        tmplate = spp::replace(tmplate,"<coms>",comsStr);

        out << tmplate;

        out.close();

        std::cout << "compiling...\n";
        system("@echo off && g++ out.cpp -o out");

        std::cout << "deleting zip file...\n";
        system("@echo off && del /F /Q tmp.zip");

        std::cout << "deleting cpp file...\n";
        system("@echo off && del /F /Q out.cpp"); 

        std::cout << "done!";
        

    }else{
        error("error zipping files, check to make sure all files are existent");
    }

}