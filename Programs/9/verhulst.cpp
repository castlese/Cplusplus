/*This program uses the Verhulst Equation to calculate future population. 
 *The equation is manipulated in 4 ways and the result tabulated to show how floating
 *point numbers algorithms can calculate incorrectly.
* New Learning Points: 	*formatting output
						*"ill-conditioned problems"
* Alternative Methods/Improvements:	
* Author: Emily Castles 
* Last Modified: 18th March 2011
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	const int WIDTH=15;
	float xa, xb, xc, xd, r;
	int count=0;
	cout << "-------------------------------------------------------" << endl;
	cout << "This program shows the varying results when calculating" << endl;
	cout << "   population growth using the Verhulst Equation" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Please enter the rate of population growth:" << endl;
	cout << "r = ";
	cin >> r;
	cout << "Please enter the initial population as a fraction of the carrying capacity" << endl;
	cin  >> xa;
	xb = xa; /*initialise all values for population to be used in the 4 methods of calculation */
	xc = xa;
	xd = xa;
	cout << "-------------------------------------------------------------------" << endl;
	cout << fixed << setprecision(10); 
	cout << setw(6) << "YEAR" << setw(WIDTH) << "POP1" << setw(WIDTH) << "POP2" <<setw(WIDTH) << "POP3" <<setw(WIDTH) << "POP4" << endl; /*table header*/

	for(count = 0; count <=100; count+=10)
	{
		//	if(count % 10 == 0)/*print out results after 10 iterations, including initial state */
		//	{
			cout << setprecision(10) << setw(6) << count << setw(WIDTH) << xa << setw(WIDTH) << xb << setw(WIDTH) << xc	<< setw(WIDTH) << xd << endl;
		//	}
			
		xa = (r+1.0)*xa - r*(xa*xa);
		xb = (r+1.0)*xb - (r*xb)*xb;
		xc = ((r+1.0) - (r*xc))*xc;
		xd = xd + r*(xd - xd*xd);

	}
	cout << "-------------------------------------------------------------------" << endl;
	


}
	


