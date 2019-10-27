#include<iostream>
using namespace std;

/****************************************************
NOTE:
&
|
<<
>>
~
^
toggle means ^
left shift means less than (<<)
1<<0 , do not move the position of 1
1<<1, move the position of 1 by 1bit to left

(1<<pos-1) //Generally
(1<<i) //for all bits or specific range of bits iteration
****************************************************/

1.How to set a particular bit in a given number?
Ans:num | = (1<<pos-1); Here pos range is [0 to 7]
num=num|(1<<pos-1);

2.How to clear a particular bit in a given number?
Ans:num & = ~(1<<pos-1);
num = num &~(1<<pos-1)
;
3.How to toggle a particular bit in a given number?
Ans:num ^= (1<<pos-1);
num = num^(1<<pos-1);

4. Find the count of no. of bits set/clear in a given number?
Ans:
// i means pos 
for(int i =0;i<8;i++) [0 to 7 for 8bit machine] //traverse through all the bits
#if 1 //Processor dependent
for(int i =0;i<sizeof(int)*8;i++) //8 => 8bits,sizof(int) is 4bytes in 32bit processor,V.V.Imp //0 to 31 bits
for(int i =0;i<sizeof(int)*8;i++) //8=> 8bits,sizof(int) is 8bytes in 64bit processor,V.V.Imp //0 to 63 bits
#endif
{

	if(num&(1<<i)) 
		setcount++;
	else
		clearcount++;

#if 0 // May not need
	if( num&(1<<i) ==1) 
		setcount++;
	else if( num&(1<<i) ==0)
		clearcount++;
#endif
}
cout<<setcount;    //no. of bits set
cout<<clearcount;  //no. of bits clear

5. Find the count of no. of bits set in the given range of bits of a number?
Ans:
//1st bit to 5th bit => 0th pos to 4th pos 
for(int i =(strtpos);i<=(endpos);i++) [0 to 7 for 8bit machine] //traverse through all the bits //i<=(endpos-1) Imp
{
	if( num&(1<<i-1) ==1) //It Means some value you get other than 0
		setcount++;
	else if( num&(1<<i-1) ==0)
		clearcount++;
}
cout<<setcount;    //no. of bits set
cout<<clearcount;  //no. of bits clear

6.How to do nibble swap in a given number?
short -2bytes
word-4bytes
byte-8bits

nibble-4bits

i/p: 0000 0010
o/p: 0010 0000

Ans: num= (num<<4 | num>> 4);

7.Do swapping of 2 no's using bitwise operations
Ans:
int x=10,y=20;
x=x^y;
y=x^y;
x=x^y;
cout<<x<<y; //x=20,y=10

swap even,odd  bits
byte swap
power of 2, n&(n-1)
even,odd numbers using bitwise
trailing zeros
