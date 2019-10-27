#include<iostream>
using namespace std;


void func(int x, int y)
{
	for(int i=x;i<=y;i++)
	{
		bool a[y-x] = {false}; //a[5] means digits 0,1,2,3,4,5
		int num = i;
		while(num)
		{
			if(a[num%10]) //if same digit repeats,then drop that number and Go to Next Number
				break;

			a[num%10] = true;
			num=num/10;
		}
		if(num==0) 
			cout<<"Unique Element is: "<<i<<endl;      
	}
}

int main()
{
	func(100,105);
}
