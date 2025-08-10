#include "Logger.h"

void main() {
	for(int i = 0;i < 10;++i)
		HooLog::Logger(HooLog::loglevel::INFO, __FILE__, __LINE__) << "hello world:" << i;
}