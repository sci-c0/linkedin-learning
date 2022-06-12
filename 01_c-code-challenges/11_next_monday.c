#include <stdio.h>
#include <time.h>

#define WKDAY_MON   1

char *ordinal(int v)
{
    if(v / 10 != 1)
    {
        switch(v % 10)
        {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        }
    }    
    return "th";
}

int main()
{
    struct tm *tmp, nextmon, today;
    time_t today_tim, nextmon_tim;
    int diff;
    char today_timstr[100], nextmon_timestr[100];

    today_tim = time(NULL);
    today_tim = 1672508878;
    tmp = localtime(&today_tim);
    memcpy(&today, tmp, sizeof(struct tm));
    
    diff = (WKDAY_MON - today.tm_wday + 7) % 7;
    diff = diff ? diff : 7;

    nextmon_tim = today_tim + (diff * 24 * 60 * 60);
    tmp = localtime(&nextmon_tim);
    memcpy(&nextmon, tmp, sizeof(struct tm));
    
    strftime(today_timstr, 100, "Today is %A, %B %e%%s, %Y\n", &today);
    strftime(nextmon_timestr, 100, "Next Monday will be the %e%%s of %B, %Y\n", &nextmon);

    printf(today_timstr, ordinal(today.tm_mday));
    printf(nextmon_timestr, ordinal(nextmon.tm_mday));

    return 0;
}