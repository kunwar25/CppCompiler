// src/Compiler.h
#ifndef COMPILER_H
#define COMPILER_H

#include <string>

class Compiler {
private:
    std::string userCodeFile;

public:
    Compiler();

    void writeCode();
    void compileAndRun();
    void clearCode();
};

#endif
