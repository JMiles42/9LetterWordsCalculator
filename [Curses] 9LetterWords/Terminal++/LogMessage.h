//This is to make the EP file a little smaller

//Logs messages to the log window
void LogMessage(char * data)
{
	wprintw(TextLogArea.Content, "%s", data);
}
//Logs messages to the log window
void LogMessage(char data)
{
	wprintw(TextLogArea.Content, "%s", data);
}
//Logs messages to the log window
void LogMessage(char * data, SubWindowWithBorder::Colour col)
{
	TextLogArea.StartContentColour(col);
	wprintw(TextLogArea.Content, "%s", data);
	TextLogArea.EndContentColour(col);
}
//Logs messages to the log window
void LogMessage(char data, SubWindowWithBorder::Colour col)
{
	TextLogArea.StartContentColour(col);
	wprintw(TextLogArea.Content, "%s", data);
	TextLogArea.EndContentColour(col);
}
//Logs messages to the log window
void LogMessage(std::string data)
{
	wprintw(TextLogArea.Content, "%s", data.c_str());
}
//Logs messages to the log window
void LogMessage(std::string data, SubWindowWithBorder::Colour col)
{
	TextLogArea.StartContentColour(col);
	wprintw(TextLogArea.Content, "%s", data.c_str());
	TextLogArea.EndContentColour(col);
}
//Logs messages to the log window
void LogMessage(int x, int y, char * data)
{
	mvwprintw(TextLogArea.Content, x, y, "%s", data);
}
//Logs messages to the log window
void LogMessage(int x, int y, char * data, SubWindowWithBorder::Colour col)
{
	TextLogArea.StartContentColour(col);
	mvwprintw(TextLogArea.Content, x, y, "%s", data);
	TextLogArea.EndContentColour(col);
}
//Logs messages to the log window
void LogMessage(int x, int y, std::string data)
{
	mvwprintw(TextLogArea.Content, x, y, "%s", data.c_str());
}
//Logs messages to the log window
void LogMessage(int x, int y, std::string data, SubWindowWithBorder::Colour col)
{
	TextLogArea.StartContentColour(col);
	mvwprintw(TextLogArea.Content, x, y, "%s", data.c_str());
	TextLogArea.EndContentColour(col);
}