/*This program calculates the pi using the formula 4 x (4arctan(1/5) - arctan(1/239)) to 10 decimla places
* Compared to previous cases, the equation converges much faster
* New Learning Points: 	*ensure to use floating point numbers where necessary (i.e. 5.0 as opposed to 5)
* Alternative Methods/Improvements:	*allow user to specify number of decimal places desired
* Author: Emily Castles 
* Last Modified: 18th March 2011
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	double pi=0, arctana=0, arctanb=0, pi_prev=1, epsilon=1e-10;
	int y=1, count=1, s=1;/*count is to count the number of iterations, s is used to change the sign of each iteration */
	int prec=10;
	cout << "This program quickly calculates pi to 10 decimal places" << endl;
	cout << "-------------------------------------------------------" << endl;
	

	while ((fabs(pi_prev-pi)) >= epsilon)
	{
		pi_prev = pi;/*set "pi_prev" to the current value of pi - used in comparison for while loop*/
		arctana += s*(pow((1/5.0),y)/y);
		arctanb += s*(pow((1/239.0),y)/y);
		pi = 4.0*(4.0*arctana - arctanb);
		cout << fixed;
		cout << count << ". " "pi = " << setprecision(prec) << pi << endl;
		y = y+2;
		count++;
		s = s*-1;
	}
	
	cout << "accuracy of 10 decimal places reached in " << count-1 << " iterations" << endl;

}
	


