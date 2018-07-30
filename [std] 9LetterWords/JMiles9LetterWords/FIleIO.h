#pragma once
#include "stdafx.h"
#include "NineLetterWords.h"
#include <fstream>
#include <regex>
#include <Windows.h>
class FileIO
{
public:
	static bool FileExists(std::string fileName);
	static std::vector<std::string> FileLoad(std::string fileName);
	static bool FileSave(std::string fileName, std::set<std::string>& eachLineString, NineLetterWords & nineLetterWords);
	static void ToUpper(std::string & stringToUpper);
	static void ToLower(std::string & stringToUpper);
	static bool GetUserTrueFalse(std::string message);
	static std::set<std::string> StringVectorToSet(std::vector<std::string>& vec);
	static std::vector<std::string> StringSetToVector(std::set<std::string>& set);
};

