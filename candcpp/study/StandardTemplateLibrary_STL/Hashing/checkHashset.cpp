// CPP program to find the first repeated character in a string

#include<iostream>
using namespace std;
#include<unordered_set> 

// Returns first repeating character in str.
char firstRepeating(string &str)
{
    unordered_set<char> h;// Creates an empty hashset
 
    for (int i=0; i<str.length(); i++)
    {
        if (h.find(str[i]) != h.end())
            return str[i];
        else // Else add element to hash set
            h.insert(str[i]);
    }
 
    return '\0'; // If there is no repeated character
}
 
int main ()
{
    string str = "geeksforgeeks";
    cout << firstRepeating(str)<<endl;
    return 0;
}
