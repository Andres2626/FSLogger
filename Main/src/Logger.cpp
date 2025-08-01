#include "Logger.h"

namespace FS {
	
	LogLevel Logger::m_Level;
	LogLevel Logger::m_LineLevel;

	Logger::Logger()
	{

	}

	Logger::~Logger()
	{

	}

	void Logger::Print(int bG, int fG, const char* str)
	{
		std::cout << "[";
		ConsoleOutput::SetConsoleColor(bG, fG);
		std::cout << str;
		ConsoleOutput::ResetColor();
		std::cout << "]: ";
	}

	Logger& Logger::Get()
	{
		static Logger instance;
		return instance;
	}

	Logger& Logger::Get(const LogLevel& level)
	{
		m_LineLevel = level;
		return Get();
	}

	void Logger::SetLogLevel(const LogLevel& level)
	{
		m_Level = level;
	}

	void Logger::End(const char* file, int line, const char* func)
	{
		/* check line level and global level */
		if (m_LineLevel > m_Level)
			return;

		/* convert buffer to string */
		std::string str = m_Buff.str();
		std::string date = GetTimeStr();

		std::cout << func << "() " << "[" << file << ":" << line << "] [" << date << "] ";

		switch (m_LineLevel)
		{
		case FS::LogLevel::INFO:
			Print(FS_CONSOLE_BLACK, FS_CONSOLE_BLUE, "Info");
			break;
		case FS::LogLevel::WARN:
			Print(FS_CONSOLE_BLACK, FS_CONSOLE_YELLOW, "WARN");
			break;
		case FS::LogLevel::ERROR:
			Print(FS_CONSOLE_BLACK, FS_CONSOLE_RED, "ERROR");
			break;
		case FS::LogLevel::FATAL:
			Print(FS_CONSOLE_RED, FS_CONSOLE_INTENSITY, "FATAL");
			break;
		case FS::LogLevel::DEBUG:
			Print(FS_CONSOLE_BLACK, FS_CONSOLE_GREEN, "Debug");
			break;
		case FS::LogLevel::TRACE:
			Print(FS_CONSOLE_CYAN + 8, FS_CONSOLE_INTENSITY, "TRACE");
			break;
		}

		/* print string */
		std::cout << str << std::endl;

		/* restore buffer */
		m_Buff.str("");
		m_Buff.clear();

		m_LineLevel = LogLevel::NONE;
	}

	std::string Logger::GetTimeStr()
	{
		std::time_t now = std::time(nullptr);
		char buff[30];
		std::strftime(buff, 30, "%F %T", std::localtime(&now));
		return buff;
	}
}