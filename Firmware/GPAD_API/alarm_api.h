#ifndef ALARM_API
#define ALARM_API
#include <Stream.h>


enum AlarmLevel { silent, informational, problem, warning, critical, panic };
// const char *AlarmNames[] = { "OK   ","INFO.","PROB.","WARN ","CRIT.","PANIC" };
const int NUM_LEVELS = 6;




int alarm(AlarmLevel level,char *str,Stream &serialport);

#endif
