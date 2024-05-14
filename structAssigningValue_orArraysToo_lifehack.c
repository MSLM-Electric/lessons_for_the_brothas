#include <stdint.h>
#include <stdio.h>
#include <Windows.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}simpleTime_t;

simpleTime_t timeNow = { 0 };

#define ENABLE_MISTAKE_CODE 0

int main(void)
{
    //you can't do just assigning array this way after it inited somewhere:
#if ENABLE_MISTAKE_CODE == 1
    timeNow = { 2024, 05, 14, 9, 44, 10 }; //compiler insults!
#endif
    //but you can do like next way:
    timeNow = (simpleTime_t){ 2023, 10, 03, 19, 30, 9 };
    printf("%u.%u.%u.%u.%u.%u\n", timeNow.year, timeNow.month, timeNow.day, timeNow.hour, timeNow.minute, timeNow.second);
    timeNow = (simpleTime_t){ 1992, 01, 01, 23, 50, 10 };
    printf("%u.%u.%u.%u.%u.%u\n", timeNow.year, timeNow.month, timeNow.day, timeNow.hour, timeNow.minute, timeNow.second);
    return 0;
}