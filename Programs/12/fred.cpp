/*This program copies personal data from one struct to another and then prints using functions and reference variables where necessary
* New Learning Points: 	*reference variable - i.e. another name for a variable - can edit data at the location instead of copying from one location to other
						*arrays are always reference variables - no '&' needed (however, need to define size of array)
						*const - when you don't require the function to change the variable, define it as const. This way an error will be produced if the 
						*program does change the variable in error
						*warning: deprecated conversion from string constant to char* (??? not entirely sure why this warning appears)
* Alternative Methods/Improvements:	*allow user input of data
* Author: Emily Castles 
* Last Modified: 21st March 2011
*/


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXLEN = 100;

struct person {
	char fname[MAXLEN];
	char sname[MAXLEN];
	int age;
	double height;
	double weight;
};

/*'person& fill' - reference variable, i.e. change the data at this location as opposed to copy from and to variable*/
void fillperson(person& fill,  char fname[MAXLEN], char sname[MAXLEN], int age, double height, double weight);

/*'person name' is const - don't want function to change it. Also, 'person& copyperson' - reference variable, i.e. change data at this location*/
void makecopy(const person name, person& copyperson);

/*'person printperson' is const - don't want function to change it*/
void printperson(const person printperson);

int main()
{
	cout << "***Program to copy and print personal data***" << endl;
	cout << "---------------------------------------------" << endl;
	struct person fred, fredcpy;
	fillperson(fred, "fred", "murphy", 22, 180.0, 83.2);
	makecopy (fred, fredcpy);
	printperson(fredcpy);
}
	
void fillperson(person& fill, char fname[MAXLEN], char sname[MAXLEN], int age, double height, double weight)
{
/*copy strings from function input to person& fill location - can't use strcopy as fname and sname are currently character arrays, i.e, no end of string identifier \0*/
	int count;
	for(count=0; count<strlen(fname); count++)
	{
		fill.fname[count] = fname[count];
	}
	fill.fname[count] = '\0';
	for(count=0; count<strlen(sname); count++)
	{
		fill.sname[count] = sname[count];
	}
	fill.sname[count] = '\0';
/*copy integers from function input to person& fill location */
	fill.age = age;
	fill.height = height;
	fill.weight = weight;
}

void makecopy(const person name, person& copyperson)
{
/*copy from original location to new location - can now use strcpy as strings have been created in previous function*/
	strcpy(copyperson.fname, name.fname);
	strcpy(copyperson.sname, name.sname);
	copyperson.age = name.age;
	copyperson.height = name.height;
	copyperson.weight = name.weight;

}

void printperson(const person printperson)
{
/*print out data from new location*/
	cout << "First Name: " << printperson.fname << endl;
	cout << "Surname: " << printperson.sname << endl;
	cout << "Age: " << printperson.age << endl;
	cout << "Height: " << printperson.height << "cm" << endl;
	cout << "Weight: " << printperson.weight << "kg" << endl;
	
}


			
		


	



	


