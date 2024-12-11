#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Password.h"

class FileProcessor {
private:
    std::string inputFileName;
    std::string outputFileName;

public:
    // Load passwords from a file
    std::vector<std::string> readPasswords(const std::string& fileName);

    // Write passwords to a file
    void writePasswords(const std::vector<std::string>& passwords, const std::string& fileName);

    // Analyze passwords for their complexity and write a report
    void analyzePasswords();

    // Generate a list of weak passwords and save to a file
    void generateWeakPasswords(int count);
    
    // File selection dialog
    std::vector<std::string> selectFile(); 
};

#endif // !FILEPROCESSOR_H
