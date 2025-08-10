#ifndef LOGGER_H
#define LOGGER_H

#include "LogLevel.h"

namespace HooLog {
	using loglevel = LogLevel::value;
namespace{
	loglevel g_loglevel = loglevel::INFO;
}

class Logger {
public:
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	Logger(Logger&&) = delete;
	Logger& operator=(Logger&&) = delete;

	Logger(loglevel level,const char* filename,int line) :level_(level),filename_(filename),line_(line){
		stream_.append("["+ std::string(LogLevel::toString(level_))+"]");
	}

	~Logger() {
		stream_.append("-");
		stream_.append(filename_);
		stream_.append(":");
		stream_.append(std::to_string(line_));
		stream_.append("\n");
		fwrite(stream_.c_str(),stream_.length(), 1, stdout);
	}

	Logger& operator<<(std::string& msg) {
		stream_.append(msg);
		return *this;
	}

	Logger& operator<<(const char* msg) {
		stream_.append(msg);
		return *this;
	}

	Logger& operator<<(int i) {
		stream_.append(std::to_string(i));
		return *this;
	}

	static void setLogLevel(loglevel level) {
		g_loglevel = level;
	}

private:
	loglevel level_;
	const char* filename_;
	int line_;
	std::string stream_;
};

}

#endif LOGGER_H