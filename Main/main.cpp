#include <iostream>
#include <stdlib.h>
#include "src/Log.h"

using namespace FS;

int main(int argc, char** argv)
{
	Logger::SetLogLevel(LogLevel::MAX);

	/* test! */
	for (int i = 0; i < 512; i++) {
		FS_INFO << i;
	}

	return 0;
}