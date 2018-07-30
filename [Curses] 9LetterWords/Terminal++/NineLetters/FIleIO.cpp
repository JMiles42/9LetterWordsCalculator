#include "FIleIO.h"
#include <direct.h>
#include "../NeededUniversalHeader.h"
#include "../SubWindowWithBorder.h"
//Checks if file exists
bool FileIO::FileExists(std::string fileName)
{
	std::ifstream file;
	//Open File
	file.open(fileName);

	//Store local bool so file can be closed
	bool fileExists = file.good();
	//Close file
	file.close();
	return fileExists;
}
//Load File return 
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
bool FileIO::FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords& nineLetterWords)
{
	//Creates output Dir
	CreateDirectory("WordFinder", NULL);
	//Check if user wants to override file
	if (FileExists("WordFinder\\" + fileName + ".txt"))
	{
		//Display message box to user and get response
		int msgBox = MessageBox(nullptr, TEXT(("Warning File Exists.\nWould you like to override file?")), TEXT("Error: File Exists"), MB_YESNO);

		//Check if Yes
		if (msgBox == IDYES)
			LogMessage("File will be overridden.");
		//Check if No
		else if (msgBox == IDNO)
		{
			LogMessage("File won't be overridden. \n Not Saving File.");
			return false;
		}
		ForceRender();
	}

	std::ofstream file;
	file.open("WordFinder\\" + fileName + ".txt");
	//Write heading to file
	file << nineLetterWords.DisplayHeading();
	//Write each line to file
	for (auto& line : eachLineString)
		file << line << "\n";
	file.close();
	return true;
}
bool FileIO::FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords& nineLetterWords, std::map <char, int> & foundLetterInstances)
{
	//Creates output Dir
	CreateDirectory("PuzzleMaker", NULL);

	//Check if user wants to override file
	if (FileExists("PuzzleMaker\\" + fileName + ".txt"))
	{
		//Display message box to user and get response
		int msgBox = MessageBox(nullptr, TEXT(("Warning File Exists.\nWould you like to override file?")), TEXT("Error: File Exists"), MB_YESNO);

		//Check if Yes
		if (msgBox == IDYES)
			LogMessage("File will be overridden.");
		//Check if No
		else if (msgBox == IDNO)
		{
			LogMessage("File won't be overridden. \n Not Saving File.");
			return false;
		}
		ForceRender();
	}

	std::ofstream file;
	file.open("PuzzleMaker\\" + fileName + ".txt");
	//Write heading to file
	file << nineLetterWords.DisplayHeading(foundLetterInstances);
	//Write each line to file
	for (auto& line : eachLineString)
		file << line << "\n";
	file.close();
	return true;
}
void FileIO::StringToUpper(std::string& stringToUpper)
{
	for (auto& letter : stringToUpper)
		letter = toupper(letter);
}
void FileIO::StringToLower(std::string& stringToUpper)
{
	for (auto& letter : stringToUpper)
		letter = tolower(letter);
}
bool FileIO::GetUserTrueFalse()
{
	//Untill user enters currect data loop
	while (true)
	{
		ForceRender();
		//Clear
		char ignoreYN;
		//Get input
		ignoreYN = getch();;
		if (ignoreYN == 'y' | ignoreYN == 'Y' | ignoreYN == '1' )
			return true;
		else if (ignoreYN == 'n' | ignoreYN == 'N' | ignoreYN == '0' )
			return false;
		else	//Log error message
			LogMessage("Error User Input Does Not Match Accepted Values\n", SubWindowWithBorder::Colour::Red);
		ForceRender();
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