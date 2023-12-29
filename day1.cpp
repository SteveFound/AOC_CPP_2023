#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <chrono>
#include <map>

#include "util/file_loader.hpp"

using namespace std;
using namespace std::chrono;

#define COUNT 2000

/**
 * Find the values of the first and last elements of a text digit representation in a string and
 * return it as a 2 digit integer.
 * @param line file contents
 * @param digits map of text representations of digits and their numeric values.
 * @return integer created by the first digit * 10 + the last digit. 0 if there are no digits.
 */
int firstAndLast(const string &line, const map<string, int> &digits) {
    int first = 0, last = 0;
    int firstIdx = 20000;
    int lastIdx = -1;
    size_t idx;


    for (const auto& [key, value] : digits) {
        if( ((idx = line.find(key)) != string::npos ) && ((int)idx < firstIdx) )  {
            firstIdx = (int)idx;
            first = value;
        }
        if( ((idx = line.rfind(key)) != string::npos ) && ((int)idx > lastIdx) ) {
            lastIdx = (int)idx;
            last = value;
        }
    }
    return first * 10 + last;
}

long sum(const vector<string> &fileContent, const map<string, int> &digits){
    long sum = 0;
    for( const string line : fileContent ){
        sum += firstAndLast(line, digits);
    }
    return sum;
}

int main(int argc, char* argv[])
{
    if( argc != 2 ) {
        cout << "Usage day1 <input_file>\n";
        return -1;
    }

    FileLoader loader;
    vector<string> fileContent = loader.readLines(argv[1]);

    map<string, int> digits;
    digits["0"] = 0; digits["1"] = 1;
    digits["2"] = 2; digits["3"] = 3;
    digits["4"] = 4; digits["5"] = 5;
    digits["6"] = 6; digits["7"] = 7;
    digits["8"] = 8; digits["9"] = 9;

    map<string, int> wordsAndDigits;
    wordsAndDigits["0"] = 0; wordsAndDigits["1"] = 1;
    wordsAndDigits["2"] = 2; wordsAndDigits["3"] = 3;
    wordsAndDigits["4"] = 4; wordsAndDigits["5"] = 5;
    wordsAndDigits["6"] = 6; wordsAndDigits["7"] = 7;
    wordsAndDigits["8"] = 8; wordsAndDigits["9"] = 9;
    wordsAndDigits["zero"] = 0; wordsAndDigits["one"] = 1;
    wordsAndDigits["two"] = 2; wordsAndDigits["three"] = 3;
    wordsAndDigits["four"] = 4; wordsAndDigits["five"] = 5;
    wordsAndDigits["six"] = 6; wordsAndDigits["seven"] = 7;
    wordsAndDigits["eight"] = 8; wordsAndDigits["nine"] = 9;

    long sum1;
    auto start = high_resolution_clock::now();
    for( int i = 0; i < COUNT; i++ ){
        sum1 = sum(fileContent, digits);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Part 1: " << sum1 << " in " << duration.count() / COUNT << " nanoseconds\n";

    long sum2;
    start = high_resolution_clock::now();
    for( int i = 0; i < COUNT; i++ ){
        sum2 = sum(fileContent, wordsAndDigits);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);    
    cout << "Part 2: " << sum2 << " in " << duration.count() / COUNT << " nanoseconds\n";
    return 0;
}