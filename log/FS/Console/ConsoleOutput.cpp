#include "ConsoleOutput.h"
#include <Windows.h>

namespace FS {

	void ConsoleOutput::SetConsoleColor(int bG, int fG)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (bG << 4) | fG);
	}

	void ConsoleOutput::ResetColor()
	{
		SetConsoleColor(FS_CONSOLE_BLACK, FS_CONSOLE_INTENSITY);
	}

}