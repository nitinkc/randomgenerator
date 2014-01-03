/** 
@Author: Nitin K Chaurasia
@Date: Jan 02, 2014
@Time: 7:10 PM

Occation: Prashants request for Bitbucket...EMBARASSENT 
Sample Progarm to test the ALL THE SHIT of GIT
* its been been a pain in my Ass for three months
* The new year...This baby is going to be nailed
* PROGRAM TO CALCULATE THE AREA OF A CIRCLE OF RANDOM RADIUS
*/


#include <stdio.h>
#include <time.h>
#define PI 3.14
void main(){

/* VARIABLE DECLARATION */
	int radius=0;
	float area;
	time_t t = time(NULL);

/* Initializing the Seed*/
	srand(time(NULL));

/* Area Calculation */
	radius = rand()%100;
	area = (radius*radius)*PI;
	printf("The area of a circle of radius r = %d is %f\n", radius, area);

}//End Main


