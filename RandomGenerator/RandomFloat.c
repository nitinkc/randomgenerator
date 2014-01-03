#include <stdio.h>
#include <time.h>
#define _XOPEN_SOURCE 600

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
	int i;
    float a = 5.0;
    for (i=0;i<20;i++){
    printf("%f\n", ((float)rand()/(float)(rand()) * a));
	double f = +1.0 - 2.0 * drand48();
	double g = -1.0 + 2.0 * drand48();
	printf("%f %f\n", f,g);
	}
    return 0;
}