/*This program generates statistics for the game of craps
* New Learning Points: 	*manipulation and access of one dimensional and two dimensional arrays
						*error: "name lookup of 'k' changed for ISO 'for' scoping" - this means, the variable k must be initialised outside of the....
						*....for loop if it is to be accessed outside of the for loop
						*use of \t tab character for formatting
* Alternative Methods/Improvements:	*introduce error checking for user entry of 0 or greater than the maximum number of dice or rolls
* Author: Emily Castles 
* Last Modified: 28th March 2011
*/


#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()
#include <cmath> // needed for sqrt()

using namespace std;

const int MAXNUMTOROLL=10; /*Count k always refers to the number of dice*/
const int MAXROLLS=100; /*Count i always refers to the number of rolls*/

// Prototypes of Functions to Implement:
// You MUST use these exact definitions, rather than writing your own

// output the values of the dice that are rolled in the array diceVals and return
// the sum of the values rolled

// rollDice returns the values of the dice that were rolled in the array diceVals[]
// It also returns the sum of the values rolled in its return value
int rollDice(int diceVals[], int numberToRoll=2);

// computeStats takes an array of roll sums as input, along with the total number
// of rolls carried out.  In the two output parameters, mean and std, it returns the mean
// and standard deviation of the set of roll sums
void computeStats(int rollSums[], int numRolls, double &mean, double &std);

// writeStats, takes an input parameter rollSums, which is a 2-dimensional array, 
// consisting of the roll sums for a rolling numToRoll dice a total of numRolls times. 
// It also takes input parameters mean[] and std[] - arrays of the means and standard deviations
// of the roll sums.
// It prints these values to the screen in the tabular form specified in the problem description
void writeStats(int rollSums[][MAXROLLS], double mean[], double std[], int numRolls, int numToRoll);

int main()
{
  int sum;
  int rollSums[MAXNUMTOROLL][MAXROLLS];
  int diceVals[MAXROLLS];
  double mean[MAXNUMTOROLL], std[MAXNUMTOROLL];
  int numToRoll, numRolls;

  // STEP 1: Ask user to input the maximum number of dice to use:

  cout << "Please enter the maximum number of dice to use:" << endl;
  do 
    {
      cin >> numToRoll;
    } while (numToRoll < 0 || numToRoll > MAXNUMTOROLL); 

  cout << "Please enter the number of rolls:" << endl;

  // STEP 2: Ask user to input the number of rolls to carry out:
  do
    {
      cin >> numRolls;
    } while (numRolls < 0 || numRolls > MAXROLLS);

  // STEP 3: For k=1 to numToRoll, simulated numRolls rolls of the dice
  // and store the sum of the numbers rolled in the array rollSums[][]

  for (int k=1;k<=numToRoll;k++)
    {
      for (int i=0;i<numRolls;i++)
	{
	  rollSums[k-1][i] = rollDice(diceVals, k);
	}
    }

  // STEP 4: Compute the mean and standard deviation of the roll sums

  for (int k=1;k<=numToRoll;k++) /*Changed from i to k to keep with standard for counts, i.e. k counts dice, i counts rolls */
    computeStats(&rollSums[k-1][0], numRolls, mean[k-1], std[k-1]);/*&rollSums[k-1][0] - this is a pointer to first element of row i-1. In function, need to
																	manipulate one-dimensional array only*/

  // STEP 5: Write out the table of roll sums along with the mean and standard
  // deviation

  writeStats(rollSums, mean, std, numRolls, numToRoll);

}

int rollDice(int diceVals[], int numberToRoll)
{
	int sum=0;
	for(int k=0; k<numberToRoll; k++)
	{
		diceVals[k] = 1 + rand()%6;
		sum += diceVals[k];
	}

	return sum;
}

void computeStats(int rollSums[], int numRolls, double &mean, double &std)
{
	double total=0;
	double x=0;
	
	/*calculate the mean by totalling the rollSums and dividing by the number of Rolls. "mean" is a reference variable so no return needed*/
	for(int i=0; i<numRolls; i++)
	{
		total += rollSums[i];
	}
	mean = total/numRolls;
	
	/*calculate the standard deviation using the mean. "std" is a reference variable - value changed at memory location, no return needed*/
	for (int i=0; i<numRolls; i++)
	{
		x += pow((rollSums[i] - mean),2);
	}
	std = sqrt(x/numRolls);

}

void writeStats(int rollSums[][MAXROLLS], double mean[], double std[], int numRolls, int numToRoll)
{

	int k, i;/*initially initialsied within the first for loop, however, this generated an error whereby variable initialised within the loop cannot be accessed
				outside of that loop - this created a problem as k is used in 4 loops*/
	cout << setw(23) << "Number of Dice Rolled: ";
	
	for (k=1; k<=numToRoll; k++)
	{
		cout << "\t" << k;	
	}
	cout << endl;
	
	
	for (i=0; i<numRolls; i++)
	{
		cout << setw(23) << " ";
		
		for (k=1; k<=numToRoll; k++)
		{
			cout << "\t" << rollSums[k-1][i];
		}
		cout << endl;
	}

	cout << setw(23) << "Mean: ";
	for (k=1; k<=numToRoll; k++)
	{
		cout << "\t" << fixed << setprecision(3) << mean[k-1];
	}
	cout << endl;
	
	cout << setw(23) << "Standard Deviation: ";
	for (k=1; k<=numToRoll; k++)
	{
		cout << "\t" << fixed << setprecision(3) << std[k-1];
	}
	cout << endl;
	
}





  





      
      
      






  



  

  

  
