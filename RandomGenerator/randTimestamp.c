#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void timestamp()
{
    time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
}

int main(){

	/* Get Local Time */
	timestamp();

    time_t t = time(NULL);
    srand (time(NULL));
    struct tm *tmptr = localtime(&t);
    printf("Today is           %s", asctime(tmptr));

    tmptr ->tm_sec -=rand()%61; //[0,61]
    tmptr ->tm_min -=rand()%59 ;//[0,59]
    tmptr ->tm_hour -=rand()%23 ;//[0,23]
    tmptr ->tm_mday -=rand()%31; //[1,31]
    
    tmptr ->tm_mon -=rand()%11; //[0,11]
    tmptr ->tm_year -= rand()%106; //years since 1900
    tmptr ->tm_wday -=rand()%6 ;//[0,6] (Sunday = 0)
    tmptr ->tm_yday -=rand()%365; //[0,365]

    mktime(tmptr);
    printf("Random Time %s", asctime(tmptr));

	return 1;
}
