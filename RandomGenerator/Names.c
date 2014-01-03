/*
*	Author:Mahak Rajvanshi
*
*	Date Created: Dec 07,2013
*	Date Mlodified: Dec 08,2013
*
*	This program takes a number as input i.e. how many names needs to be displayed and then displays the same number of first and last names.
*/

//Header Files declaration
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using namespace std;

//Function declaration
void read(vector<string>& nvec, string fname);

//Main function
int main()
{
    int count;//Declaration of variable

    //Declaration of string vectors(Vectors are sequence containers representing arrays that can change in size dynamically unlike arrays)
    vector<string> vecF; 
    vector<string> vecL;
    
    //Declaration of file variables
    ifstream fName;
    ifstream lName;
    
    srand(time(NULL)); 
    
    //Reading data from a file through read function call
    read(vecF, "firstname.txt");
    read(vecL, "lastname.txt" );
    
    cout<< "Enter number of first and last names wanted: ";
    cin >> count;

    cout<<endl<<"List of First and Last Names are: "<<endl<<endl;
    for (int i=0; i<count; i++)
    {
	string str="";
       		   
	// Random first and last name generation
	str += vecF[rand() % vecF.size()];
	str += " ";
	str += vecL[rand() % vecL.size()];

	cout <<str<<endl;//Printing first and last names
		
    }	   
    
    getch();
    return 0;
}

void read(vector<string>& nvec, string fname)
{
    ifstream fin;//File variable declaration
    fin.open(fname.c_str()); //Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a string)                              representing the current value of the string object.

    if (!fin)
    {
        cout << "Unable to read " <<  fname << endl;
        exit(1);
    }

    for (string someName; fin >> someName;) 
    {
        nvec.push_back(someName);//Adds a new element at the end of the vector, after its current last element. 
    }

    fin.close();
}
