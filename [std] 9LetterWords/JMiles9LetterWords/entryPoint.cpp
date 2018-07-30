#include "stdafx.h"
#include "NineLetterWords.h"
#include "entryPoint.h"

int main()
{
	InitDictionary();
	std::cout << "Please enter how many times you would like to loop.\n";
	std::cin >> loops;
	while (loops--)
	{
		foundWords.clear();
		playerData.GetLettersFromUser();
		//Set previous char
		char prevChar = 'a';
		//Print First char
		std::cout << "\n\n\nWorking on words starting with: " << prevChar << std::endl;

		//Each word in the wordlist check word
		for (auto word : fileData)
		{
			//Check and set prevChar if differant

			if (prevChar != word[0])//Print the next 
				std::cout << "Now working on words starting with: " << (prevChar = word[0]) << std::endl;



			//	For Getting words ending with s or without
			//
			//if( word [ word.size()-1 ] == 's' )
			//	AddWordToFinalDictionary(word);

			//If word checks out
			if (playerData.CheckWord(word))
			{
				if (playerData.removePlurals)
					if (CheckPlurals(word))
						AddWordToFinalDictionary(word);
					else
						AddWordToFinalDictionary(word);
			}
		}
		//Save word list to file

		//FileIO::FileSave("../Working/" + playerData.ToString() + ".txt", foundWords, playerData);
		FileIO::FileSave(playerData.ToString() + (playerData.removePlurals ? " (Removed Plurals)" : "") + ".txt", foundWords, playerData);
		if ((FileIO::GetUserTrueFalse("Please enter (y) or (n) if you would like to display found words.\n")))
			DisplayFinalList();
	}
	system("pause");
	system("pause");
}

///
void InitDictionary()
{
	std::fstream wordFile;
	//Open wordlist
	//wordFile.open("../Working/WordList.txt");
	wordFile.open("Wordlist.txt");
	
	//Check word list file exits
	while (wordFile.fail())
	{
		std::cout 
			<< "Error Wordlist not in directory.\n"
			<< "If you have moved it. Please enter new path.\n"
			<< "If you have not moved it.\n"
			<< "I'm sorry, it appers I have made a bad program.\n"
			<< "XD\n"
			<< "Enter New File Path:\n";
		std::string newFilePath = "";
		//Get new file name
		std::getline(std::cin, newFilePath);
		//Try open file again
		wordFile.open(newFilePath);
	}
	//Each line
	while (!wordFile.eof())
	{
		//
		std::string line = "";
		//Read line
		std::getline(wordFile, line);
		//If the line is a comment ignore
		if (line[0] != '/')
			//Add none comment to list of read words
			fileData.emplace(line);
	}
	wordFile.close();
}

bool CheckPlurals(std::string& word)
{
	//Make a local copy of the word
	std::string checkWord = word;
	
	//If there is nothing to compair to Bailout
	//	If there is no "s" on the end or the word Bailout
	if (foundWords.size() == 0 || checkWord[checkWord.size()-1] != 's')
		return true;

	//Remove the last "s"
	checkWord.pop_back();

	//Return if there is the word is already in the found set
	return (foundWords.find(checkWord) == foundWords.end());
}

void AddWordToFinalDictionary(std::string& word)
{
	//Add word to list
	foundWords.emplace(word);
}
void DisplayFinalList()
{
	//Display current heading
	std::cout << "These are the found words that fit the 9 letters you entered.\n";
	
	for (auto& fW : foundWords) //Print word
		std::cout << fW << std::endl;
	std::cout << "//////////////////////////////" << std::endl 
		<< "//////////////////////////////" << std::endl;
}
