#pragma once
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <fstream>
#include <string>

class FileProcessor {

private:
	std::string inputFileName;
	std::string outputFileName;

public:
	void analyzePasswords();
	void generateWeakPasswords(int count);
};



#endif // !FILEPROCESSOR_H
