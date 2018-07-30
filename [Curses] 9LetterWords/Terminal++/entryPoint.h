#pragma once
#include "NeededUniversalHeader.h"

#include "NineLetters/stdafx.h"
#include "SubWindowWithBorder.h"
#include "NineLetters/NineLetterWords.h"

//Program running Used so user can loop it
bool MainProgRun();
//Initiate the volume
void InitConsoleWindow();
//The method given to the refresh thread
void TerminalUpdate();
//Starts the 2 threads
void ThreadStart();
//Display text to the screen at start
void InitWindowText();
//Print the y/n for plurals
void PrintCharForPlural();
//Display the nine letters in there box
void DisplayNineLetters();
//Display the fill around the nine letters
void DisplayNineLetterBorder();
//Load the dictionary off disk
void InitDictionary();
//Called when the program is restarted
void RestartProg();
bool Processing = true;
bool TypeInChars = true;

//Ints that determin the consoles width, height and subwindow positions
const int WindowHeight = 40;
const int WindowWidth = 94;
const int LeftWindowWidth = 53;
const int RightWindowWidth = (WindowWidth - LeftWindowWidth) + 1;
const int TextLogAreaHeight = 10;
const int ProgressBarHeight = 3;
const int EnteredLettersHeight = 7;
const int FoundWordsWidth = 41;

std::mutex renderLock;

//Loaded File Data From WordList
static std::set<std::string> fileData = std::set<std::string>();;
//The Words Found In the Wordlist that fit into the Nineletters
static std::set<std::string> foundWords = std::set<std::string>();;

//The class that does the calculation
NineLetterWords playerData;