#include "NineLetterWords.h"
#include "../NeededUniversalHeader.h"
#include "FileIO.h"
#include "../SubWindowWithBorder.h"
NineLetterWords::NineLetterWords()
{

}
NineLetterWords::NineLetterWords(std::set<std::string>*_fileData, std::set<std::string>*_foundWords)
{
	fileData = _fileData;
	foundWords = _foundWords;

	TopLeft = ' ';
	TopMiddle = ' ';
	TopRight = ' ';
	MiddleLeft = ' ';
	MiddleMiddle = ' ';
	MiddleRight = ' ';
	LowerLeft = ' ';
	LowerMiddle = ' ';
	LowerRight = ' ';
	removePlurals = false;

	InitVariables();
}
NineLetterWords::NineLetterWords(std::set<std::string>*_fileData, std::set<std::string>*_foundWords, char _TopLeft, char _TopMiddle, char _TopRight, char _MiddleLeft, char _MiddleMiddle, char _MiddleRight,char _LowerLeft,char _LowerMiddle,char _LowerRight)
{
	fileData = _fileData;
	foundWords = _foundWords;

	TopLeft = _TopLeft;
	TopMiddle = _TopMiddle;
	TopRight = _TopRight;
	MiddleLeft = _MiddleLeft;
	MiddleMiddle = _MiddleMiddle;
	MiddleRight = _MiddleRight;
	LowerLeft = _LowerLeft;
	LowerMiddle = _LowerMiddle;
	LowerRight = _LowerRight;

	InitVariables();
}
NineLetterWords::NineLetterWords(std::set<std::string>*_fileData, std::set<std::string>*_foundWords, char _TopLeft, char _TopMiddle, char _TopRight, char _MiddleLeft, char _MiddleMiddle, char _MiddleRight, char _LowerLeft, char _LowerMiddle, char _LowerRight, bool _IgnorePlurals)
{
	fileData = _fileData;
	foundWords = _foundWords;

	TopLeft = _TopLeft;
	TopMiddle = _TopMiddle;
	TopRight = _TopRight;
	MiddleLeft = _MiddleLeft;
	MiddleMiddle = _MiddleMiddle;
	MiddleRight = _MiddleRight;
	LowerLeft = _LowerLeft;
	LowerMiddle = _LowerMiddle;
	LowerRight = _LowerRight;

	removePlurals = _IgnorePlurals;

	InitVariables();
}
void NineLetterWords::GetClassDetailsFromUser()
{
	LogMessage("\n\nPlease Enter Nine Letters to search with.\n");
	LogMessage("Letters will be asked for in order of: 123 456 789 5 being the Middle Middle.\n\n");
	//inputs And Checks if alpha
	ForceRender();
	{
		//Get all the letters in order from user
		GetLettersFromUser();

		//Get min and max
		GetDigitFromUser(true);
		GetDigitFromUser(false);

		//Check the word lenth
		if (minWordLength>maxWordLength)
		{
			//Swap word length around
			minWordLength = minWordLength + maxWordLength;
			maxWordLength = minWordLength - maxWordLength;
			minWordLength = minWordLength - maxWordLength;
		}

		//Get if the plural checker should run
		{
			ForceRender();
			LogMessage("\nEnter (y) or (n) if the results should contain plurals : ");
			//Get user input of Y/N is plurals are checked
			removePlurals = FileIO::GetUserTrueFalse();
			ForceRewriteRender();
		}
	}
	AllToLower();

	LogMessage("\nThank You For Entering The Required Data.");
	ForceRender();
}
void NineLetterWords::GetLettersFromUser()
{
	GetLetterFromUser(LetterPosition::TopLeft);
	GetLetterFromUser(LetterPosition::TopMiddle);
	GetLetterFromUser(LetterPosition::TopRight);
	GetLetterFromUser(LetterPosition::MiddleLeft);
	GetLetterFromUser(LetterPosition::MiddleMiddle);
	GetLetterFromUser(LetterPosition::MiddleRight);
	GetLetterFromUser(LetterPosition::LowerLeft);
	GetLetterFromUser(LetterPosition::LowerMiddle);
	GetLetterFromUser(LetterPosition::LowerRight);
	InitVariables();
}
void NineLetterWords::AllToLower()
{
	//Convert all letters to lower case
	TopLeft = tolower(TopLeft);
	TopMiddle = tolower(TopMiddle);
	TopRight = tolower(TopRight);
	MiddleLeft = tolower(MiddleLeft);
	MiddleMiddle = tolower(MiddleMiddle);
	MiddleRight = tolower(MiddleRight);
	LowerLeft = tolower(LowerLeft);
	LowerMiddle = tolower(LowerMiddle);
	LowerRight = tolower(LowerRight);
	CreateStream();
}
void NineLetterWords::AllToUpper()
{
	//Convert all letters to upper case
	TopLeft = toupper(TopLeft);
	TopMiddle = toupper(TopMiddle);
	TopRight = toupper(TopRight);
	MiddleLeft = toupper(MiddleLeft);
	MiddleMiddle = toupper(MiddleMiddle);
	MiddleRight = toupper(MiddleRight);
	LowerLeft = toupper(LowerLeft);
	LowerMiddle = toupper(LowerMiddle);
	LowerRight = toupper(LowerRight);
	CreateStream();
}
void NineLetterWords::GetLetterFromUser(LetterPosition letterPos)
{
	/*
	This method was suposed to clean up the duplication of the
	Display message, get input then the while loop
	However this caused some issues when I tried it,
	the only letter that changed was the one I initiated the variable with
	So I keep this method and just mad it a bit neater the when it was all 
	contained in the GetLettersFromUser() method.
	*/
	char* localRefToReturn;

	//This Switch statment contains Nine instances of the same code idea,
	/*
	Display Message
	Force the display to rewrite the text
	Get letter from user
	While letter not a letter
		Log Error Message
		Force the display to rewrite the text
		Get letter from user
	*/
	switch (letterPos)
	{
	case NineLetterWords::LetterPosition::TopLeft:
		LogMessage("\nPlease Enter the Top Left Letter: ");
		ForceRewriteRender();
		TopLeft = getch();
		//While user entered none letter
		while (!isalpha(TopLeft))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			TopLeft = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::TopMiddle:
		LogMessage("\nPlease Enter the Top Middle Letter: ");
		ForceRewriteRender();
		TopMiddle = getch();
		//While user entered none letter
		while (!isalpha(TopMiddle))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			TopMiddle = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::TopRight:
		LogMessage("\nPlease Enter the Top Right Letter: ");
		ForceRewriteRender();
		TopRight = getch();
		//While user entered none letter
		while (!isalpha(TopRight))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			TopRight = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::MiddleLeft:
		LogMessage("\nPlease Enter the Middle Left Letter: ");
		ForceRewriteRender();
		MiddleLeft = getch();
		//While user entered none letter
		while (!isalpha(MiddleLeft))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			MiddleLeft = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::MiddleMiddle:
		LogMessage("\nPlease Enter the Middle Middle Letter: ");
		ForceRewriteRender();
		MiddleMiddle = getch();
		//While user entered none letter
		while (!isalpha(MiddleMiddle))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			MiddleMiddle = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::MiddleRight:
		LogMessage("\nPlease Enter the Middle Right Letter: ");
		ForceRewriteRender();
		MiddleRight = getch();
		//While user entered none letter
		while (!isalpha(MiddleRight))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			MiddleRight = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::LowerLeft:
		LogMessage("\nPlease Enter the Lower Left Letter: ");
		ForceRewriteRender();
		LowerLeft = getch();
		//While user entered none letter
		while (!isalpha(LowerLeft))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			LowerLeft = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::LowerMiddle:
		LogMessage("\nPlease Enter the Lower Middle Letter: ");
		ForceRewriteRender();
		LowerMiddle = getch();
		//While user entered none letter
		while (!isalpha(LowerMiddle))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			LowerMiddle = getch();;
		}
		break;
	case NineLetterWords::LetterPosition::LowerRight:
		LogMessage("\nPlease Enter the Lower Right Letter: ");
		ForceRewriteRender();
		LowerRight = getch();
		//While user entered none letter
		while (!isalpha(LowerRight))
		{
			LogMessage("\nThe Character you entered is not a letter.\n Please try again.", SubWindowWithBorder::Colour::Red);
			ForceRewriteRender();
			LowerRight = getch();;
		}
		break;
	default:
		break;
	}
	//Force the display to rewrite the text
	ForceRewriteRender();
}
void NineLetterWords::GetDigitFromUser(bool isMin)
{
	/*
	Similar to the letters
	This is to get the min/max word length

	Display Message
	Force the display to rewrite the text
	Get letter from user
	While letter not a letter
	Log Error Message
	Force the display to rewrite the text
	Get letter from user
	*/
	if(isMin)
	{
		LogMessage("\nPlease enter the min word length.");
		ForceRender();
		minWordLength = getch();;
		while (!isdigit(minWordLength))
		{
			LogMessage("\nNaN \nNot A Number.", SubWindowWithBorder::Colour::Red);
			ForceRender();
			minWordLength = getch();
		}
		minWordLength -= '0';
	}
	else
	{
		LogMessage("\nPlease enter the max word length.");
		ForceRender();
		maxWordLength = getch();;
		while (!isdigit(maxWordLength))
		{
			LogMessage("\nNaN \nNot A Number.", SubWindowWithBorder::Colour::Red);
			ForceRender();
			maxWordLength = getch();
		}
		maxWordLength -= '0';
	}
	ForceRewriteRender();
}
NineLetterWords::operator std::string()
{
	return charString;
}
void NineLetterWords::CreateStream()
{
	stream = std::stringstream();
	stream	<< TopLeft	<< TopMiddle		<< TopRight
			<< MiddleLeft	<< MiddleMiddle	<< MiddleRight
			<< LowerLeft	<< LowerMiddle		<< LowerRight;
	charString = stream.str();
}
void NineLetterWords::InitVariables()
{
	CreateStream();
	letters = std::map<char, int>();
	for (int i = 0; i < 9; i++)
	{
		char* Char = &MiddleMiddle;
		switch (i)
		{
		case 0:
			Char = &TopLeft;
			break;
		case 1:
			Char = &TopMiddle;
			break;
		case 2:
			Char = &TopRight;
			break;
		case 3:
			Char = &MiddleLeft;
			break;
		case 4:
			Char = &MiddleMiddle;
			break;
		case 5:
			Char = &MiddleRight;
			break;
		case 6:
			Char = &LowerLeft;
			break;
		case 7:
			Char = &LowerMiddle;
			break;
		case 8:
			Char = &LowerRight;
			break;
		default:
			Char = &MiddleMiddle;
			break;
		}

		//If char exists add one 
		//	else add to list with occering once
		if (letters.count((*Char)))
			letters[(*Char)]++;
		else
			letters.emplace((*Char), 1);
	}
}
std::string NineLetterWords::DisplayHeading() const
{
	std::stringstream localStream;
	localStream
		<< "Please read the Wordlist file for all the copyright details.\n"
		<< "Letters Are: " << ToString() <<". The line numbers will be 10 higher then the found word count.\n"
		<< "///////////\n"
		<< "//       //\n"
		<< "//  " << TopLeft		<< TopMiddle		<< TopRight	<< "  //\n"
		<< "//  " << MiddleLeft	<< MiddleMiddle	<< MiddleRight	<< "  //\n"
		<< "//  " << LowerLeft		<< LowerMiddle		<< LowerRight	<< "  //\n"
		<< "//       //\n"
		<< "///////////\n";
	return localStream.str();
}
std::string NineLetterWords::DisplayHeading(std::map<char, int>& foundLetterInstances) const
{
	std::stringstream localStream;
	localStream
		<< "Please read the Wordlist file for all the copyright details.\n"
		<< "Word Entered: " << ToString() << ".\n";
	for (auto& num : foundLetterInstances)
		localStream << "Letter: "  << num.first  << " Occers: " << num.second << " Times.\n";
	localStream << "\n";
	
	return localStream.str();
}
std::string NineLetterWords::ToString()const
{
	return charString;
}
bool NineLetterWords::CheckWord(std::string& word, bool checkMiddle)const
{
	//Word Can't be checked against if longer then nine characters

	/*
		If any of these the easy checks are false.
		
		Word longer then max
		or
		Word shorter then min
		or
		The word doesn't contain the required middle letter
	*/
	if (checkMiddle)
	{
		if (word.length() > maxWordLength || word.length() < minWordLength || !DoesStringContainMiddle(word))
			return false;
	}
	else 	if (word.length() > maxWordLength || word.length() < minWordLength)
		return false;
	//Init the local letters found dictionary
	std::map<char, int> lettersFound = letters;
	//Copies entrys of each letter so the needed letters are easy
	
	//Set copied values to 0
	for (auto& a : lettersFound)
		a.second = 0;

	//Final resualt to return usualy set to false
	//Most of the time the method will return false and end, however not in all cases,this is the final value to pass back
	bool resualt = false;

	/*
		For each letter in the word being search
		Using a regular expression to find the letter being searched
		if found add one the local occerances
	*/
	for (auto& character : word)
	{
		{
			std::stringstream localStream;
			localStream << character;
			std::regex letterToFind(localStream.str());
			std::string stringToSearch = charString;
			bool charValue = std::regex_search(stringToSearch, letterToFind);
			if (!charValue)//If it doesn't occer it bails out
				return false;
		}

		//If letters character is in the letters Dictionary/Map
		if (lettersFound.count(character))//Double check it exists
			lettersFound[character]++;//incriment amount of occurrences
		else
			return false;
	}
	//Each letter checks if the letter occers less or equal to the allowed times
	for (auto& c : letters)
	{
		//Makes sure there is a index of c value
		if (lettersFound.at(c.first))
		{
			//Checks value
			//Checks if the letter occers in the word less or equal to the nine letters
			if (c.second >= lettersFound.at(c.first))
				resualt = true;
			else
				return false;
		}
	}
	//Returns Resualt
	return resualt;
}
bool NineLetterWords::DoesStringContainMiddle(std::string& word)const
{
	std::stringstream localStream;
	localStream << MiddleMiddle;
	std::regex characterToFind(localStream.str());
	std::string stringToSearch = word;
	//Search for the occerance of the middle char at least once.
	//If found return true else false
	return std::regex_search(stringToSearch, characterToFind);
}
bool NineLetterWords::CheckPlurals(std::string & word)
{
	//If there is nothing to compair to Bailout
	//	If there is no "s" on the end or the word Bailout
	if (foundWords == NULL)
		return true;
	if (foundWords->size() == 0)
		return true;

	//Make a local copy of the word
	std::string checkWord = word;
	//Check if the last letter is an "s" if not an "s" Its not a plural
	if(checkWord[checkWord.size() - 1] != 's')
		return true;

	//Remove the last "s"
	checkWord.pop_back();

	//Return if there is the word is already in the found set
	return (foundWords->find(checkWord) == foundWords->end());
}
void NineLetterWords::GetHardestCharInDictionary()
{
	//Make sure there are no found words
	foundWords->clear();

	LogMessage("\nPlease Enter the nine letter word you would like to make the puzzle out of.\n");
	ForceRender();
	//Get the letters from user
	GetLettersFromUser();
	GetDigitFromUser(true);
	GetDigitFromUser(false);
	LogMessage("\nWill now calculate the hardest letter to find.\n");
	ForceRewriteRender();
	//Init the local letters found dictionary
	//Copies entrys of each letter so the needed letters are easy
	std::map<char, int> lettersFound = letters;

	//Set copied values to 0
	for (auto& a : lettersFound)
		a.second = 0;

	char prevChar = 'A';
	DisplayLetterWorkingOn(prevChar);
	//Print Current Alphabet index to A
	for (auto word : (*fileData))
	{
		//Display the letter that is currently being worked on
		DisplayLetterWorkingOn(prevChar, word[0]);
		/*
		For every letter in the word add one instance.
		If and only if the letter is already contained.
		*/
		for (auto letter : word)
			//Check if letter is contained and then increment if it is.
			if(lettersFound.count(letter))
				//increment letter if contained
				lettersFound[letter]++;

		//Check the word is contained with in the nine letters
		if (CheckWord(word, false))
			AddWordToFinalDictionary(word);
		DisplayFoundWords();
		ForceRender();
	}
	LogMessage("\n");
	LogMessage("\n");
	LogMessage("\n");
	LogMessage("###################################################",SubWindowWithBorder::Colour::Red);
	/*
	For every letter in the nine letters entered and searched.
	Display the letters and there found instances.
	*/
	for (auto a : lettersFound)
	{
		if (a.first == '\0')
			continue;

		int intValue = a.second;
		std::string charString = " ";
		charString[0] = (char)toupper(a.first);

		LogMessage("Letter: ");
		LogMessage(charString, SubWindowWithBorder::Colour::Green);
		LogMessage(" Occers: ");
		LogMessage(std::to_string(intValue), SubWindowWithBorder::Colour::Green);
		LogMessage(" Times.\n");
		ForceRender();
	}
	LogMessage("###################################################", SubWindowWithBorder::Colour::Red);
	ForceRender();
	//Save the data to disk
	FileIO::FileSave((charString), *foundWords, *this, lettersFound);
}
void NineLetterWords::ResetData()
{
	TopLeft = ' ';
	TopMiddle = ' ';
	TopRight = ' ';
	MiddleLeft = ' ';
	MiddleMiddle = ' ';
	MiddleRight = ' ';
	LowerLeft = ' ';
	LowerMiddle = ' ';
	LowerRight = ' ';
	minWordLength = 4;
	maxWordLength = 9;
}