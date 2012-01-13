/*This program calculates the arctan of a user entered decimal number.
* New Learning Points: 	*using floating point variables (double)
						*cannot use boolean comparison of floating point numbers as with integers (use of an epsilon value)
						*setting number of decimal places - iomanip library - setprecision(), fixed
						*function "pow" to calculate powers - cmath library
						*how long function takes to converge for x=1.0 - too long to wait for. Other values of x converge in reasonable no. of iterations
* Alternative Methods/Improvements:	*error check user input
									*allow user to specify number of decimal places required and set epsilon accordingly 
									*(possibly using a loop to mulptiply by -10)
* Author: Emily Castles 
* Last Modified: 17th March 2011
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	double x, arctan = 0, arctan_prev = 1, epsilon = 1e-15;
	int y=1, count=1, s=1;/*count is to count the number of iterations, s is used to change the sign of each iteration */
	int prec=15;
	cout << "***********      ARCTAN INFINITE SERIES CALCULATOR      ***********" << endl;
	cout << "calculates value of arctan for each consecutive step in the series " << endl;
	cout << "** demonstrates how long the series takes to converge to fifteen " << endl;
	cout << "******* decimal places when using floating point numbers  ********" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "please enter a decimal number between -1.0 and 1.0" << endl;
	cout << "x = ";
	cin >> x;/*error check input?*/
	cout << "--------------------------------------------------" << endl;

		
	while ((fabs(arctan-arctan_prev)) >= epsilon)/*loop to calculate arctan continues until converges to 15 decimal places*/
	{
		arctan_prev = arctan;
		arctan += s*(pow(x,y)/y);
		cout << fixed;
		cout << count << ". " "arctan(x) = " << setprecision(prec) << arctan << endl;/*prints arctan to 15 decimal places*/
		y = y+2;
		count++;
		s = s*-1;
	} 

	
	cout << "Convergence reached in " << count-1 << " iterations" << endl;

}
	


