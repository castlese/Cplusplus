/*This program dynamically allocates memory for a 5x3 character matrix in one single block of memory. 
 *The memory addresses for each position of the matrix are printed out
 *The matrix is then deleted
* New Learning Points: 	*pointers
						*printing out pointer address (not what is stored there) using &
						*dynamic assignment of memory (new and delete)						
* Alternative Methods/Improvements:	*put the assignment and deletion into functions
									*print out the memory addresses to prove that they're empty??
* Author: Emily Castles 
* Last Modified: 13th April 2011
*/

#include <iostream>

using namespace std;

int main ()
{
	int *arrayHolder;/*allocate a block of 15 continuous memory locations, within which the 5x3 matrix will be held*/
	int **a;/*allocate pointer to a pointer*/
	int i, j, **temp;
	
	arrayHolder = new int[15];/*pointer to array holder of 15*/
	a = new int*[5];/*pointer to 5 pointers*/

	for (i=0; i<5; i++)
		a[i] = &arrayHolder[i*3];/*for each of the 5 pointers allocated above, set the position to be 3 away from the previous location*/
		
	cout << "*******Assigned Memory************" << endl;
	
	for (i=0; i<5;i++)/*assign the row number to each position of the matrix*/
	{
		for(j=0;j<3;j++)
		{
			a[i][j] = i;
			cout << &a[i][j] << " " << a[i][j] << endl;/*print out the memory address and number at each position in the matrix*/
		}
			
	}
	
	cout << "**********Deleted Memory***********" << endl;
	
	delete [] arrayHolder;/*delete array holder*/
	
	for (i=0; i<5; i++)/*delete the 5 memory pointers allocated*/
	{
		temp = a+3;
		delete [] a;
		a = temp;
	}
	


}
