#pragma once
#include "terminal.h"
#include <curses.h>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <io.h>    // for _setmode()
#include <fcntl.h> // for _O_U16TEXT
#include "SubWindowWithBorder.h"
#include <string>
#include <sstream>
#pragma region IntPositions
//These are positions that are required for placing letters in there needed place
// Was easier to edit while testing with them being #defines
#define WorkingOnLetterPos 32 //35 Old number
#define OutputPluralsYN 29
#define LetterLeft 24
#define LetterMiddle 25
#define LetterRight 26
#pragma endregion

//Render console
static bool render = true;

//Window Top Left
static SubWindowWithBorder EnteredLetters;
//Window Lower Left
static SubWindowWithBorder TextLogArea;
//Window Middle Left
static SubWindowWithBorder ProgressBar;
//Window Right Side
static SubWindowWithBorder FoundWords;

#pragma region LogMessage
void LogMessage(char* data);
void LogMessage(char data);
void LogMessage(std::string data);
void LogMessage(char* data, SubWindowWithBorder::Colour col);
void LogMessage(char data, SubWindowWithBorder::Colour col);
void LogMessage(std::string data, SubWindowWithBorder::Colour col);

void LogMessage(int x, int y, char* data);
void LogMessage(int x, int y, std::string data);
void LogMessage(int x, int y, char* data, SubWindowWithBorder::Colour col);
void LogMessage(int x, int y, std::string data, SubWindowWithBorder::Colour col);

//Displays the letter that is currently being processed
void DisplayLetterWorkingOn(char &prev, char current);
void DisplayLetterWorkingOn(char current);
#pragma endregion

void ForceRender();
//Display the progress on the screen
void DisplayPercentage(char letterDisplay);
//Calculate and Display the progress on the screen
void DisplayPercentageClear();
//Force a rewrite of all subwindows
void ForceRewriteRender();
//Display found words to screen
void DisplayFoundWords();
//Add word to dictionary
void AddWordToFinalDictionary(std::string word);