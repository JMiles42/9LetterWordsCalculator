#include "SubWindowWithBorder.h"

SubWindowWithBorder::SubWindowWithBorder()
{

}
SubWindowWithBorder::SubWindowWithBorder(bool _log)
{
	Content->_scroll = _log;
	IsLog = _log;
}

SubWindowWithBorder::SubWindowWithBorder(int nlines, int ncols, int begy, int begx)
{
	Border = newwin(nlines, ncols, begy, begx);
	Content = newwin(nlines - 2, ncols - 2, begy + 1, begx + 1);
}
SubWindowWithBorder::SubWindowWithBorder(int nlines, int ncols, int begy, int begx, bool _log)
{
	Border = newwin(nlines, ncols, begy, begx);
	Content = newwin(nlines - 2, ncols - 2, begy + 1, begx + 1);
	Content->_scroll = _log;
	IsLog = _log;
}
void SubWindowWithBorder::DrawBorders() const
{
	WriteBorders((unsigned long)BorderTileType::UpperLeftCorner, (unsigned long)BorderTileType::UpperRightCorner, (unsigned long)BorderTileType::LowerLeftCorner, (unsigned long)BorderTileType::LowerRightCorner, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(int col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)BorderTileType::UpperLeftCorner, (unsigned long)BorderTileType::UpperRightCorner, (unsigned long)BorderTileType::LowerLeftCorner, (unsigned long)BorderTileType::LowerRightCorner, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)BorderTileType::UpperLeftCorner, (unsigned long)BorderTileType::UpperRightCorner, (unsigned long)BorderTileType::LowerLeftCorner, (unsigned long)BorderTileType::LowerRightCorner, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight) const
{
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, int col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert) const
{
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)hor, (unsigned long)vert);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert, int col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)hor, (unsigned long)vert);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(BorderTileType topLeft, BorderTileType topRight, BorderTileType lowerLeft, BorderTileType lowerRight, BorderTileType hor, BorderTileType vert, Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)topLeft, (unsigned long)topRight, (unsigned long)lowerLeft, (unsigned long)lowerRight, (unsigned long)hor, (unsigned long)vert);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, int col)const
{
	StartBorderColour((int)col);
	WriteBorders(topLeft, topRight, lowerLeft, lowerRight, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders(topLeft, topRight, lowerLeft, lowerRight, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert) const
{
	WriteBorders(topLeft, topRight, lowerLeft, lowerRight, hor, vert);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert, int col)const
{
	StartBorderColour((int)col);
	WriteBorders(topLeft, topRight, lowerLeft, lowerRight, hor, vert);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::DrawBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert, Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders(topLeft, topRight, lowerLeft, lowerRight, hor, vert);
	EndBorderColour((int)col);
	BorderRefresh();
}
void SubWindowWithBorder::Print(char * data) const
{
	wprintw(Content, "%s", data);
	Refresh();
}
void SubWindowWithBorder::Print(char * data, int col)const
{
	StartContentColour((int)col);
	wprintw(Content, "%s", data);
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(char * data, Colour col)const
{
	StartContentColour((int)col);
	wprintw(Content, "%s", data);
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(std::string & data) const
{
	wprintw(Content, "%s", data);
	Refresh();
}
void SubWindowWithBorder::Print(std::string & data, int col)const
{
	StartContentColour((int)col);
	wprintw(Content, "%s", data.data());
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(std::string & data, Colour col)const
{
	StartContentColour((int)col);
	wprintw(Content, "%s", data.data());
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, char* data)const
{
	mvwprintw(Content, x, y, "%s", data);
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, char* data, int col)const
{
	StartContentColour((int)col);
	mvwprintw(Content, x, y, "%s", data);
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, char * data, Colour col)const
{
	StartContentColour((int)col);
	mvwprintw(Content, x, y, "%s", data);
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, std::string& data)const
{
	mvwprintw(Content, x, y, "%s", data.data());
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, std::string& data, int col)const
{
	StartContentColour((int)col);
	mvwprintw(Content, x, y, "%s", data.data());
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Print(int x, int y, std::string & data, Colour col) const
{
	StartContentColour((int)col);
	mvwprintw(Content, x, y, "%s", data.data());
	EndContentColour((int)col);
	Refresh();
}
void SubWindowWithBorder::Refresh()const
{
	wrefresh(Content);
}
void SubWindowWithBorder::Clear()const
{
	for (int x = 0; x < Content->_maxy; x++)
		for (int y = 0; y < Content->_maxx; y++)
			Print(x, y, " ");
	//Was not clearing the screen in my usage
	//Not sure if using it wrong
	//Content->_clear = true;
	wrefresh(Content);
}
void SubWindowWithBorder::Init() const
{
	DrawBorders();
	BorderRefresh();
	Refresh();
}
void SubWindowWithBorder::Init(int col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)BorderTileType::UpperLeftCorner, (unsigned long)BorderTileType::UpperRightCorner, (unsigned long)BorderTileType::LowerLeftCorner, (unsigned long)BorderTileType::LowerRightCorner, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
	Refresh();
}
void SubWindowWithBorder::Init(Colour col)const
{
	StartBorderColour((int)col);
	WriteBorders((unsigned long)BorderTileType::UpperLeftCorner, (unsigned long)BorderTileType::UpperRightCorner, (unsigned long)BorderTileType::LowerLeftCorner, (unsigned long)BorderTileType::LowerRightCorner, (unsigned long)BorderTileType::HLine, (unsigned long)BorderTileType::VLine);
	EndBorderColour((int)col);
	BorderRefresh();
	Refresh();
}
int SubWindowWithBorder::GetHeight() const
{
	return Content->_maxy;
}
int SubWindowWithBorder::GetWidth() const
{
	return Content->_maxx;
}
int SubWindowWithBorder::GetArea() const
{
	return GetWidth() * GetHeight();
}
void SubWindowWithBorder::StartContentColour(int col)const
{
	wattron(Content, COLOR_PAIR(col));
}
void SubWindowWithBorder::EndContentColour(int col)const
{
	wattroff(Content, COLOR_PAIR(col));
}
void SubWindowWithBorder::StartContentColour(Colour col)const
{
	wattron(Content, COLOR_PAIR((int)col));
}
void SubWindowWithBorder::EndContentColour(Colour col)const
{
	wattroff(Content, COLOR_PAIR((int)col));
}
void SubWindowWithBorder::WriteBorders(unsigned long topLeft, unsigned long topRight, unsigned long lowerLeft, unsigned long lowerRight, unsigned long hor, unsigned long vert) const
{
	wborder(Border,
		vert,
		vert,
		hor,
		hor,
		topLeft,
		topRight,
		lowerLeft,
		lowerRight);
}
void SubWindowWithBorder::StartBorderColour(int col)const
{
	wattron(Border, COLOR_PAIR(col));
}
void SubWindowWithBorder::EndBorderColour(int col)const
{
	wattroff(Border, COLOR_PAIR(col));
}
void SubWindowWithBorder::BorderRefresh()const
{
	wrefresh(Border);
}
