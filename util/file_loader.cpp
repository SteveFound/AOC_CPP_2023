#include <fstream>

#include "file_loader.hpp"

using namespace std;

vector<string> FileLoader::readLines(string filename) {
    // Opening the file
    ifstream file(filename);
 
    vector<string> lines;
    string str;
 
    // Read the next line from File until it reaches the
    // end.
    while (file >> str) {
        // Now keep reading next line
        // and push it in vector function until end of file
        lines.push_back(str);
    }
    return lines;
}