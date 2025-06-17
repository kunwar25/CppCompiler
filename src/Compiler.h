#ifndef COMPILER_H
#define COMPILER_H

#include <string>

class Compiler {
private:
    std::string filename;
    std::string compilerFlags;

public:
    Compiler();
    void writeCode();
    void compileAndRun();
    void clearFile();
    void setCompilerFlags();
};

#endif
