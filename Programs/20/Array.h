#define true 1
#define false 0

/*definitions of data types*/

typedef double Arr;
typedef int Size;
typedef int Dim;

class Array {
  private:
    Size size;//array size, i.e. number of elements
	Arr *arrayHolder;//pointer to an arrayHolder
	Arr **twodim;//pointers for a two dimensional array 
	Arr ***threedim;//pointers for a three dimensional array
	Dim dim1;
	Dim dim2;
	Dim dim3;
	bool twoD;
	
  public:
  Array();
  Array(const int a, const int b);//constructor for 2D
  Array(const int a, const int b, const int c);//constructor for 3D
  Array(Array& c);//copy constructor
  ~Array();//destructor
  void reshape(const int x, const int y);//manipulator method to reshape
  void reshape(const int x, const int y, const int z);//manipulator method to reshape
  void transpose();//manipulator method to transpose a 2D array
  Array operator*(const Array A);//operator to mulitply arrays
  double& operator()(const int i, const int j);//operator to return element[i][j]
  double& operator()(const int i, const int j, const int k);//operator to return element [i][j][k]
  void print();//accessor method to print the array
  };

