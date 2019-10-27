std::string class Api's

Iterators:
----------
begin() -Return iterator to beginning 
end() -Return iterator to end 
rbegin() -Return reverse iterator to reverse beginning 
rend() -Return reverse iterator to reverse end 
C++11:
cbegin() -Return const_iterator to beginning 
cend() -Return const_iterator to end 
crbegin() -Return const_reverse_iterator to reverse beginning 
crend() -Return const_reverse_iterator to reverse end 

Capacity:
---------
size() -Return length of string 
empty() -Return true if container is empty or else false  
length() -Return length of string 
max_size() -Return maximum size of string 
resize() -Resize string 
capacity() -Return size of allocated storage 
reserve() -Request a change in capacity 
clear() -Clear string
C++11: 
shrink_to_fit() -Shrink to fit 

Element access:
--------------
operator[] -Get character of string 
at() -Get character in string 
back() -Access last character 
front() -Access first character 

Modifiers:
---------
insert() -Insert into string 
erase() -Erase characters from string 
operator+= Append to string 
append() -Append to string 
push_back() -Append character to string 
pop_back() -Delete last character 
assign() -Assign content to string 

replace() -Replace portion of string 
swap() -Swap string values 


String operations:
c_str() -Get C string equivalent 
copy() -Copy sequence of characters from string 
find() -Find content in string 
rfind() -Find last occurrence of content in string 
find_first_of() -Find character in string 
find_last_of() -Find character in string from the end 
find_first_not_of() -Find absence of character in string 
find_last_not_of() -Find non-matching character in string from the end 
substr() -Generate substring 
compare() -Compare strings 

Member constants:
npos Maximum value for size_t (public static member constant )

Non-member function overloads:
operator+ -Concatenate strings 
operator== -relational operators(==,!= ,>=,<=)
operator>> -Extract string from stream 
operator<< -Insert string into stream 
swap() -Exchanges the values of two strings 
getline() -Get line from stream into string 
