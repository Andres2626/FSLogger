#pragma once

#define FS_CONSOLE_BLACK 0
#define FS_CONSOLE_BLUE 1
#define FS_CONSOLE_GREEN 2
#define FS_CONSOLE_CYAN 3
#define FS_CONSOLE_RED 4
#define FS_CONSOLE_MAG 5
#define FS_CONSOLE_YELLOW 6
#define FS_CONSOLE_INTENSITY 7

namespace FS {

	class ConsoleOutput {
	public:
		static void SetConsoleColor(int bG, int fG);
		static void ResetColor();
	};

}
