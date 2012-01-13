/*This program reads words input by the user and counts the occurence of each letter of the alphabet
* Key Learning Points:	*Using a vector template class instead of array
						*reading in strings from keyboard "cin.getline"
						*static_cast<char> to convert an int to an ASCII character
* Alternative Methods:	*array could be used instead of vector for letter counts
						*can use a while loop to read the characters as they are entered and change the counts at this point. More efficient?	
						*create a function to count letters		
* Author: Emily Castles
* Last Modified: 2nd March 2011
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	const int INITVAL=0;
	vector<int> alphabet(27, INITVAL);/*vector class variable of counts for each letter, initialised to 0*/
	int alphcount, strcount, length;
	const int MAXSTRLEN=200;
	char string[MAXSTRLEN];/*maximum user input of 200 characters*/

	cout <<"************    C++ LETTER COUNTER    ************" << endl;
	cout <<"counts the occurences of each letter in a sentence" << endl;
	cout <<"**************************************************" << endl;
	cout <<"enter a sentence:" << endl;
	cin.getline (string, MAXSTRLEN);/*read user input from keyboard. /0 entered automatically during input*/
	length = strlen(string);
	
	for (alphcount = 0; alphcount < 26; alphcount++)/* for loop to set all count values in alphabet array to 0*/
	{
		alphabet[alphcount] = 0;
	}
	
	for (strcount = 0; strcount < length ; strcount++)/*for loop which calls 'count_letters function' for each character in the string entered by user*/
	{
		for(alphcount = 0; alphcount < 26; alphcount++)
		{
			if ((string[strcount] == (alphcount + 65)) | (string[strcount] == (alphcount + 97)))/*ASCII: 65 is "A", 66 is "B" etc AND 97 is "a", 98 is "b" etc. */
			{
				alphabet[alphcount] = alphabet[alphcount] + 1;
			}
		}
	}
		
	cout << "The totals for each letter (both upper and lower case) are:" << endl;
	
	for (alphcount = 0; alphcount < 26; alphcount++) /*for loop to print out each letter of the alphabet and the total 
														count for that letter 
														%c and "alphacount+97" call the alphabet character based on ASCII
														%d and alphabet[alphacount] calls the total for each alphabet character
													*/
	{
		cout << static_cast<char>(alphcount+97) << "=" << alphabet[alphcount] << endl;/*ASCII: 97 is "a", 98 is "b", etc. */
	}

}


	
			