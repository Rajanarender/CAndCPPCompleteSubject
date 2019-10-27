#include<iostream>
using namespace std;
#include<fstream> //For C++ file operations

/***************************************************
C-style files
FILE *ptr
ptr =fopen("raja.txt","r"); //r,w,b
fclose(fp);
fseek(fp,5,SEEK_SET); //here 5 is offset, SEEK_SET/SEEK_CUR/SEEK_END
ftell(fp);
fscanf(fp,,); //read from file
fprintf(fp,,); //write into file
while( !feof(fp) ) //feof(fp) API internally traverses the fp pointer by 1byte in each iteration till the end of file
{
}
--------------------------------------------------------
C++ style files
ifstream obj; //Reading file using ifstream class
obj.open("raja.txt",ios::in);
obj.close();
obj.seekg(5,ios::beg);//here 5 is offset, ios::beg/ios::cur/ios::end
obj.tellg();
char c;
while( !obj.eof() )
{
obj>>c; //Reading from file character by character
        //similar to cin>> 
}

ofstream obj; //Writing file using ifstream class
obj.open("raja.txt",ios::out);
obj.close();
obj.seekp(5,ios::beg);//here 5 is offset, ios::beg/ios::cur/ios::end
obj.tellp();
obj<<"Global Edge"; //Writing into file
                    //similar to cout<< 
***************************************************/

/*
ofstream obj1;
obj1<<"Hello World"; //For writing into file

ifstream obj
char c;
while(!obj.eof())
{
obj>>c;// For reading from file
cout<<c; //Print to console
}

ifstream-default mode is ios::in, class for Reading file,Member functions: seekg(,),tellg()
ofstream-default mode is ios:out, class for Writing file,Member functions: seekp(,),tellp()
fstream- default mode is ios:in|ios:out, class for both
All modes are:(6 modes)
ios::binary
ios::app
ios::trunc
ios::ate

is_open()-true if file open successfully, else false
eof()-to Check stream has reached end of file or not

seekg(offset/bytes,direction) //directions - ios::beg,ios::cur,ios::end
seekp(offset/bytes,direction)
streampos x = tellg()
streampos x = tellp()
*/

int main()
{
	//ofstream obj("chitti.txt"); //obj creation,Constructor call
	//ofstream obj("chitti.txt",ios::out); //obj creation,Constructor call
	ofstream obj;
	obj.open("chitti.txt");
	//obj.open("chitti.txt",ios::out);
	if(obj.is_open()) //To check whether we can open file or not
	{
		obj<<"Past is a mistake"<<endl;
		obj<<"Power pack";
		obj.close(); //destructor call
	}
       
	if(!obj)//Should not use obj != NULL (or) '\0'
	{
		cout<<"No data is present in obj,Means that file is not present\n";
	}

//        while(!obj.eof()) //Used for Traversing in the file,Should not use obj.eof() != NULL (or)'\0'
  //      {}

        obj.open("chitti.txt",ios::trunc); //Complete Replacement
        obj<<"Global Edge"<<endl;
        obj.close();

        obj.open("chitti.txt",ios::app); //Appending the data
        obj<<"ALTRAN";
        obj.close();

#if 1
	//ofstream obj;
	obj.open("chitti.txt"); //seekp(),tellp() are member functions of ofstream
                                 //seekg(),tellg() are not members,so Error
	obj.seekp(4,ios::beg);
        streampos x;   
        x=obj.tellp();
        obj.close();
#endif

#if 0
        ifstream obj1;
	obj1.open("chitti.txt"); //seekg(),tellg() are member functions of ifstream
                                 //seekp(),tellp() are not members,so Error
	obj1.seekg(4,ios::beg);
        streampos y;
        y=obj1.tellg();
        obj1.close();
#endif

}
