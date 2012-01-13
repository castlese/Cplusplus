/*This program compares two files and tells the user if they are identical or not
* New Learning Points: 	using fstream instead of ifstream or ofstream
* Alternative Methods/Improvements:	*error checking when opening files
* Author: Emily Castles 
* Last Modified: 16th March 2011
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{

char ca, cb;

fstream str1; 
fstream str2; 

str1.open(argv[1], ios::in); /* open input file stream for first file*/
str2.open(argv[2], ios::in); /* open input file stream for second file*/


str1.get(ca); /*read character from first file*/
str2.get(cb); /*read character from second file*/

while (!str1.eof() && !str2.eof() && ca == cb) /*continue reading characters from the files, while the characters in each file are the same, 
												until the end of either file is reached*/
{
	str1.get(ca);
	str2.get(cb);
}

if (ca == cb)
{
	cout << "files are identical\n";
}

else
{
	cout << "files are different\n";
}


str1.close(); /*close input and output streams*/
str2.close();

}

