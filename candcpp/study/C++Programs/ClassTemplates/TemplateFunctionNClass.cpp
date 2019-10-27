#include<iostream>
using namespace std;

/**********************
templates:
They are used to achieve function overloading 
We can call the same fuction by changing the typename[datatype name]
syntax:
template<class T>
 (or)
template<typename T>

2types of templates:
=>function templates
=>class templates
**********************/

#if 0
// One function works for all data types.
template <typename T>
    //(or)
//template<class T>
T myMax(T x, T y)
{
	return (x > y)? x : y;
}

int main()
{
	cout << myMax<int>(3, 7) << endl;  // Call myMax for int
	cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double
	cout << myMax<char>('g', 'e') << endl;   // call myMax for char
	return 0;
}
#endif

#if 1
/**********************
template class
**********************/
// Class template with two parameters
template<typename T1, typename T2>
      //(or)
//template<class T1, class T2>
class Test
{
	T1 a;
	T2 b;
	public:
	Test(T1 x, T2 y)
	{
		a = x;
		b = y;
	}

	void show()
	{
		cout << a << " and " << b << endl;
	}
};

int main()
{
	Test <float, int> test1 (1.23, 123);
	Test <int, char> test2 (100, 'W');     
	test1.show();
	test2.show();
	return 0;
}
#endif

