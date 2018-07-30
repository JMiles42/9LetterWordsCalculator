#pragma once
#include "stdafx.h"
#include "NineLetterWords.h"
#include <fstream>
#include <regex>
#include <Windows.h>
class FileIO
{
public:
	//Check if the file exists
	static bool FileExists(std::string fileName);
	//Load A vector from a file
	static std::vector<std::string> FileLoad(std::string fileName);
	//Save A String set/vector to disk
	static bool FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords & nineLetterWords);
	static bool FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords & nineLetterWords, std::map<char, int> & foundLetterInstances);
	//static bool FileSave(std::string fileName, std::vector<std::string>& eachLineString, NineLetterWords & nineLetterWords);
	
//////////Less File in out stuff just haven't cleaned it out yet, and don't want to cause potential issues so there here in this project

	static void StringToUpper(std::string & stringToUpper);
	static void StringToLower(std::string & stringToUpper);
	//Get the users Yy1/Nn0 and returns a bool
	//static bool GetUserTrueFalse(std::string message);
	static bool GetUserTrueFalse();
	//String vector set
	static std::set<std::string> StringVectorToSet(std::vector<std::string>& vec);
	//String set to vector
	static std::vector<std::string> StringSetToVector(std::set<std::string>& set);
};

