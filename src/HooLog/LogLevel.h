#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

#include <string>

namespace HooLog {

class LogLevel {
public:
	enum class value{
		TRACE,
		DEBUG,
		INFO,
		WARN,
		ERROR,
		FATAL
	};

	static const char* toString(value level) {
		switch (level) {
		case value::TRACE:
			return "\033[36mTRACE\033[0m";
		case value::DEBUG:
			return "\033[35mDEBUG\033[0m";
		case value::INFO:
			return "\033[32mINFO\033[0m";
		case value::WARN:
			return "\033[33mWARN\033[0m";
		case value::ERROR:
			return "\033[31mERROR\033[0m";
		case value::FATAL:
			return "\033[1;31mFATAL\033[0m";
		}
		return nullptr;
	}
};

}


#endif //LOG_LEVEL_H