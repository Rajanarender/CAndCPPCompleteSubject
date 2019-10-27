#include<iostream>
using namespace std;

/*********************************************
Triangle pattern with 
=>Natural no. of stars[with space,without space(90degrees right side),without space(90degrees left side)]
=>Even no. of stars[2row]
=>Odd no. of stars[2row-1]

This pattern consists of 
Each row(for loop)
Each column is occupied by spaces(for loop) and stars(for loop)
*********************************************/

int main()
{

#if 0 //Triangle without spaces,Even No. of stars
	int noofRows=5;
	for(int row=1;row<=noofRows;row++)
	{
		for(int colspace=1;colspace<=noofRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=(2*row);colstar++) //Even stars,2n
		{
			cout<<"*"; //"* "[*withoutspace] is V.V.Imp
		}
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif

#if 0 //Triangle without spaces,Odd No. of stars
	int noofRows=5;
	for(int row=1;row<=noofRows;row++)
	{
		for(int colspace=1;colspace<=noofRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=(2*row)-1;colstar++) //Odd stars,2n-1
		{
			cout<<"*"; //"* "[*withoutspace] is V.V.Imp
		}
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif

#if 1 //Rhombus/Diamond without spaces,Odd No. of stars
	int noofRows=5;
        int NRows = 3; //for the 1st 3 Rows
	for(int row=1;row<=NRows;row++)
	{
		for(int colspace=1;colspace<=NRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=(2*row)-1;colstar++) //Odd stars,2n-1
		{
			cout<<"*"; //"* "[*withoutspace] is V.V.Imp
		}
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}

        //Code for the next 2rows
	int count=1;
	for(int row=2;row>=1;row--) //row=2,since only 2rows are needed,V.V.Imp
	{
		for(int colspace=1;colspace<=count;colspace++) //colspace<=count,V.V.Imp
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=(2*row)-1;colstar++) //Odd stars,2n-1
		{
			cout<<"*"; //"* "[*withoutspace] is V.V.Imp
		}
		count++;
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif

#if 0 //Triangle with spaces,Natural No. of stars
	int noofRows=5;
	for(int row=1;row<=noofRows;row++)
	{
		for(int colspace=1;colspace<=noofRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=row;colstar++) //stars
		{
			cout<<"* "; //"* "[*withspace] is V.V.Imp
		}
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif

#if 0 //Right angle Triangle without spaces, 90degrees towards Right side
	int noofRows=5;
	for(int row=1;row<=noofRows;row++)
	{
		for(int colspace=1;colspace<=noofRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
		for(int colstar=1;colstar<=row;colstar++) //stars
		{
			cout<<"*"; //"*"[*withoutspace] is very important
		}
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif

#if 0 //Right angle Triangle without spaces, 90degrees towards Left side
	int noofRows=5;
	for(int row=1;row<=noofRows;row++)
	{
		for(int colstar=1;colstar<=row;colstar++) //stars,star has to be printed first,V.V.Imp
		{
			cout<<"*"; //"* "[*withoutspace] is very important
		}

#if 0 //Disable this always,Not necessary
		for(int colspace=1;colspace<=noofRows-row;colspace++) //empty spaces
		{
			cout<<" ";
		}
#endif
		cout<<endl; //V.V.Imp,Each row starts in a new line
	}
#endif
}
