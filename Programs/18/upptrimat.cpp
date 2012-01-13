/*This program allocates an upper triangular matrix 
* New Learning Points: *the maths of upper triangular matrices
					   *offsetting the memory location so array can be accessed correctly
* Alternative Methods/Improvements/Comments:	 
* Author: Emily Castles 
* Last Modified: 22nd April 2011
*/

#include <iostream>

using namespace std;

int main ()
{
	
	int **matrix;/*allocate pointer to a pointer*/
	int N, i, j=0;
	cout << "Please enter the size of the matrix, N:" << endl;
	cin >> N;
	
	matrix = new int*[N];/*pointer to N pointers*/

	for (i=0; i<N; i++)
	{
			matrix[i+j] = new int[N-j];/*for each of the N pointers, offset the pointer to location i+j and allocate memory of size N-j, 
										i.e. leaving out the 0's in that row*/
			j++;
	}	
	
	
	for (i=0; i<N;i++)/* print out the address of each element of the upper triangular matrix*/
	{
		for(j=i;j<N;j++)
		{
			cout << &matrix[i][j] << " ";/*accessing matrix elements as required*/
			
		}
		cout << endl;	
	}
	cout << "pointer address of first element of matrix: " << &matrix[0][0] << endl;
	cout << "pointer to first element if matrix: matrix[0][0]" << endl;
	
	delete [] matrix[0];/*delete the dynamic memory that was allocated*/
	delete [] matrix;
}

	
