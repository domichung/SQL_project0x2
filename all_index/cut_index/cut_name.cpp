#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <direct.h> 

using namespace std;

void splitFile(const string& inputFileName, const string& outputDir, int chunkSize) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening input file: " << inputFileName << endl;
        return;
    }

    _mkdir(outputDir.c_str());

    vector<string> lines;
    string line;
    int currentSize = 0;
    int chunkNumber = 1;

    while (getline(inputFile, line)) {
        lines.push_back(line);
        currentSize += line.size() + 1; 

        if (currentSize >= chunkSize) {
            stringstream outputFileName;
            outputFileName << outputDir << "/" << setfill('0') << setw(4) << chunkNumber << ".txt";
            ofstream outputFile(outputFileName.str());

            for (const auto& l : lines) {
                outputFile << l << '\n';
            }

            outputFile.close();

            lines.clear();
            currentSize = 0;
            ++chunkNumber;
        }
    }

    if (!lines.empty()) {
        stringstream outputFileName;
        outputFileName << outputDir << "/" << setfill('0') << setw(4) << chunkNumber << ".txt";
        ofstream outputFile(outputFileName.str());

        for (const auto& l : lines) {
            outputFile << l << '\n'; 
        }

        outputFile.close();
    }

    inputFile.close();

    cout << "File " << inputFileName << " split into " << chunkNumber << " chunks." << endl;
}

int main() {
    string inputFileName = "../long/classname.txt";  
    string outputDir = "../index_classname"; 
    int chunkSize = 1024; 

    splitFile(inputFileName, outputDir, chunkSize);

    return 0;
}
