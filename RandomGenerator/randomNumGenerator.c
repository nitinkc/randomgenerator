/*
 * randomGenerator.c
 *
 *  Created on: Dec 7, 2013
 *      Author: nitin
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/*Main Program*/
int main(int argc, char *argv[]){

	/* Variable Declaration */
	int i;
	long randomNumber;
	char oFilename[]= "randNumbers.csv";

	/* Variable for Time Stamp */
	time_t t = time(NULL);
	/* Initializing the Seed*/
	srand(time(NULL));
	struct tm *tmptr = localtime(&t);
	printf("Today is       nitin    %s", asctime(tmptr));
	char buff[99]; //Temp buffer to store Date and time Stamp to custom format the string
	/* Output FILE HANDLING */
	FILE *randNumFilePointer;

	//fptr = fopen ("randNumbers.csv","w"); //Can be opened like this as well
	randNumFilePointer = fopen (oFilename,"a+"); //Append mode, Returns the File descriptor (Null pointer otherwise)
	if (randNumFilePointer == NULL) {
		printf ("Cannot open file to write!\n");
		 exit(-1);
	}

	/* Generate Random Data */
	for (i=0; i<rand(); i++){

		randomNumber = rand();
		tmptr = localtime(&t);

		/* Random Date Generation by subtracting random years, months etc from Current Date/Time stamp*/
		tmptr ->tm_sec -=rand() ; //[0,61]
		mktime(tmptr);
		//printf("Random Time %s\n", asctime(tmptr));

		strftime(buff,sizeof (buff),"%a, %b %d %Y \t%I:%M %p", tmptr);//Converting time to Custom String with tokens
		//puts(buff);
		//printf("%s",asctime(tmptr));
		fprintf (randNumFilePointer, "%ld, %s\n", randomNumber, buff);
	}
}
