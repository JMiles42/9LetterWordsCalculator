#include "FIleIO.h"

///Checks if file exists
bool FileIO::FileExists(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	bool fileExists = file.good();
	
	file.close();
	return fileExists;
}
///Load File return 
std::vector<std::string> FileIO::FileLoad(std::string fileName)
{
	std::vector<std::string> fileData;
	//Bail out if no file
	if (!FileExists(fileName))
		return fileData;

	std::ifstream file;
	file.open(fileName);
	//Each Line read into a vector of strings one entry per line
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		fileData.push_back(line);
	}
	file.close();
	return fileData;
}
///Save Vecter of strings one entry per line With heading
bool FileIO::FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords& nineLetterWords)
{
	//Creates output Dir
	CreateDirectory("OutputDir",NULL);

	//Check if user wants to override file
	if (FileExists("OutputDir/" + fileName))
		if (!GetUserTrueFalse("Please enter (y) or (n) if you would like to override the file.\n"))
			return false;

	std::ofstream file;
	file.open("OutputDir/" + fileName);
	file << nineLetterWords.DisplayHeading();
	//Write each line to file
	for (auto& line : eachLineString)
		file << line << "\n";
	file.close();
	return true;
}
///Convert all characters in the string to upper case
void FileIO::ToUpper(std::string& stringToUpper)
{
	for (auto& letter : stringToUpper)
		letter = toupper(letter);
}
///Convert all characters in the string to lower case
void FileIO::ToLower(std::string& stringToUpper)
{
	for (auto& letter : stringToUpper)
		letter = tolower(letter);
}
bool FileIO::GetUserTrueFalse(std::string message)
{
	while (true)
	{
		std::cout << message;
		std::cin.clear();
		char ignoreYN;
		std::cin >> ignoreYN;
		if (ignoreYN == 'y' || ignoreYN == 'Y')
			return true;
		else if (ignoreYN == 'n' || ignoreYN == 'N')
			return false;
		else
			std::cout << "Error User Input Does Not Match Accepted Values\n";
	}
	return false;
}

std::set<std::string> FileIO::StringVectorToSet(std::vector<std::string>& vec)
{
		std::set<std::string> set;
		for (auto& v : vec)
			set.emplace(v);
	return set;
}

std::vector<std::string> FileIO::StringSetToVector(std::set<std::string>& set)
{
		std::vector<std::string> vec;
		for (auto& s : set)
			set.emplace(s);
	return vec;
}
