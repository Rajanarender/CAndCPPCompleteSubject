Containers(Sequential,Associative) related Api's

Iterators:
----------
begin() -Return iterator to beginning  
end() -Return iterator to end  
rbegin() -Return reverse_iterator to reverse beginning  
rend() -Return reverse_iterator to reverse end  
C++11:
cbegin() -Return const_iterator to beginning  
cend() -Return const_iterator to end  
crbegin() -Return const_reverse_iterator to reverse beginning  
crend() -Return const_reverse_iterator to reverse end  

Capacity:
---------
size() -Return size  
empty() -Return true if container is empty or else false  
max_size() -Return maximum size  
resize() -Change size //Used by vector,deque 
capacity() -Return size of allocated storage capacity //Used by vector only  
reserve() -Request a change in capacity //Used by vector only 
C++11:
shrink_to_fit() -Shrink to fit  

Element access:
---------------
operator[] -Access element //Used by vector,deque,map only 
at() -Access element //Used by vector,deque,map only 
front() -Access first element  
back() -Access last element  
NOTE: set,multiset,unordered_set doesn't have Element access Api's
cout<<*it; //set
cout<<it->first; //map key
cout<<it->second; //map value

Modifiers:
----------
insert() -Insert elements  
erase() -Erase elements  
swap() -Swap content  
clear() -Clear content 
assign() -Assign container content //Used by All sequential containers (vector,deque,list,forward_list) 
push_back() -Add element at the end  
pop_back() -Delete last element  
push_front() -Add element at the beginning //Used by vector,deque only 
pop_front() -Delete first element  //Used by vector,deque only 
 
insert(make_pair(key,value)) -Insert elements in map 
insert(pair<keydatatype,valuedatatype>(key,value)) -Insert elements in map  
erase() -Erase elements
 
#if 1 //How to insert,erase in map
map<>m;
map<>::iterator it;
it = m.find(key);
m.erase(it); //Both key,value pair will be erased
m.insert(it->second,newvalue) //old value is replaced with new value
#endif

C++11:
emplace() -Construct and insert element  
emplace_back() -Construct and insert element at the end  
emplace_front() -Construct and insert element at beginning //Used by deque,list only

Operations: //Used by list,forward_list only
merge() -Merge sorted lists
sort() -Sort elements in container
reverse() -Reverse the order of elements 
unique() -Remove duplicate values
remove() -Remove elements with specific value 
remove_if() -Remove elements fulfilling condition 
splice() -Transfer elements from list to list //Used by list only

Operations: //Used by All Associative containers(set,map)
find() -Returns iterator to element
count() -Count elements with a specific value 
lower_bound() -Return iterator to lower bound 
upper_bound() -Return iterator to upper bound 
equal_range() -Get range of equal elements

#if 1 // Use this for all Associative containers
it =m.find(value); 
int value= m.count(value);
#endif

#if 1 //Use this for all Sequential containers
#include<algorithm> //Mandatory 
it =find(v.begin(),v.end(),value); 
int value= count(v.begin(),v.end(),value); 
#endif




