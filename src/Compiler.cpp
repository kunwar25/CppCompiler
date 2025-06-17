#include "Compiler.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

Compiler::Compiler() : filename("user_code/main.cpp"), compilerFlags("") {}

void Compiler::writeCode() { 
    std::ofstream file(filename);
    std::string line;

    std::cout << "Enter your C++ code (type 'END' to finish):\n";
    while (true) {
        std::getline(std::cin, line);
        if (line == "END") break;
        file << line << "\n";
    }
    file.close();
    std::cout << "Code saved successfully.\n";
}

void Compiler::compileAndRun() {
    std::string compileCmd = "g++ " + compilerFlags + " " + filename + " -o user_code/output.exe 2> logs/compile.log";
    std::cout << "Compiling...\n";

    if (system(compileCmd.c_str()) == 0) {
        std::cout << "\033[32m[✔] Compilation successful\033[0m\nRunning program...\n";

        auto start = std::chrono::high_resolution_clock::now();
        system("user_code\\output.exe");
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Execution Time: " << elapsed.count() << " seconds\n";
    } else {
        std::cout << "\033[31m[✘] Compilation failed.\033[0m\nCheck logs/compile.log\n";
    }
}

void Compiler::clearFile() {
    std::ofstream file(filename, std::ofstream::trunc);
    file.close();
    std::cout << "File cleared.\n";
}

void Compiler::setCompilerFlags() {
    std::cout << "Enter compiler flags (e.g. -g, -O2): ";
    std::getline(std::cin, compilerFlags);
}
