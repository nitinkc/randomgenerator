#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i;
    char buff[70];
    time_t t = time(NULL);
    struct tm *tmptr = localtime(&t);
    srand((unsigned)time(NULL));
    for (i=0; i<50; i++){
    tmptr = localtime(&t);
    //printf("Today is           %s", asctime(tmptr));
    tmptr->tm_sec -= rand();
    //tmptr ->tm_min -=rand()%59 ;//[0,59]
        //tmptr ->tm_hour -=rand()%23;//[0,23]
        //tmptr ->tm_mday -=rand()%31; //[1,31]
        //tmptr ->tm_mon -=rand()%11; //[0,11]
        tmptr ->tm_year -= rand()%112; //years since 1900
        //tmptr ->tm_wday -=rand()%6 ;//[0,6] (Sunday = 0)
        //tmptr ->tm_yday -=rand()%365; //[0,365]
    mktime(tmptr);
    printf("100 months ago was %s", asctime(tmptr));
    //setlocale(LC_TIME, "el_GR.utf8");

    /*
     * %A Full Weekday, %a abbr. weekday
     * %B Full Month, %b abbr. Month
     *
     * */
    strftime(buff,sizeof (buff),"Today is %a, %b %d %Y", tmptr);
    puts(buff);
    strftime (buff,sizeof (buff), "The time is %I:%M %p.", tmptr);
    puts(buff);
    }
}
