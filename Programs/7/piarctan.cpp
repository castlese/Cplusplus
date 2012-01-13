/*This program calculates the pi using the arctan formula pi = 4*arctan(1.0) and demonstrates how slowly the formula 
 *converges when using floating point variable
* New Learning Points: 	*due to slow convergence, the arctan formula is useless for finding pi. iterations were too many to wait for!
* Alternative Methods/Improvements:	*use a different formula to calculate pi which will converge more quickly
* Author: Emily Castles 
* Last Modified: 17th March 2011
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	double pi=0, arctan = 0, pi_prev=1, epsilon = 1e-10;
	int y=1, count=1, s=1;/*count is to count the number of iterations, s is used to change the sign of each iteration */
	int prec=10;
	cout << "This program attempts to calculate pi to 10 decimal places of accuracy" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	while ((fabs(pi_prev-pi)) >= epsilon)
	{
		pi_prev = pi;/*set "pi_prev" to the current value of pi - used in comparison for while loop*/
		arctan += s*(pow(1.0,y)/y);/*calculate arctan*/
		pi = 4.0*arctan;
		cout << fixed;
		cout << count << ". " "pi = " << setprecision(prec) << pi << endl;
		y = y+2;
		count++;
		s = s*-1;
		}
	
	cout << "accuracy of 10 decimal places reached in " << count-1 << " iterations" << endl;

}
	


