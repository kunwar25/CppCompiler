// src/Compiler.cpp
#include "Compiler.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

Compiler::Compiler() {
    userCodeFile = "user_code/main.cpp";
}

void Compiler::writeCode() {
    std::ofstream outFile(userCodeFile);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    std::cout << "Enter your C++ code (type 'END' on a new line to finish):\n";
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == "END") break;
        outFile << line << std::endl;
    }
    outFile.close();
    std::cout << "Code saved successfully.\n";
}

void Compiler::compileAndRun() {
    std::string compileCommand = "g++ " + userCodeFile + " -o user_code/output.exe 2> logs/compile.log";
    int compileResult = system(compileCommand.c_str());

    if (compileResult != 0) {
        std::cout << "Compilation failed. See logs/compile.log for details.\n";
        return;
    }

    std::cout << "Compilation successful. Running program...\n\n";
    std::string runCommand = "user_code\\output.exe";
    system(runCommand.c_str());
}

void Compiler::clearCode() {
    std::ofstream outFile(userCodeFile, std::ios::trunc);
    outFile.close();
    std::cout << "Code cleared successfully.\n";
}
