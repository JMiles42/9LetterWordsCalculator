#include "NineLetterWords.h"
///Defualt constructer
NineLetterWords::NineLetterWords()
{
	TopLeft = 'a';
	TopMiddle = 'a';
	TopRight = 'a';
	MiddleLeft = 'a';
	MiddleMiddle = 'b';
	MiddleRight = 'a';
	LowerLeft = 'a';
	LowerMiddle = 'a';
	LowerRight = 'a';
	removePlurals = false;

	InitVariables();
}
///Extra Constructer for building from the nine chars
//Not currently used
NineLetterWords::NineLetterWords(
	char	_TopLeft,
	char	_TopMiddle,
	char	_TopRight,
	char	_MiddleLeft,
	char	_MiddleMiddle,
	char	_MiddleRight,
	char	_LowerLeft,
	char	_LowerMiddle,
	char	_LowerRight)
{
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
NineLetterWords::NineLetterWords(
	char	_TopLeft,
	char	_TopMiddle,
	char	_TopRight,
	char	_MiddleLeft,
	char	_MiddleMiddle,
	char	_MiddleRight,
	char	_LowerLeft,
	char	_LowerMiddle,
	char	_LowerRight,
	bool _IgnorePlurals)
{
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
///Called to set the letters to what ever the user wants
void NineLetterWords::GetLettersFromUser()
{
	std::cout << "Please Enter Nine Letters to search with. (Anymore will be ignored)\nNote Middle Middle is the required letter in found words.\n";
	std::cout << "Letters will be asked for in order of:"
		<< "\n123\n456\n789\n5 being the Middle Middle.\n123456789\n";
	//inputs And Checks if alpha
	{
		{
			//std::cout << "\nPlease Enter the Top Left Letter: ";
			std::cin >> TopLeft;
			while (!isalpha(TopLeft))
			{
				std::cout << "The Top Left Character is not a letter.\n";
				std::cin >> (TopLeft);
			}
		}
		{
			//std::cout << "\nPlease Enter the Top Middle Letter: ";
			std::cin >> TopMiddle;
			while (!isalpha(TopMiddle))
			{
				std::cout << "The Top Middle Character is not a letter.\n";
				std::cin >> (TopMiddle);
			}
		}
		{
			//std::cout << "\nPlease Enter the Top Right Letter: ";
			std::cin >> TopRight;
			while (!isalpha(TopRight))
			{
				std::cout << "The Top Right Character is not a letter.\n";
				std::cin >> (TopRight);
			}
		}
		{
			//std::cout << "\nPlease Enter the Middle Left Letter: ";
			std::cin >> MiddleLeft;
			while (!isalpha(MiddleLeft))
			{
				std::cout << "The Middle Left Character is not a letter.\n";
				std::cin >> (MiddleLeft);
			}
		}
		{
			//std::cout << "\nPlease Enter the Middle Middle Letter: ";
			std::cin >> MiddleMiddle;
			while (!isalpha(MiddleMiddle))
			{
				std::cout << "The Middle Middle Character is not a letter.\n";
				std::cin >> (MiddleMiddle);
			}
		}
		{
			//std::cout << "\nPlease Enter the Middle Left Letter: ";
			std::cin >> MiddleRight;
			while (!isalpha(MiddleRight))
			{
				std::cout << "The Middle Right Character is not a letter.\n";
				std::cin >> (MiddleRight);
			}
		}
		{
			//std::cout << "\nPlease Enter the Lower Left Letter: ";
			std::cin >> LowerLeft;
			while (!isalpha(LowerLeft))
			{
				std::cout << "The Lower Left Character is not a letter.\n";
				std::cin >> (LowerLeft);
			}
		}
		{
			//std::cout << "\nPlease Enter the Lower Middle Letter: ";
			std::cin >> LowerMiddle;
			while (!isalpha(LowerMiddle))
			{
				std::cout << "The Lower Middle Character is not a letter.\n";
				std::cin >> (LowerMiddle);
			}
		}
		{
			//std::cout << "\nPlease Enter the Lower Right Letter: ";
			std::cin >> LowerRight;
			while (!isalpha(LowerRight))
			{
				std::cout << "The Lower Right Character is not a letter.\n";
				std::cin >> (LowerRight);
			}
		}
		{
			std::cout << "Please enter the min word length.\n";
			std::cin >> minWordCount;
		}
		{
			std::cout << "Please enter the max word length.\n";
			std::cin >> maxWordCount;
		}
		{
			std::cout << "Please enter (y) or (n) if the final output should contain plurals.\n";
			std::cin.clear();
			char ignoreYN;
			std::cin >> ignoreYN;
			if (ignoreYN == 'y' || ignoreYN == 'Y')
				removePlurals = true;
			else if (ignoreYN == 'n' || ignoreYN == 'N')
				removePlurals = false;
			else
				std::cout << "User did not enter a valid response. Plurals will be added to the output.\n";
		}
	}
	//Chars To Lowers
	{
		TopLeft  = tolower(TopLeft);
		TopMiddle = tolower(TopMiddle);
		TopRight = tolower(TopRight);
		MiddleLeft = tolower(MiddleLeft);
		MiddleMiddle = tolower(MiddleMiddle);
		MiddleRight = tolower(MiddleRight);
		LowerLeft = tolower(LowerLeft);
		LowerMiddle = tolower(LowerMiddle);
		LowerRight = tolower(LowerRight);
	}

	//Get Ignore plurals input from user
//	{
//		//std::cout << "\nPlease Enter the Top Left Letter: ";
//		std::cin >> TopLeft;
//		while (!isalpha(TopLeft))
//		{
//			std::cout << "The Top Left Character is not a letter.\n";
//			std::cin >> (TopLeft);
//		}
//	}
	//Init the local unchangeable variables
	InitVariables();
}
///Returns the nine characters in order as a string
NineLetterWords::operator std::string()
{
	return charString;
}
///Creates a stringstream to convert the chars to a string
void NineLetterWords::CreateStream()
{
	stream = std::stringstream();
	stream	<< TopLeft	<< TopMiddle		<< TopRight
			<< MiddleLeft	<< MiddleMiddle	<< MiddleRight
			<< LowerLeft	<< LowerMiddle		<< LowerRight;
	charString = stream.str();
}
///Calls Create stream and sets the local list to letter ocerances values
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
//Prints a display heading used for displaying at the top of the file
std::string NineLetterWords::DisplayHeading() const
{
	std::stringstream stream;
	stream	<< "Please read the Wordlist file for all the copyright details.\n"
			<< "Letters Are:" << ToString() <<". The line numbers will be 10 higher then the found word count.\n"
		<<"///////////\n"
		<<"//       //\n"
		<<"//  " << TopLeft		<< TopMiddle		<< TopRight	<< "  //\n"
		<<"//  " << MiddleLeft		<< MiddleMiddle	<< MiddleRight	<< "  //\n"
		<<"//  " << LowerLeft		<< LowerMiddle		<< LowerRight	<< "  //\n"
		<<"//       //\n"
		<<"///////////\n";
	return stream.str();
}
///Used to easly get the charstring
std::string NineLetterWords::ToString()const
{
	return charString;
}
//Returns true if word can be made using supplied letters
bool NineLetterWords::CheckWord(std::string& word)const
{
	//Word Can't be checked against if longer then nine characters
	if (word.length() > 9 || word.length() < 4 || !DoesStringContainMiddle(word))
		return false;

	//Init the local letters found dictionary
	std::map<char, int> lettersFound = letters;
	
	//Set copied values to 0
	for (auto& a : lettersFound)
		a.second = 0;

	//Final resualt to return usualy set to false
	//Most of the time the method will return false and end, however not in all cases,this is the final value to pass back
	bool resualt = false;

	for (auto& character : word)
	{
		{
			std::stringstream stream;
			stream << character;
			std::regex wordFinder(stream.str());
			std::smatch match;
			std::string stringSearch = charString;

			bool charValue = std::regex_search(stringSearch, wordFinder);

			if (!charValue)
				return false;
		}

		//If letters character is in the letters Dictionary/Map
		if (lettersFound.count(character))
			lettersFound[character]++;//incriment amount of occurrences
	}
	//Each letter checks if the letter occers less or equal to the allowed times
	for (auto& c : letters)
	{
		//Makes sure there is a index of c value
		if (lettersFound.at(c.first))
		{
			//Checks value
			if (c.second >= lettersFound.at(c.first))
				resualt = true;
			else
				return false;
		}
	}
	//Returns Resualt
	return resualt;
}
///Returns True if the middle/Required letter is containd in the word for quick ignoreing if it does not contain letter.
bool NineLetterWords::DoesStringContainMiddle(std::string& word)const
{
	std::stringstream stream;
	stream << MiddleMiddle;
	std::regex wordFinder(stream.str());
	std::string stringSearch = word;
	//Search for the occerance of the middle char at least once.
	//If found return true else false
	return std::regex_search(stringSearch, wordFinder);
}
