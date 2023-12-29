#ifndef _FILE_LOADER_H
#define _FILE_LOADER_H

#include <vector>
#include <string>

class FileLoader {
    public:
    std::vector<std::string> readLines(std::string filename);
};

#endif