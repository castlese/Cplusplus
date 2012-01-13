/*This program provides instructions to solve the puzzle of the Hanoi Towers for a user inputted number of discs
 *Recursive Solution
* New Learning Points: 	*recursion and logic of solving problem
* Alternative Methods/Improvements:	*iterative solution
* Last Modified: 21st March 2011
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void move(int n, char left[], char middle[], char right[]);


int main()
{

	
	int n;/*number of discs */
	char left[] = "Left";
	char right[] = "Right";
	char middle[] = "Middle";
	
	
	cout << "TOWERS OF HANOI" << endl;

	cout << "---------------" << endl;
	cout << endl;
	cout << "Enter number of discs to solve for: ";
	cin >> n;
	if (n < 1)
	{
		cout << "please choose a positive integer for the number of discs: " << endl; 
		cin >> n;
	}
	cout << "*****************INSTRUCTIONS*********************" << endl;
	move(n, left, middle, right);
	
}

void move(int n, char left[], char middle[], char right[])
{
	if (n>0)
	{
	move (n-1, left, right, middle);/*For each case it is easier to solve for "number of discs -1" so this function is called until n=0
									 *Each time the function is called, n-1 discs are moved from a left peg to middle peg using 
									 *the right peg as an intermediary*/
									 
									 
	
	cout << "Move disk from " << left << " Peg to " << right << " Peg" << endl;/*The nth peg is then moved from the left to the right peg*/
	
	move (n-1, middle, left, right);/*The same process is repeated to move next n-1 pegs from the middle peg to the left peg using the right peg as intermediary
									......and so on until n=0, exit function*/
	
	}

}
	


