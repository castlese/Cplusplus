/*This program displays 20 lines at a time using Q to quit or Return to display the next 20 lines
* New Learning Points: 	*std::exit(EXIT_FAILURE) function to exit the program
* Alternative Methods/Improvements:	*error checking for opening of files
* Author: Emily Castles 
* Last Modified: 16th March 2011
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{

	char c;
	char userinput[2];
	int lines;
	fstream str; 


	str.open(argv[1], ios::in); /* open input file stream*/
	str.get(c); /*read first character from file*/
	lines = 0;


	while (!str.eof() && (userinput[0] != 'q' || userinput[0] != 'Q' || userinput[0] == '\n')) 
	{
		cout << c;
		
		if (c == '\n')
		{
			lines++;
		}
		
		if (lines == 20)
		{
			lines = 0;
			cout << "Press 'Q' to quit, or hit return to show the next 20 lines of data:";
			cin.getline(userinput, 2);
			
			if (userinput[0] == 'q' || userinput [0] == 'Q')
			{
				std::exit(EXIT_FAILURE);
			}
			
		}
		
		str.get(c);
		
	}
	cout << "***************end of file has been reached***************" << endl;
}
	


