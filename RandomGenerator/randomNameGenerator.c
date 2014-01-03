#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]){
char inFilename[]= "surnames.csv";
time_t t = time(NULL);
srand(time(NULL));
	FILE *randNamesFilePointer;
	randNamesFilePointer = fopen(inFilename, "r");
	if (randNamesFilePointer == NULL) {
	  fprintf(stderr, "Can't open input file surnames.csv!\n");
	  exit(1);
	}

	printf ("File opened\n");
	char surname[15];//#define SURNAME 15
	printf("The contents of %s file are :\n", inFilename);

	/*while (!feof(randNamesFilePointer)){
	fscanf(randNamesFilePointer, "%s", surname);
	printf("%s\n", surname );
	}*/

	int temp;
	
	fseek(randNamesFilePointer,rand()%20,SEEK_SET);
	fscanf(randNamesFilePointer, "%s", surname);
	fgets(", randNamesFilePointer);
	printf("%s\n", surname );
	fclose(randNamesFilePointer);
}
