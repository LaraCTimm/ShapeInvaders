#include "FileReader.h"

FileReader::FileReader(const string& file_name): _filename{file_name}
{}

int FileReader::getHighScore()
{
	file.open(_filename, ios::in);
	if (!file) throw std::logic_error("FileReader::FileReader - File Not Found");
	file >> _high_score;
	file.close();
	file.clear();
	return _high_score;
}

void FileReader::setHighScore(int score)
{
	file.open(_filename, ios::out);
	if (!file) throw std::logic_error("FileReader::FileReader - File Not Found");
	file << score;
	file.close();
	file.clear();
}

void FileReader::closeFile()
{
	file.close();
}
