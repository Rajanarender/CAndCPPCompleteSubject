#include<iostream>
using namespace std;

//Bubble sort(Passes,Iterations)
/********************************************
Bubble sort is repeatedly comparing one element with the next element and then swapping them,
if the lower index numbervalue > next following higher index numbervalue
1st for loop -No. of Passes(n) will be n-1
2nd for loop -No. of iterations(p) will be n-1-i

for each i value increment ,j ranges from 0 to n-i-i
NOTE:Right side elements are sorted in each iteration 
*******************************************/

void swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

void BubbleSort(int x[],int n)
{
	for(int i =0;i<n-1;i++) //This is called as Pass.Since we are advancing to j+1,we make i<n-1                                  
	{                       //Last element is excluded

		for(int j=0;j<n-1-i;j++) //In each Iteration of i, One element of Array gets Sorted in Ascending oder,so j<n-1-i 
		{                        //Right side elements are sorted,so excluded

			if(x[j] <= x[j+1])
			{
				continue;
			}
			else
			{
				swap(&x[j],&x[j+1]);
			} 

#if 0
                              if(x[j] > x[j+1])  //here j+1, includes the next successive index
				swap(&x[j],&x[j+1]);
		                //swap(x[j],x[j+1]); //Since array elements hold address by default
#endif

#if 0
                        if(x[j] <= x[j+1])
                          continue; //skip this
#endif
		}
	}
}
//Time Complexity is O(n2),nsquare

/*************************************************************
Selection sort( left sorted,right unsorted) 
It takes 1st element as min value and keeps checking for value < min element
If it is found,we will swap with the 1st left element
Now the Array will have 
=>sorted elements at left side and
=>unsorted elements at right side
Finally all the elements will get sorted

NOTE:Left side elements are sorted in each iteration 
*************************************************************/

void SelectionSort(int x[],int n)
{
	int min=0;
	for(int i=0;i<n-1;i++) //Last element of array is excluded
	{
		min=i;
		for(int j=i+1;j<n;j++) //Sorted element settles at left side,so i+1
		{                      //Left side elements are sorted              
 
			if(x[j] < x[min])
				min =j; //Keep overridding this min value index till the end of array
		}
		swap(&x[min],&x[i]); //Sorted element placed at the left side of Array
		//swap(x[min],x[i]); //Since array elements hold address by default
	}
}
//Time Complexity is O(n2),nsquare

/*************************************************************
Insertion Sort:(No swapping, only shifting)
This Sorting technique does not use swapping
It uses shifting of array elements to the next position and overrides the next position elements
It is similar to playing cards
*************************************************************/
void InsertionSort(int x[],int n)
{
	int key;
	int j;
	for(int i=1;i<n;i++)
	{
		key = x[i];
		j=i-1;     //j position should be 1 element less to that of i

		while(x[j]>=0 && x[j] > key) //V.V.Imp step
		{
			x[j+1]=x[j]; //V.V.Imp step,shift the array elements to next position
			j--;
		} 
		x[j+1]=key; //V.V.Imp step,Placing the key to the left side of array
	}
}
//Time Complexity is O(n2),nsquare


/*********************************************************
Quick Sort:[Divide and Conquer Algorithm]
In this Sort,we take an array element as Pivot
Now using this pivot, we sort and Divide the array into 2parts
This 2parts again will have their own pivot and divide the array into 2 more parts
Finally the array gets sorted 

NOTE:Sort and Divide concept
*********************************************************/
void swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

int partition(int x[],int l,int r)
{
	int index = l-1; //Take index as -1
	int pivot = x[r]; //Take last element of array as pivot
	//for(int j=0;j<r;j++) //This is wrong
	for(int j=l;j<r;j++) // Right most element pivot is excluded here,V.V.Imp step
	{
               if(x[j] <= pivot) //Validation check,V.V.Imp step
               {
		index++;    //Increment the index and then only swap,V.V.Imp step 
		swap(x[index],x[j]);
               }
	}
	//swap(&x[index+1],&pivot); //swap the index+1 with pivot,This is wrong
	swap(x[index+1],x[r]); //swap the index+1 with x[r],V.V.Imp step
	return index+1; //return index+1,since this is the final pivot position
}

//This is a Recursive function, so we dont have while loop
void QuickSort(int x[],int l,int r)
{
        int pi;
	if(l < r) //should use if condition and not while loop,V.V.Imp step
	{
		pi=partition(x,l,r);
		QuickSort(x,l,pi-1); //Before pivot
	        QuickSort(x,pi+1,r); //After pivot
	}
}
//Time Complexity is O(n2),nsquare

int main()
{
	int arr[]={5,1,4,2};
	//int n=sizeof(arr)/sizeof(arr[0]);
	int n=sizeof(arr)/sizeof(int);
	BubbleSort(arr,n);
	SelectionSort(arr,n);
	QuickSort(arr,0,n-1); // n-1 ,V.V.Imp step
	cout<<"Sorted Array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

/***************************************************************
Merge sort:[Divide and Conquer Algorithm]
We calculate the middle element and Divide the array into 2 halves
We keep dividing these sub arrays further.
Finally a stage arrives where we cannot divide the array anymore
Now we use individual elements, Keep comparing with other elements and arrange in sorted order

NOTE: Divide and sort concept
***************************************************************/















