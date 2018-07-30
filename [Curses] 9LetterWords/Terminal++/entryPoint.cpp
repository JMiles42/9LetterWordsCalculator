#include "entryPoint.h"
#include <chrono>
#include "NineLetters/FIleIO.h"
#include <WinUser.h>

int main()
{
	InitConsoleWindow();

#pragma region Init Sub Windows
	EnteredLetters = SubWindowWithBorder(EnteredLettersHeight, LeftWindowWidth, 0, 0);
	FoundWords = SubWindowWithBorder(WindowHeight, FoundWordsWidth+1, 0, LeftWindowWidth-1);
	ProgressBar = SubWindowWithBorder(ProgressBarHeight, LeftWindowWidth, EnteredLettersHeight-1, 0);
	TextLogArea = SubWindowWithBorder(WindowHeight - EnteredLettersHeight - ProgressBarHeight + 2, LeftWindowWidth, 8, 0, true);
#pragma endregion
#pragma region Draw Borders
	TextLogArea.DrawBorders(SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.DrawBorders(SubWindowWithBorder::Colour::Cyan);
	//Progress Bar Border
	FoundWords.DrawBorders(SubWindowWithBorder::BorderTileType::PointingDownT, SubWindowWithBorder::BorderTileType::UpperRightCorner, SubWindowWithBorder::BorderTileType::PointingUpT, SubWindowWithBorder::BorderTileType::LowerRightCorner, SubWindowWithBorder::Colour::Cyan);
	ProgressBar.DrawBorders(SubWindowWithBorder::BorderTileType::PointingRightT, SubWindowWithBorder::BorderTileType::PointingLeftT, SubWindowWithBorder::BorderTileType::PointingRightT, SubWindowWithBorder::BorderTileType::PointingLeftT,SubWindowWithBorder::Colour::Cyan);
#pragma endregion
	//Start loading the wordlist in another thread
	ThreadStart();

	std::thread InitDictionaryThread(InitDictionary);
	InitDictionaryThread.detach();
	while (Processing)
	{
		//LogMessage("\nProcessing...");
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	curs_set(FALSE);

	bool ProgRun = true;

	playerData.fileData = &fileData;
	playerData.foundWords= &foundWords;

	while (ProgRun)
	{
		RestartProg();

		LogMessage("Press (W) to search letters through wordlist.\n");
		LogMessage("Or\nPress (C) to convert word to the grid puzzle.\n");
		LogMessage("Or\nPress (Q) to quit.\n");
		LogMessage("Or\nPress (R) to Restart.\n");
		ForceRender();

		char ch = getch();
		if (ch == 'c' | ch == 'C')
		{
			playerData.GetHardestCharInDictionary();
			LogMessage("\n\n Press any key to continue\n\n");
			ForceRender();
			getch();
		}
		if (ch == 'w' | ch == 'W')
		{
			MainProgRun();
			LogMessage("\n\n Press any key to continue\n\n");
			ForceRender();
			getch();

		}
		if (ch == 'q' | ch == 'Q')
		{
			ProgRun = false;
		}
		if (ch == 'r' | ch == 'R')
		{
			ProgRun = true;
		}

	}
}
void ThreadStart()
{
	//Auto Refresh the console
	std::thread refreshThread(TerminalUpdate);
	refreshThread.detach();
}
void RestartProg()
{
	//Disable thread rendering during this edit
	render = false;
	foundWords.clear();
	EnteredLetters.Clear();
	TextLogArea.Clear();
	ProgressBar.Clear();
	FoundWords.Clear();
	playerData.ResetData();
	ForceRender();

	ForceRewriteRender();
	InitWindowText();
	//Enable thread rendering again
	render = true;
}
bool MainProgRun()
{
	//When the other thread starts loading the file continue
	while (fileData.size() == 0)
	{
		//Wait until file is loading
	}
	//Get the letters from the user
	playerData.GetClassDetailsFromUser();
	//Display them in the UI
	DisplayNineLetters();
	DisplayNineLetterBorder();
	PrintCharForPlural();
	ForceRender();

	LogMessage("\nNote the program will now start processing the dictionary.");
	LogMessage("\nUsing the values displayed above.\n");
	playerData.InitVariables();
	LogMessage("\nProcessing.");
	//Set Current Alphabet index to A
	char prevChar = 'A';
	DisplayLetterWorkingOn(prevChar);
	//Print Current Alphabet index to A
	for (auto word : fileData)
	{
		DisplayLetterWorkingOn(prevChar, word[0]);
		//Chack if word is in dictionary
		if (playerData.CheckWord(word,true))
		{
			if (playerData.removePlurals)
			{
				if (playerData.CheckPlurals(word))
					AddWordToFinalDictionary(word);
			}
			else
				AddWordToFinalDictionary(word);
			DisplayFoundWords();
		}
	}
	LogMessage("' \nThe Prosessing has finished.");

	LogMessage("\nThe file will now be saved.\n");
	FileIO::FileSave(playerData.charString, foundWords, playerData);
	return true;
}
void DisplayLetterWorkingOn(char &prev, char current)
{
	//Check Current Alphabet index to prevChar
	if (prev != current)
	{
		//Set prev to curret
		prev = current;
		current = _toupper(current);
		//Display Chars
		DisplayPercentage(current);

		TextLogArea.Print(TextLogArea.Content->_maxy - 1, WorkingOnLetterPos, &current);
	}
}
void DisplayLetterWorkingOn(char current)
{
	DisplayPercentage(current);
	TextLogArea.Print(TextLogArea.Content->_maxy - 1, 0, ("Processing Words Starting with 'A'"));
}
#define NineLetterDisplayBorderTop		"//||||||||||||||||||||\\\\"
#define NineLetterDisplayBorder			"||||||||||||||||||||||||"
#define NineLetterDisplayBorderInverted		"\\\\||||||||||||||||||||//"
void DisplayNineLetterBorder()
{
	EnteredLetters.Print(1, 0, NineLetterDisplayBorderTop,SubWindowWithBorder::Colour::Green);
	EnteredLetters.Print(1, LetterRight + 1, NineLetterDisplayBorderTop, SubWindowWithBorder::Colour::Green);
	EnteredLetters.Print(2, 0, NineLetterDisplayBorder, SubWindowWithBorder::Colour::Yellow);
	EnteredLetters.Print(2, LetterRight + 1, NineLetterDisplayBorder, SubWindowWithBorder::Colour::Yellow);
	EnteredLetters.Print(3, 0, NineLetterDisplayBorderInverted, SubWindowWithBorder::Colour::Red);
	EnteredLetters.Print(3, LetterRight + 1, NineLetterDisplayBorderInverted, SubWindowWithBorder::Colour::Red);


	//for (int i = 1; i < 4; i++)
	//{
	//	EnteredLetters.Print(i, 0, NineLetterDisplayBorder);
	//	EnteredLetters.Print(i, LetterRight+1, NineLetterDisplayBorder);
	//}
}
void DisplayPercentage(char letterDisplay)
{
	int pos = (letterDisplay-'A');

	mvwprintw(ProgressBar.Content,0, (pos*2), "%c%c", letterDisplay,'>');
		
	ProgressBar.Refresh();
	ForceRender();
}
void DisplayPercentageClear()
{
	TextLogArea.Clear();
}
void InitWindowText()
{
	EnteredLetters.Print(0, 0, "Please Enter The Letters You Would Like To Test");

	DisplayNineLetters();
	DisplayNineLetterBorder();
	PrintCharForPlural();

	EnteredLetters.Print(4, 0, "Skip Outputting Plurals? Y/N:Y");
	FoundWords.Print(0, 0, "Found Words:" , SubWindowWithBorder::Colour::Red);
	//Print out the word lenth headings
	EnteredLetters.Print(4, OutputPluralsYN + 3, "Min:");
	EnteredLetters.Print(4, OutputPluralsYN + 11, "Max:");
}
void DisplayNineLetters()
{
	EnteredLetters.Print(1, LetterLeft, &("%c",playerData.TopLeft), SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.Print(1, LetterMiddle, &("%c", playerData.TopMiddle), SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.Print(1, LetterRight, &("%c", playerData.TopRight), SubWindowWithBorder::Colour::Cyan);

	EnteredLetters.Print(2, LetterLeft, &("%c", playerData.MiddleLeft), SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.Print(2, LetterMiddle, &("%c", playerData.MiddleMiddle), SubWindowWithBorder::Colour::Red);
	EnteredLetters.Print(2, LetterRight, &("%c", playerData.MiddleRight), SubWindowWithBorder::Colour::Cyan);

	EnteredLetters.Print(3, LetterLeft, &("%c", playerData.LowerLeft), SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.Print(3, LetterMiddle, &("%c", playerData.LowerMiddle), SubWindowWithBorder::Colour::Cyan);
	EnteredLetters.Print(3, LetterRight, &("%c", playerData.LowerRight), SubWindowWithBorder::Colour::Cyan);
}
void PrintCharForPlural()
{
	playerData.removePlurals ?
		EnteredLetters.Print(4, OutputPluralsYN, "Y", SubWindowWithBorder::Colour::Green) :
		EnteredLetters.Print(4, OutputPluralsYN, "N", SubWindowWithBorder::Colour::Green);

	EnteredLetters.Print(4, OutputPluralsYN + 8, std::to_string(playerData.minWordLength), SubWindowWithBorder::Colour::Green);
	EnteredLetters.Print(4, OutputPluralsYN + 16, std::to_string(playerData.maxWordLength), SubWindowWithBorder::Colour::Green);
}
void TerminalUpdate()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		renderLock.lock();
		{
			if(render)
				ForceRender();
		}
		renderLock.unlock();
	}
}
void InitConsoleWindow()
{
	curs_set(0);
	//Get Console Curser
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	DWORD newStyle = WS_OVERLAPPEDWINDOW;

	SMALL_RECT rect;
	COORD coord;
	coord.X = WindowWidth; // Defining our X and
	coord.Y = WindowHeight;  // Y size for buffer.

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1; // height for window
	rect.Right = coord.X - 1;  // width for window

	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
	SetConsoleWindowInfo(console, TRUE, &rect);       // set window size
	SetConsoleScreenBufferSize(console, coord);       // set buffer size

	resize_term(coord.Y, coord.X);
	//Sets window title
	SetConsoleTitle(TEXT("THE NINE LETTER WORD CALCULATOR OF CHEATY MC CHEATING!!!!!"));





	//Set the console window to have styles. 
	//Styles of No Min/Maximize options and cannot be resized
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE)&~WS_SIZEBOX&~WS_MINIMIZEBOX&~WS_MAXIMIZEBOX);
	refresh();
}
void ForceRender()
{
	EnteredLetters.Refresh();
	TextLogArea.Refresh();
	FoundWords.Refresh();
	ProgressBar.Refresh();
	curses::terminal.update();
}
void ForceRewriteRender()
{
	DisplayNineLetters();
	PrintCharForPlural();
	DisplayNineLetterBorder();
	ForceRender();
}
void DisplayFoundWords()
{
	FoundWords.Print(0, 0, "Found Words Found: " + std::to_string(foundWords.size()), SubWindowWithBorder::Colour::Red);

	if (!foundWords.size())
		return;

	FoundWords.Content->_clear = true;
	FoundWords.Refresh();
	FoundWords.Content->_clear = false;

	int wordCount = 0;
	int wordCountHeight = 1;
	int wordCountWidth = 0;
	std::set<std::string>::iterator it;
	for (it = foundWords.begin(); it != foundWords.end(); ++it)
	{
		std::string s = it->data();
		FoundWords.Print(wordCountHeight, wordCountWidth, s, SubWindowWithBorder::Colour::Green);
		wordCountWidth += 10;
		wordCount++;
		if (wordCount >= (4 * wordCountHeight))
		{
			wordCountHeight++;
			wordCountWidth = 0;
		}
	}
	ForceRender();
}
void InitDictionary()
{
	std::fstream wordFile;
	//Open wordlist
	wordFile.open("Wordlist.txt");
	bool useMessageBoxThisTime = true;
	//Check word list file exits
	while (wordFile.fail())
	{
		std::string newFilePath = "";
		int msgBox = 0;

		//Display message box if there is no wordlist
		if(useMessageBoxThisTime)
			msgBox = MessageBox(nullptr, TEXT("File Not Found In Local Dir\nWhere the exe file is!\n(Yes) Recheck Local Dir.\n(NO) Enter New File Path."), TEXT("Error: No Wordlist"), MB_YESNO);

		useMessageBoxThisTime = true;
		//Recheck the local dir if user said so
		if (msgBox == IDYES)
		{
			LogMessage("\nRechecking Local Dir.\n");
			ForceRender();
			continue;//Goto next loop 
		}
		//Askes user to input word dir
		else if (msgBox == IDNO)
			LogMessage("Please Enter New Filepath.\nFilepath can be either\nRelitive to program.\nOr\nOr absolute.\n");
		
		ForceRender();
		char str[FILENAME_MAX];
		//Get User Input
		getstr(str);

		msgBox = MessageBox(nullptr, TEXT((str)), TEXT("Is the entered file path currect"), MB_YESNO);
		if (msgBox == IDNO)
			useMessageBoxThisTime = false;


		newFilePath = str;
		ForceRender();
		//Try open file again
		wordFile.open(newFilePath);
	}
	Processing = false;
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
			if(line.length()<10)
				fileData.emplace(line);
	}
	wordFile.close();
}
void AddWordToFinalDictionary(std::string word)
{
	foundWords.emplace(word);
}
#pragma region Log Messages
#include "LogMessage.h"
#pragma endregion
