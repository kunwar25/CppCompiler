#include <iostream>
#include "src/Compiler.h"

void showMenu() {
    std::cout << "\n==== Simple C++ CLI Compiler ====\n";
    std::cout << "Commands:\n";
    std::cout << "1. write     - Write C++ code\n";
    std::cout << "2. run       - Compile and execute\n";
    std::cout << "3. clear     - Clear user code\n";
    std::cout << "4. exit      - Exit program\n";
    std::cout << "=================================\n";
}

int main() {
    Compiler compiler;
    std::string command;

    while (true) {
        showMenu();
        std::cout << "\nEnter command: ";
        std::cin >> command;
        std::cin.ignore();

        if (command == "write") {
            compiler.writeCode();
        } else if (command == "run") {
            compiler.compileAndRun();
        } else if (command == "clear") {
            compiler.clearCode();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    return 0;
}
