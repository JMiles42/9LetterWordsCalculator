#pragma once
#include "stdafx.h"
class NineLetterWords
{
public:
	std::stringstream stream;
	std::string charString;
	std::map<char, int> letters;
	int minWordCount = 4;
	int maxWordCount = 9;
	NineLetterWords();
	NineLetterWords
	(
		char _TopLeft,		char _TopMiddle,	char _TopRight,
		char _MiddleLeft,	char _MiddleMiddle,	char _MiddleRight,
		char _LowerLeft,	char _LowerMiddle,	char _LowerRight
	);
	NineLetterWords(
		char _TopLeft,		char _TopMiddle,	char _TopRight, 
		char _MiddleLeft,	char _MiddleMiddle,	char _MiddleRight,
		char _LowerLeft,	char _LowerMiddle,	char _LowerRight, 
		bool _IgnorePlurals);
	void GetLettersFromUser();

	char	TopLeft;		char	TopMiddle;		char	TopRight;
	char	MiddleLeft;	char	MiddleMiddle;		char	MiddleRight;
	char	LowerLeft;		char	LowerMiddle;		char	LowerRight;
	bool removePlurals;

	operator std::string();
	void InitVariables();
	std::string DisplayHeading()const;
	std::string ToString()const;
	bool CheckWord(std::string & word)const;
	bool DoesStringContainMiddle(std::string & word)const;
private:
	void CreateStream();
};
