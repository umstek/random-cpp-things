#include <iostream>
#include <string>
#include <time.h>

int main(int argc, char const *argv[])
{
    std::string s;

    struct tm t1;
    struct tm t2;

    t1.tm_hour = 13;
    t1.tm_min = 30;
    t1.tm_sec = 30;

    t2.tm_hour = 17;
    t2.tm_min = 30;
    t2.tm_sec = 30;

    // =>

    time_t tNow;
    time(&tNow);
    struct tm *tmNow = gmtime(&tNow);
    t1.tm_year = tmNow->tm_year;
    t2.tm_year = tmNow->tm_year;
    t1.tm_mon = tmNow->tm_mon;
    t2.tm_mon = tmNow->tm_mon;
    t1.tm_mday = tmNow->tm_mday;
    t2.tm_mday = tmNow->tm_mday;

    time_t tStart = mktime(&t1) - timezone;
    time_t tEnd = mktime(&t2) - timezone;

    std::cout << t1.tm_year << "-" << t1.tm_mon << "-" << t1.tm_mday << "[" << t1.tm_wday << "] "
              << t1.tm_hour << ":" << t1.tm_min << ":" << t1.tm_sec << std::endl;

    std::cout << t2.tm_year << "-" << t2.tm_mon << "-" << t2.tm_mday << "[" << t1.tm_wday << "] "
              << t2.tm_hour << ":" << t2.tm_min << ":" << t2.tm_sec << std::endl;

    std::cout << tStart << " -> " << tNow << " -> " << tEnd << std::endl;

    s.c_str();
    return 0;
}
