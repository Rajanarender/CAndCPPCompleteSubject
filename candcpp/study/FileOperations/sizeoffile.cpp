#include<iostream>
using namespace std;
#include<fstream>

//We should open the existing file in Read,Binary mode

int main()
{
	ofstream obj;
	obj.open("filesize.txt");
	obj<<"Global Edge";
	obj.close();

        ifstream ok; //Read Mode
	ok.open("filesize.txt",ios::binary); //Should open the file in Read with Binary Mode
	streampos start,end;
	start=ok.tellg();
	ok.seekg(0,ios::end); //change the file ptr position to the end
	end=ok.tellg();
	ok.close();
	cout<<"size of filesize.txt is: "<<(end-start)<<"bytes\n"; 
}
