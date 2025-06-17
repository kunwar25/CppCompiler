#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {
public:
    void listFiles(const std::string& directory);
    void createNewFile();
    void openFile();
    void showHistory();
    void logHistory(const std::string& filename);
};

#endif
