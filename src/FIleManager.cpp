#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void FileManager::listFiles(const std::string& directory) {
    std::cout << "Available files:\n";
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.path().extension() == ".cpp") {
            std::cout << " - " << entry.path().filename().string() << '\n';
        }
    }
}

void FileManager::createNewFile() {
    std::string filename;
    std::cout << "Enter new filename (with .cpp extension): ";
    std::getline(std::cin, filename);

    std::ofstream file("user_code/" + filename);
    file << "#include <iostream>\nusing namespace std;\n\nint main() {\n    // Your code here\n    return 0;\n}\n";
    file.close();

    std::cout << "Template created in user_code/" << filename << std::endl;
    logHistory(filename);
}

void FileManager::openFile() {
    std::string filename;
    std::cout << "Enter filename to open: ";
    std::getline(std::cin, filename);

    std::ifstream file("user_code/" + filename);
    if (!file.is_open()) {
        std::cout << "File not found.\n";
        return;
    }

    std::cout << "\nContents of " << filename << ":\n\n";
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void FileManager::logHistory(const std::string& filename) {
    std::ofstream history("logs/history.log", std::ios::app);
    history << filename << " created or modified.\n";
    history.close();
}

void FileManager::showHistory() {
    std::ifstream history("logs/history.log");
    if (!history.is_open()) {
        std::cout << "No history available.\n";
        return;
    }
    std::string line;
    while (std::getline(history, line)) {
        std::cout << line << std::endl;
    }
    history.close();
}
