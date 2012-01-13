#include <iostream>
using namespace std;
#include "Array.h"


int main()
{
  Array a(2,6);
  Array b(2,2,3);
  Array c;//not sure about initialisation here....my preferred method would be to use the copy constructor and
			//only declare the new array in equations in lines 23 and 25 below

  for (int i=0;i<2;i++)
    for (int j=0;j<6;j++)
      a(i,j) = i+j;

  for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
      for (int k=0;k<3;k++)
	b(i,j,k) = i*j+k;

  b.reshape(2,6);

  c = a*b;

  c = a.transpose()*b;//operator not working for this. need to over load but not sure how to go about this

  cout << c;

}


