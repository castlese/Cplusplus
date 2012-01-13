/* This program is a conversion of C Portfolio Program 7 to C++
Asks user to enter 2 numbers. The program adds and subtracts these numbers
New Learning Points: Differences between C and C++ syntax, libraries, functions. 
Alternative Methods: n/a
Author: Emily Castles
Last Modified: 1st March 2011

*/
#include <iostream>
using namespace std;
int main()
{
	int number1, number2, sum, sub; /*declares numbers to be entered, their summed and subtracted values*/
	
	cout << "***********      C++ Calulator     *************" << endl;
	cout << "adds and subtracts 2 numbers entered by the user" << endl;
	cout << "************************************************" << endl;

	cout << "Please enter first number:";/*asks the user to imput number 1*/
	cin >> number1;/*assigns value to variable number1*/
	
	cout << "Please enter second number:";/*asks the user to input number 2*/
	cin >> number2;/*assigns value to variable number2*/
	
	sum = number1+number2;
	cout << "The sum of the numbers entered =" << sum << endl;
	
	if (number1 >= number2)
	{
		sub = number1-number2;
	}
	else if (number1 < number2)
	{
		sub = number2-number1;
	}
	cout << "The same numbers subtracted = " <<sub << endl;

}