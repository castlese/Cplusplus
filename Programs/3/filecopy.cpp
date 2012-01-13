/*This program copies text from an input file to an output file. 
* New Learning Points: 	*use of fstream library, ifstream and ofstream functions
* Alternative Methods:	*prompt the user for file name and scan input	
						*need to introduce error checking for opening of files etc
						*can this be donw using one stream for input and output using fstream?
* Author: Emily Castles
* Last Modified: 16th March 2011
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{

char c;

	ifstream input_stream; /* open input file variable*/
	ofstream output_stream; /* open output file variable*/

	input_stream.open(argv[1], ios::in); /* open input file stream*/
	output_stream.open(argv[2], ios::out); /* open output file stream*/

	while (!input_stream.eof()) /*read the data from the input file character
								by character, until "end of file" is reached*/
	{
		input_stream.get(c);
		output_stream << c;
	}


	input_stream.close(); /*close input and output streams*/
	output_stream.close();

	cout << "files copied successfully";
}
