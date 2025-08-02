# FSLogger

Simple logging system implemented in c++

# Dependencies

- GNU Make
- GNU GCC and Binutils minimal version 13.2.0 and 2.41

# Install

For build FSLogger library 

```shell
	$ git clone https://github.com/Andres2626/FSLogger.git
	$ cd FSLogger
	$ make all
```

For clean all .objs

```shell
	$ make clean
```

# Platforms

At the moment this logging system only works in WinX

TODO: Implement more platforms in the future

# Usage 

NOTE: To use this library you must first link libfslog.a into your 
program.

```c++

#include "fslog.h"

using namespace FS;

int main(int argc, char** argv) {
	/* 
	 * Initialize Log system (this is nessesary for print your logs)
	 * If for example you set the level to INFO the program will only
	 * print messages that have a level less than or equal to INFO (view LogLevel.h)
	 */ 
	Logger::SetLogLevel(LogLevel::INFO);

	/* If you print all messages initialize log library like this: */
	// Logger::SetLogLevel(LogLevel::MAX)

	/* 
	 * Note: You can change the LogLevel whenever you want, or when your program requires
	 * it.
	 * Note 2: It is not necessary to put the std::endl at the end of each call to
	 * the log, because the program already includes it.
	 */

	/* This is the main logging macro (you have to define the message level for yourself!) */
	FS_LOG(LogLevel::INFO) << "Hello from main loggin macro";

	/* 
	 * The main loggin macro has another helper macro, this one prints __FILE__ in the
	 * format instead of calling RELPATH (this means that RELPATH omits the whole path of the
	 * __FILE__ which leaves it as x.cpp or x.h ...
	 */ 
	FS_LOG_(LogLevel::INFO) << "Hello from __FILE__ format";

	/* Please note that all macros ending with _ have the above condition (FS_INFO_, FS_WARN_, ...) */

	FS_INFO << "This is a info message!";
	FS_INFO_ << "This is a info2 message!";
	FS_WARN << "This is a warning message!";
	FS_WARN_ << "This is a warning2 message!";
	FS_ERROR << "This is a error message!";
	FS_ERROR_ << "This is a error2 message!";
	FS_FATAL << "This is a fatal message!";
	FS_FATAL_ << "This is a fatal2 message!";
	FS_DEBUG << "This is a debug message!";
	FS_DEBUG_ << "This is a debug2 message!";
	FS_TRACE << "This is a trace message!";
	FS_TRACE_ << "This is a trace2 message!";
}

```
---
