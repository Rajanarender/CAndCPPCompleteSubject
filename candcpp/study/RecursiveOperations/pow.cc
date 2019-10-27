#include<iostream>
using namespace std;

int func(int base,int expo)
{
	if(expo == 0) //V.V.Imp
		return 1;

	return base*func(base,expo-1);
}
int main()
{
cout<<func(2,4);

}
