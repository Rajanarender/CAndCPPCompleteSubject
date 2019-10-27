
Inheritance - Is a Relationship
Aggregation - Has a Relationship 
Association - uses of Relationship
Composition - consists of Relationship

Inheritance:[Is A Relationship]
One class having the features of the other
It is Relationship b/w 2 classes in which one class depends on the other with Single Ownership[Base class]
Dependency: Yes
Ownership: Yes
UML Representation: Solid Line with Solid Arrow 
Example:
Vehicle - 2wheeler,4wheeler
2Wheeler,4wheeler will have all features of Vehicle

Association:[Independent]
It is Relationship b/w 2 classes in which one class does not depend on the other
Dependency: NO
Ownership: NO
UML Representation: Solid Line
FYI:Relationship can be of type one to one,one to many,many to one,many to many
Example:
Teacher and Student
Teacher can be associated with multiple Students
Student can be associated with multiple Teachers
Teacher will exist without Student and vice-versa

Aggregation:[Independent],[Has A Relationship]-Nested class
It is a Special form of Association
It is Relationship b/w 2 classes in which one class does not depend on the other with Single Ownership
Dependency: NO
Ownership: Yes
UML Representation: Solid Line with Hollow Diamond 
Example: 
Car has Stirring,Brakes,tyres,lights
Car is the owner for all this parts

Composition:[Dependent]
It is a Restricted form of Aggregation,due to dependency
It is Relationship b/w 2 classes in which one class depends on the other with Mutual Ownership
Dependency: Yes
Ownership: Yes
UML Representation: Solid Line with Solid Diamond 
Example: 
House with Rooms
House doesnot exist without Rooms and Rooms doesnot exist without House

Dependency:
It is Relationship b/w 2 classes in which one class depends on the other for Implementation with Mutual Ownership
Dependency: Yes
Ownership: Yes
UML Representation: Dashed Line with Solid Arrow 
Example: 
Client-Server system
Client depends on Server for implementing its functionalities













