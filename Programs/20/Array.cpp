#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "array.h"

// ///////////////////////// //
// Interface for the Array ADT 
// ///////////////////////// //

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array::Array()
{
	dim1 = 1;
	dim1 = 1;
	dim3 = 1;
	size = 1;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array::Array(const int a, const int b)
{
	dim1 = a;
	dim2 = b;
	dim3 = 1;//this is initialised here for when the reshape method is called
	twoD = true;
	int i, j;
	
	size = dim1*dim2;//size of array
	arrayHolder = new double[size];//allocate dynamic memory to store the array
	twodim = new double*[dim1];//pointer to 'dim1' pointers
	
	for (i=0; i<dim1; i++)
		twodim[i] = &arrayHolder[i*dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
	
	//initialise array elements to 0
	for (i=0; i<dim1; i++)
	{
		for(j=0; j<dim2; j++)
			twodim[i][j] = 0;
	}		
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array::Array(const int a, const int b, const int c)
{
	int i, j, k;
	int l=0;//temporary variable
	dim1 = a;
	dim2 = b;
	dim3 = c;
	twoD = false;
	size = dim1*dim2*dim3;//size of array
	arrayHolder = new double[size];//dynamic allocation of memory to store the array
	threedim = new double**[dim1];//pointer to 'dim1' pointers to pointers
	
	for (i=0; i<dim1; i++)
	{
		threedim[i] = new double*[dim2];
		for (j=0; j<dim2; j++)
		{
			threedim[i][j] = &arrayHolder[i*dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
		}
	}
	//dynamically allocate the memory for the 3D matrix in one block
	for (i=0; i<dim1; i++)
	{
		threedim[i] = new double*[dim2];//for each of 'dim1' pointers, create 'dim2' pointers
		for (j=0; j<dim2; j++)
		{
			threedim[i][j] = &arrayHolder[l];//for each 'dim2' pointers, make the memory address 'dim3' times away from the previous location using temp variable 'l'
			l = l + dim3;
		}
	}
	
	for (i=0;i<dim1;i++)
	{
		for(j=0;j<dim2;j++)
		{
			for(k=0;k<dim3;k++)
			{
				threedim[i][j][k] = 0;//initialise each value of the array to 0
			}
		}
			
	}


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array::Array(Array& A)
{
	
	if(twoD)
	{
		A.dim1 = dim1;
		A.dim2 = dim2;
		dim3 = 1;//this is initialised here for when the reshape method is called
		twoD = true;
		int i, j;
		
		A.size = A.dim1*A.dim2;//size of array
		A.arrayHolder = new double[A.size];//allocate dynamic memory to store the array
		A.twodim = new double*[A.dim1];//pointer to 'dim1' pointers
		
		for (i=0; i<A.dim1; i++)
			A.twodim[i] = &A.arrayHolder[i*A.dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
	}
	
	else
	{	
		int i, j, k;
		int l=0;//temporary variable
		A.dim1 = dim1;
		A.dim2 = dim2;
		A.dim3 = dim3;
		A.twoD = false;
		A.size = A.dim1*A.dim2*A.dim3;//size of array
		A.arrayHolder = new double[A.size];//dynamic allocation of memory to store the array
		A.threedim = new double**[A.dim1];//pointer to 'dim1' pointers to pointers
		
		for (i=0; i<A.dim1; i++)
		{
			A.threedim[i] = new double*[A.dim2];
			for (j=0; j<A.dim2; j++)
			{
				A.threedim[i][j] = &A.arrayHolder[i*A.dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
			}
		}
		//dynamically allocate the memory for the 3D matrix in one block
		for (i=0; i<A.dim1; i++)
		{
			A.threedim[i] = new double*[A.dim2];//for each of 'dim1' pointers, create 'dim2' pointers
			for (j=0; j<A.dim2; j++)
			{
				A.threedim[i][j] = &A.arrayHolder[l];//for each 'dim2' pointers, make the memory address 'dim3' times away from the previous location using temp variable 'l'
				l = l + A.dim3;
			}
		}
	}
	
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array::~Array()
{
	delete [] arrayHolder;
	delete arrayHolder;
	
	delete [] twodim[0];
	delete [] twodim;
	
	delete [] threedim[0][0];
	delete [] threedim[0];
	delete [] threedim;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Array::reshape(const int x, const int y)
{
	if ((x*y) != (dim1*dim2*dim3))//if it is a 2 dimensional array, dim3 = 1
		cout << "Error: reshape size is not equal to array size" << endl;
		
	else if (dim3==1)
		cout << "Error: Array is already in 2 dimensional form" <<endl;//not sure if we are required to facilitate reshaping of a 2D array to a 2D array of diff dimensions
																		//e.g. a 3x4 array to a 2x6 array. I haven't included this functionality
		
	else
	{
		dim1 = x;
		dim2 = y;
		Arr *temp;
		int i, j, k;
		int m=0;
		temp = new double[size];
		
		//read current values of the array into temp
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				for(k=0;k<dim3;k++)
				{
					temp[m] = threedim[i][j][k];
					m++;
				}
			}
				
		}
		
		//allocate memory for two dim arr
		twodim = new double*[dim1];//pointer to 'dim1' pointers
	
		for (i=0; i<dim1; i++)
			twodim[i] = &arrayHolder[i*dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
	
		//copy data from temp into new array...check allocation is as per figure in assignment
		m=0;
		for (i=0; i<dim1; i++)
		{
			for(j=0; j<dim2; j++)
			{
				twodim[i][j] = temp[m];
				m++;
			}
		}
		twoD = true;

		//delete memory allocated for threedim array
		delete [] threedim[0][0];
		delete [] threedim[0];
		delete [] threedim;
	
	
	}

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Array::reshape(const int x, const int y, const int z)
{
	if ((x*y*z) != (dim1*dim2*dim3))//if it is a 2 dimensional array, dim3 = 1
		cout << "Error: reshape size is not equal to array size" << endl;
		
	else if (dim3!=1)
		cout << "Error: Array is already in 3 dimensional form" <<endl;
		
	else
	{
		dim1 = x;
		dim2 = y;
		dim3 = z;
		Arr *temp;
		int i, j, k;
		int m=0;
		int l=0;
		temp = new double[size];
		
		//read current values of the array into temp
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				temp[m] = twodim[i][j];
				m++;
			}
		}
		
		threedim = new double**[dim1];//pointer to 'dim1' pointers to pointers
	
		for (i=0; i<dim1; i++)
		{
			threedim[i] = new double*[dim2];
			for (j=0; j<dim2; j++)
			{
				threedim[i][j] = &arrayHolder[i*dim2];//for each of the 'dim1' pointers allocated above, set the position to be 'dim2' away from the previous location
			}
		}
		//dynamically allocate the memory for the 3D matrix in one block
		for (i=0; i<dim1; i++)
		{
			threedim[i] = new double*[dim2];//for each of 'dim1' pointers, create 'dim2' pointers
			for (j=0; j<dim2; j++)
			{
				threedim[i][j] = &arrayHolder[l];//for each 'dim2' pointers, make the memory address 'dim3' times away from the previous location using temp variable 'l'
				l = l + dim3;
			}
		}
	
		//copy data from temp into new array...check allocation is as per figure in assignment
		m=0;
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				for(k=0;k<dim3;k++)
				{
					threedim[i][j][k] = temp[m];
					m++;
				}
			}
				
		}
		
		twoD = false;
		//delete memory allocated for twodim array
		delete [] twodim[0];
		delete [] twodim;
	
	
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Array::transpose()
{
	int i, j;
	int m=0;
	Arr *temp;
	
	if(twoD)
	{
		temp = new double[size];
		//read array values into temp
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				temp[m] = twodim[i][j];
				m++;
			}
		}

		//read array values from temp in transposed order
		m=0;
		for (j=0; j<dim2; j++)
		{
			for (i=0; i<dim1; i++)
			{
				twodim[i][j] = temp[m];
				m++;
			}
		}
	}
	else
	{
		cout << "Can only transpose a two dimensional array" << endl;
	}



}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Array Array::operator*(const Array A)
{
	int i, j, k;
	
	if (twoD != A.twoD)
	{
		cout << "Error: Cannot multiply arrays of different dimensions" << endl;
	}
	else
	{
		if(twoD)//if the array is 2 dimensional multpily as follows
		{
			Array ans(dim1, dim2);
			
			for (i=0;i<dim1;i++)
			{
				for(j=0;j<dim2;j++)
				{
					ans(i,j) = twodim[i][j]*A(i,j);//need to figure out () overloading for this to work
				}
			}
			return ans;
		}
		
		
		else//if the array is not 2 dimensional, i.e. is 3 dimensional, multiply as follows
		{
			Array ans(dim1, dim2, dim3);
			
			for (i=0;i<dim1;i++)
			{
				for(j=0;j<dim2;j++)
				{
					for(k=0;k<dim3;k++)
					{
						ans(i,j,k) = threedim[i][j][k]*A(i,j,k);//need to figure out () overloading for this to work
					}
				}
			}
			return ans;
		}

	}


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
double& Array::operator()(const int i, const int j)//return address of where element is
{
	
	if(!twoD)
	{
		cout << "Error: incorrect call to three dimensional array" << endl;
		exit(-1);
	}
	else
	{
		return twodim[i][j];
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
double& Array::operator()(const int i, const int j, const int k)
{
	
	if(twoD)
	{
		cout << "Error: incorrect call to two dimensional array" << endl;
		exit(-1);
	}
	else
	{
		 
		return threedim[i][j][k];
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Array::print()
{
	int i, j, k;
	
	if(twoD)
	{
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				cout << twodim[i][j] << ' ';
			}
			cout << endl;
		}
	
	}
	else
	{
		for (i=0;i<dim1;i++)
		{
			for(j=0;j<dim2;j++)
			{
				for(k=0;k<dim3;k++)
				{
					cout << threedim[i][j][k] << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
	
	}

}



