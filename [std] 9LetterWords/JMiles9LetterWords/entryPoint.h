#pragma once
#include "FIleIO.h"
//#include "Wordlist.txt"

NineLetterWords playerData;
static std::set<std::string> fileData;
static std::set<std::string> foundWords;
int loops = 1;
void InitDictionary();

bool CheckPlurals(std::string& word);

static void AddWordToFinalDictionary(std::string& word); 
void DisplayFinalList();
