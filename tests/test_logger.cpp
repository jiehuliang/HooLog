#include "Logger.h"
#include "LogStream.h"

#include <iostream>

void main() {
	HooLog::LogStream logstream;
	int i = -123456;
	logstream <<  i ;
	
	//logstream.fmt("nihao test %d ,shishikan %s ,zuihouzailaiyige %.9f",i,"pinjiezifuchuan",3.141567);
	//logstream.fmt("%s", "teste");
	//logstream.toString();

	logstream.toString();
}