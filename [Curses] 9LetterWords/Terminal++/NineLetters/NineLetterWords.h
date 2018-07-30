#pragma once
#include "stdafx.h"
class NineLetterWords
{
public:
	//An enum that represenmts the position of the letters
	enum class LetterPosition
	{
		TopLeft, TopMiddle, TopRight,
		MiddleLeft, MiddleMiddle, MiddleRight,
		LowerLeft, LowerMiddle, LowerRight
	};
	//String Stream for converting the chars to a string
	std::stringstream stream;
	//A referance to the string so that its quicker to get
	std::string charString;
	//The base numbers of the allowed letters
	//if the input is "aaabbcccc"
	// a = 3
	// b = 2
	// c = 4
	// This will then be used to determin if the current word is less then or equal to the entered letters
	std::map<char, int> letters;
	//A referance to the filedata in the EP
	std::set<std::string>* fileData;
	//A referance the the found words in the EP
	std::set<std::string>* foundWords;

	// The min word length of the checked words
	int minWordLength = 4;
	// The max word length of the checked words
	int maxWordLength = 9;

	// Empty constructer
	NineLetterWords();
	//Referance only constructer
	NineLetterWords(std::set<std::string>*_fileData, std::set<std::string>*_foundWords);
	//Referance & chars constructer
	NineLetterWords
	(
		std::set<std::string>*_fileData, std::set<std::string>*_foundWords,
		char _TopLeft,		char _TopMiddle,	char _TopRight,
		char _MiddleLeft,	char _MiddleMiddle,	char _MiddleRight,
		char _LowerLeft,	char _LowerMiddle,	char _LowerRight
	);
	//Referance, chars and bool constructer
	NineLetterWords(
		std::set<std::string>*_fileData, std::set<std::string>*_foundWords,
		char _TopLeft,		char _TopMiddle,	char _TopRight, 
		char _MiddleLeft,	char _MiddleMiddle,	char _MiddleRight,
		char _LowerLeft,	char _LowerMiddle,	char _LowerRight, 
		bool _IgnorePlurals);
	//Gets All the classes details from user
	void GetClassDetailsFromUser();
	//Edit the current instance to be what the user wants
	void GetLettersFromUser();
	//Convert the nine letters to all lower case
	void AllToLower(); 
	//Convert the nine letters to all upper case
	void AllToUpper();
	//Get letter 
	void GetLetterFromUser(LetterPosition letterPos);
	void GetDigitFromUser(bool isMin);

	// The top three letters
	char	TopLeft;		char	TopMiddle;		char	TopRight;
	// The middle three letters
	char	MiddleLeft;	char	MiddleMiddle;		char	MiddleRight;
	// The lower three letters
	char	LowerLeft;		char	LowerMiddle;		char	LowerRight;
	// Weather or not to allow plurals ending with S into the final output
	//Will only find if the non plural version is in the found words
	bool removePlurals;

	//Convet the class to a string easly
	operator std::string();
	//The none opperator version of string return type
	std::string ToString()const;
	//Initiate the varialbes mainly the 
	void InitVariables();
	//Display a formatted heading for writing to file
	std::string DisplayHeading()const;
	std::string DisplayHeading(std::map<char, int> & foundLetterInstances)const;
	//Check the word againts the whole nine letters
	//	only after checking and succeding the middle check
	bool CheckWord(std::string & word, bool checkMiddle)const;
	//Check if the word contains the required letter at least once
	bool DoesStringContainMiddle(std::string & word)const;
	//Check if the word contains plurals
	bool CheckPlurals(std::string& word);
	void GetHardestCharInDictionary();
	void ResetData();
private:
	//Create the string stream for easy display of the nine letters
	void CreateStream();
};
