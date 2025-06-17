#include "src/Compiler.h"
#include "src/FileManager.h"
#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n==== Simple C++ CLI Compiler ====\n"
              << "Commands:\n"
              << "1. write     - Write C++ code\n"
              << "2. run       - Compile and execute\n"
              << "3. clear     - Clear user code\n"
              << "4. list      - List available files\n"
              << "5. new       - Create new file\n"
              << "6. open      - Open existing file\n"
              << "7. history   - View compile history\n"
              << "8. config    - Set compiler options\n"
              << "9. exit      - Exit program\n"
              << "=================================\n";
}

int main() {
    Compiler compiler;
    FileManager fileManager;
    std::string command;

    while (true) {
        showMenu();
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);

        if (command == "write") compiler.writeCode();
        else if (command == "run") compiler.compileAndRun();
        else if (command == "clear") compiler.clearFile();
        else if (command == "list") fileManager.listFiles("user_code");
        else if (command == "new") fileManager.createNewFile();
        else if (command == "open") fileManager.openFile();
        else if (command == "history") fileManager.showHistory();
        else if (command == "config") compiler.setCompilerFlags();
        else if (command == "exit") break;
        else std::cout << "Invalid command.\n";
    }
}
