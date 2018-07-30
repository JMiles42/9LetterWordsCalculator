#pragma once
#include "terminal.h"
#include <curses.h>
#include <Windows.h>
#include <io.h>    // for _setmode()
#include <fcntl.h> // for _O_U16TEXT

//#pragma region Sub Window Colours
//#define  SubWinCol_White 0
//#define  SubWinCol_Black 1
//#define  SubWinCol_Blue 2
//#define  SubWinCol_Green 3
//#define  SubWinCol_Cyan 4
//#define  SubWinCol_Red 5
//#define  SubWinCol_Grey 6
//#pragma endregion

class SubWindowWithBorder
{
public:
	enum class BorderTileType
	{
		UpperLeftCorner = ACS_ULCORNER,	
		LowerLeftCorner = ACS_LLCORNER,
		UpperRightCorner = ACS_URCORNER,
		LowerRightCorner = ACS_LRCORNER,
		PointingLeftT = ACS_RTEE,
		PointingRightT = ACS_LTEE,
		PointingUpT = ACS_BTEE,
		PointingDownT = ACS_TTEE,
		HLine = ACS_HLINE,
		VLine = ACS_VLINE,
		LeftArrow = ACS_LARROW,
		RightArrow = ACS_RARROW,
		DownArrow = ACS_DARROW,
		UpArrow = ACS_UARROW,
		Board = ACS_BOARD,
		Lantern = ACS_LANTERN,
		Block = ACS_BLOCK,
		S1 = ACS_S1,
		S9 = ACS_S9,
		Diamond = ACS_DIAMOND,
		Checkerboard = ACS_CKBOARD,
		Degree = ACS_DEGREE,
		PlusMinus = ACS_PLMINUS,
		Bullet = ACS_BULLET,
		Plus = ACS_PLUS,
	};
	enum class Colour
	{
		White = 0,
		Black = 1,
		Blue = 2,
		Green = 3,
		Cyan = 4,
		Red = 5,
		Purple = 6,
		Yellow = 7
	};
	//Border window only used for the outline/border
	WINDOW* Border;
	//The content this is where all the displayed text is held.
	WINDOW* Content;
	//Determins if the subwindow Content should be a text scrollable window
	bool IsLog;
	//Empty Constructer
	SubWindowWithBorder();
	//Log only constructer
	SubWindowWithBorder(bool _log);
	//Position and dimention only constructer
	SubWindowWithBorder(int nlines, int ncols, int begy, int begx);
	//Full constructer
	SubWindowWithBorder(int nlines, int ncols, int begy, int begx, bool _log);
	//Display the border with current drawing colour
	void DrawBorders()const;
	void DrawBorders(int col)const;
	void DrawBorders(Colour col) const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight)const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, int col)const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, Colour col)const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert)const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert, int col)const;
	void DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert, Colour col)const;
	void DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, int col)const;
	void DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, Colour col)const;
	void DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert)const;
	void DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert, int col)const;
	void DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert, Colour col)const;
	//Print a char to the screen
	void Print(char* data)const;
	void Print(char* data, int col)const;
	void Print(char* data, Colour col)const;
	void Print(std::string& data)const;
	void Print(std::string& data, int col)const;
	void Print(std::string& data, Colour col) const;
	void Print(int x, int y, char* data)const;
	void Print(int x, int y, std::string& data)const;
	void Print(int x, int y, char * data, int col)const;
	void Print(int x, int y, char * data, Colour col) const;
	void Print(int x, int y, std::string& data, int col)const;
	void Print(int x, int y, std::string& data, Colour col) const;
	//Refresh the subwindows contents ready for display
	void Refresh()const;
	//Clears the window
	void Clear() const;
	//Called to draw borders and do first refresh
	void Init()const;
	void Init(int col)const;
	void Init(Colour col)const;
	int GetHeight()const;
	int GetWidth()const;
	int GetArea()const;
	void StartContentColour(int col)const;
	void EndContentColour(int col)const;
	void StartContentColour(Colour col)const;
	void EndContentColour(Colour col)const;
private:
	void WriteBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert)const;
	void StartBorderColour(int col)const;
	void EndBorderColour(int col)const;
	void BorderRefresh()const;
};

