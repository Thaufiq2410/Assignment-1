#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string sourceFile = "original.csv";
    std::string destinationFile = "copy.csv";

    std::ofstream clearFile(destinationFile, std::ios::trunc); 
    if (!clearFile) {
        std::cerr << "Error: Unable to clear the destination file!" << std::endl;
        return 1;
    }
    clearFile.close();

    std::ifstream inputFile(sourceFile);
    if (!inputFile) {
        std::cerr << "Error: Could not open source file!" << std::endl;
        return 1;
    }

    
    std::ofstream outputFile(destinationFile);
    if (!outputFile) {
        std::cerr << "Error: Could not open destination file!" << std::endl;
        return 1;
    }

    std::string lines;
    while (std::getline(inputFile, lines)) {
        outputFile << lines << '\n';
    }

    
    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully!" << std::endl;
    return 0;
}
