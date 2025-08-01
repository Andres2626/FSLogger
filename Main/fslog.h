#pragma once
#include "Src/LogLevel.h"
#include "Src/Logger.h"
#include "Src/LogMessage.h"

#include "Src/Console/ConsoleOutput.h"

#define FS_LOG(x) FS::LogMessage(x, RELPATH, __LINE__, __FUNCTION__)
#define FS_LOG_(x) FS::LogMessage(x, __FILE__, __LINE__, __FUNCTION__)

/* Info level */
#define FS_INFO     FS_LOG(FS::LogLevel::INFO)
#define FS_INFO_    FS_LOG_(FS::LogLevel::INFO)

/* Warn level */
#define FS_WARN     FS_LOG(FS::LogLevel::WARN)
#define FS_WARN_    FS_LOG_(FS::LogLevel::WARN)

/* Error level */
#define FS_ERROR    FS_LOG(FS::LogLevel::ERROR)
#define FS_ERROR_   FS_LOG_(FS::LogLevel::ERROR)

/* Fatal level */
#define FS_FATAL    FS_LOG(FS::LogLevel::FATAL)
#define FS_FATAL_   FS_LOG_(FS::LogLevel::FATAL)

/* Debug level */
#define FS_DEBUG    FS_LOG(FS::LogLevel::DEBUG)
#define FS_DEBUG_   FS_LOG_(FS::LogLevel::DEBUG)

/* Trace level */
#define FS_TRACE    FS_LOG(FS::LogLevel::TRACE)
#define FS_TRACE_   FS_LOG_(FS::LogLevel::TRACE)