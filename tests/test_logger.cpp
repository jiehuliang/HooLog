#include "Logger.h"
#include "LogStream.h"

#include <iostream>

void main() {
	HooLog::setLogLevel(HooLog::loglevel::DEBUG);
	int i = -123456;
	for (int i = 0; i < 100; ++i) {
		LOG_DEBUG << " hello world!!!ashdlksahkldhaslksdhjkvjkzxbvjasfkjahvklasbfjkbzxvklhkjgwljksfalsbfl" << i;
		Sleep(100);
	}

	
	//logstream.fmt("nihao test %d ,shishikan %s ,zuihouzailaiyige %.9f",i,"pinjiezifuchuan",3.141567);
	//logstream.fmt("%s", "teste");
	//logstream.toString();

	//logstream.toString();
}