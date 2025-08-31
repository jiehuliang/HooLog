#include "HooLog.h"

#include <iostream>

#ifdef _WIN32
#define Sleep(time) Sleep(time)
#elif defined(__linux__)
#define Sleep(time) usleep(time*1000)
#endif 

int main() {
	setLogLevel(loglevel::DEBUG);

	std::shared_ptr<AsyncLogger> asyncLogger = std::make_shared<AsyncLogger>();
	setOutputFunc(std::bind(&AsyncLogger::AppendNonCache, asyncLogger,std::placeholders::_1,std::placeholders::_2));
	setFlushFunc(std::bind(&AsyncLogger::Flush, asyncLogger));
	asyncLogger->Start();

	int i = -123456;
	for (int i = 0; i < 10000; ++i) {
		LOG_DEBUG << " hello world!!!ashdlksahkldhaslksdhjkvjkzxbvjasfkjahvklasbfjkbzxvklhkjgwljksfalsbfl" << i;
		Sleep(100);
	}
	
	//logstream.fmt("nihao test %d ,shishikan %s ,zuihouzailaiyige %.9f",i,"pinjiezifuchuan",3.141567);
	//logstream.fmt("%s", "teste");
	//logstream.toString();

	//logstream.toString();
	return 0;
}