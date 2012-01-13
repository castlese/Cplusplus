/*This program performs a generalised dynamic allocation of a three dimensional matrix
* New Learning Points: 	*pointers
						*dynamic assignment of memory (new and delete)						
* Alternative Methods/Improvements:	*DELETE MEMORY???? IS THIS RIGHT (IN PREVIOUS PROGRAM TOO)
* Author: Emily Castles 
* Last Modified: 13th April 2011
*/

#include <iostream>

using namespace std;

int main ()
{
	int a, b, c;
	int i, j, k;
	int l = 0;
	int ***temp1, **temp2;

	cout << "Please enter the three dimensions of your array" << endl;
	cout << "First Dimension:";
	cin >> a;
	cout << "Second Dimension:";
	cin >> b;
	cout << "Third Dimension:";
	cin >> c;
	
	int length = a*b*c;
	
	int *arrayHolder;/*allocate a block of continuous memory locations which will hold the user input matrix*/
	int ***array;/*allocate pointer to a pointer to a pointer*/
	
	arrayHolder = new int[length];/*pointer to array holder*/
	
	array = new int**[a];/*pointer to 'a' pointers*/

	/*following code, dynamically allocates the memory for the 3D matrix in one block - not actually asked for this in the question*/
	for (i=0; i<a; i++)
	{
		array[i] = new int*[b];/*for each of 'a' pointers, create 'b' pointers */
		for (j=0; j<b; j++)
		{
			array[i][j] = &arrayHolder[l];/*for each 'b' pointers, make the memory address 'c' times away from the previous location*/
			l = l + c;
		}
	}

		
	/*assign numbers to the positions of the array - can refer to the array as normal array[][][]*/	
	for (int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			for(int k=0;k<c;k++)
			{
				array[i][j][k] = k;/*assign a number for each position in the matrix*/
				cout << &array[i][j][k] << " " << array[i][j][k] << endl;/*print out the memory address and number at each posistion in the matrix
																		  *depending on computer, each address should be 4 bytes away from the previous*/
			}
		}
			
	}

	for(i= 0; i <length ; i ++ )
	delete [] arrayHolder ;/*delete the arrayHolder memory that was allocated*/
	delete arrayHolder;
	
	delete [] array[0][0];/*delete the pointers to memory*/
	delete [] array[0];
	delete [] array;
	
}