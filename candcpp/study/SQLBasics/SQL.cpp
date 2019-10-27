This is case-insensitive language,we can use upper or lower case letters

SQL - Structured Query Language
PL/SQL -Procedural Language

SQL comment Lines
1.single line comments is two hyphens (--)
2.multiple line comments is slash and an asterisk (/* */)

/********************
SHORTCUT
QSSCJF -This is fine
********************/

NFSCSJSD
Normalization forms -Not necessary
Functions[single row functions(single row i/p,single o/p),multiple row functions(multiple row i/p,single o/p)]
Statements[DDL,DML,DRL,DCL,TCL]
Constraints[primary key,foreign key]
Subqueries[query within another query]
Joins[inner/self join,outer join(left,right,full)] - We are joining the tables 
Set operators[intersect,union,union all, minus]
Data types[number,char,varchar(),varchar2()]

Databases:
RDBMS[Relational DataBase Management System] -Oracle works on this
NDBMS[Network]
ODBMS[Object Oriented]

/*************************************************************
plsql topics: BCTVIE
unnamed blocks[declare,begin,end],named blocks[functions,procedures,packages]
cursors,triggers,views,indexes,exception handling
*************************************************************/

Any of 3 cases can be used  
SELECT sal from emptbl; //Select is case-insensitive
SelEcT sal from emptbl;
select sal from emptbl;

select rownum,rowid from emptbl; //rownum,rowid are internal attributes for any database table V.Imp
select upper('Raja') from dual; //RAJA,dual is the dummy table V.Imp
----------------------------------------------------------------------------------------------------------------------

distinct keyword: V.V.Imp
select distinct sal from emptbl; //displays the unique salaries, duplicates are eliminated

select max(sal) from emptbl; //Finding the 1st Highest salary with duplicates
select distinct max(sal) from emptbl; //Finding the 1st Highest salary without duplicates
                                      //distinct is mandatory,V.V.Imp                                
//Finding the 2nd Highest salary,V.V.Imp
//select max(sal) from emptbl where sal<max(sal); //Error,Cannot use Aggregate functions in WHERE clause
select max(sal) from emptbl where sal< (select distinct max(sal) from emptbl); //Use subquery to avoid Error
                                                                               //distinct is mandatory,V.V.Imp

select employee,max(sal) from emptbl group by dept; //displays the max salaried employee of each dept

V.V.Imp
nvl -null value functions
nvl(Nullcolumn,value);
nvl2(Nullcolumn,value1,value);
decode(specificcolumn,specificcolumnvalue,value1,value2);

select nvl(salary,0) "REVISEDSALARY" from emptbl; //replace the columns having empty/null salary with 0
select nvl2(salary,100,0) "REVISEDSALARY" from emptbl; //replace the columns having empty/null salary with 0 and non-empty with 100
select decode(salary,100,10,20) "REVISEDSALARY" from emptbl; //replace the columns having salary=100 with 10 else with 20

select decode(NULL,NULL,'MATCH,'NOTMATCH') from dual; //o/p is 'MATCH',this is wrong since NULL cannot be compared with NULL 
//To resolve the above error use "case" 
------------------------------------------------------------------------------------------------------------------------

Select * from Employee where Rownum = n; //displays the nth record
//Select * from Employee where Rownum = max(Rownum); //Error,Aggregate functions should not be used in where clause
Select * from Employee Where Rownum/Rowid = (Select max(Rownum/Rowid) from Employee); //displays the last nth record

Select * from Employee Where Rownum <= n; //displays the first n number of records
Select * from (Select * from Employee ORDER BY Rownum DESC) Where Rownum <= n; //displays the last n number of records ,V.V.Imp,Subquery

What is the difference b/w nvl and nvl2 functions?
nvl(exp1,exp2) --If exp1 is NULL,then it returns exp2 or else exp1
nvl2(exp1,exp2,exp3) --If exp1 is NULL,then it returns exp3 or else exp2

How to create a Backup table/duplicate table from the original table?
create table dupemp_tbl as select * from emp_tbl //Here column names and all records are copied
             (or)
create table dupemp_tbl as select * from emp_tbl where 1=1 //1=1 means true condition

How to create a Backup table/duplicate table from the original table with same structure/same columnns but no data ?
create table dupemp_tbl as select * from emp_tbl where 1=2 //Here column names are only copied, records are not copied
                                                           //1=2 means false condition

select * from Emp1 INTERSECT Select * from Emp2; //Displays the common records present in both tables emp1,emp2
Select * from Emp1 UNION Select * from Emp2; //displays the unique records of both tables Emp1,Emp2 
Select * from Emp1 UNION ALL Select * from Emp2; //displays the records of both tables Emp1,Emp2 including duplicates
Select * from Emp1 MINUS Select * from Emp2; //displays the records of Emp1 that are not present in Emp2

////////////////////////////////////////////
V.V.Imp 
int x =10; //C style of variable declaration
x number := 10 //SQL variable declaration

char y = 'Global'
y char := 'Global'
////////////////////////////////////////////

SQL aggregate functions:
SUM(columnname) // returns the sum of all values present in that column
MIN(columnname) //returns the min column value 
MAX(columnname) // returns the max column value
AVG(columnname) // returns the avg value
COUNT(columnname) // returns the number of records
FIRST(columnname) // returns the first value of the column
LAST(columnname)  // returns the last value of the column

SELECT *
FROM orders
WHERE order_id = 100
OR order_id = 101
OR order_id = 102;

Keywords //V.V.Imp
In
NOT In
Exists
Like

Select * from orders where order_id in (100,101,102) //We can avoid using multiple OR's using IN clause
Select employee from emp_tbl where location in ('hyderabad','bangalore','chennai') 
Select employee from emp_tbl where location NOT in ('hyderabad','bangalore','chennai')
Select employee from emp_tbl where companyname IN ('GlobalEdge')
          (or)
Select employee from emp_tbl where companyname = 'GlobalEdge'

Select employee from emp_tbl where companyname IN ('GlobalEdge','ALTRAN') //If we want to check with 2 or more names then should use IN 

//string is Global
select employee from emp_tbl where emp LIKE 'G%' //displays emp starting with G 
select employee from emp_tbl where emp LIKE '%l' //emp ending with l
select employee from emp_tbl where emp LIKE 'G%l' //emp starting with G and ending with l
select employee from emp_tbl where emp LIKE '%ba%' //emp having letters in b/w as 'ba'
 
select employee from emp_tbl where emp NOT LIKE 'G%' //emp not starting with G 

Given a table with Annualsalary of each employee,How to get the monthly salary of each employee
select empname,annualsalary/12 from emp_tbl //V.Imp

select *,rownum from emp_tbl where mod(rownum,2) =0 //displays even rownum records
select *,rownum from emp_tbl where mod(rownum,2) =1 //displays odd rownum records

select * from emp_tbl where to_char(joiningdate,'YYYY') = '2018' //Joining date using typecasting,V.Imp

constraints:
primary key -This is only one key in table ,unique and not null
foreign key
not null
unique
check(columnname > value)
default 'GLOBAL' 

create table emp(col1 number constraint col1_pk primary key,
                 col2 varchar2(10))

create table emp(col1 number ,
                 col2 varchar2(10)
                 constraint col1_pk primary key(col1));

create table emp(col1 number ,
                 col2 varchar2(10)
                 constraint col1_pk primary key(col1,col2)); //Composite Primary Key

ALTER table emp //Adding constraint to a column after table creation
ADD constraint col1_pk primary key(col1);

ALTER table emp //Droping/enabling/disabling constraint to a column after table creation
DROP/ENABLE/DISABLE constraint col1_pk //No need to specify the constraint

FOREIGN Key:
This establishes the relationship b/w 2tables.
This is the key in child table which points to Primary key of another table 

NOTE:Foreign key column and Primary key column should have same data type with same size.
Once the foreign key references to primary key , you cannot delete that Primary key COLUMN of the parent table.

create table orders(col number constraint col1_fk FOREIGN Key references emp(col1),
                    col2 varchar2(10))

create table orders(col number ,
                    col2 varchar2(10)
                    constraint col1_fk FOREIGN key(col) references emp(col1));


Foreign key in child table references(points) to Primary key in parent table
Now if we delete the record in parent table,then what should happen to the records in child table??

ON DELETE CASCADE //Foreign key record gets deleted on deleting the primary key record
ON DELETE SET NULL //Foreign key record gets NULL  on deleting the primary key record
Example:
create table orders(col number ,
                    col2 varchar2(10)
                    constraint col1_fk FOREIGN key(col) references emp(col1) ON DELETE CASCADE);

create table orders(col number ,
                    col2 varchar2(10)
                    constraint col1_fk FOREIGN key(col) references emp(col1) ON DELETE SET NULL);
-------------------------------------------------------------------------------------------------------------
Difference b/w Primary Key and Foreign Key
Primary Key                                                      Foreign Key
1.This cannot be NULL                                          This can be NULL
2.Should be Unique, I mean no Duplicates allowed               Duplicate Foreign keys are allowed 
3.Only one Primary Key is allowed in a Table                   Can contain many Foreign keys in a Table
4.This adds a Clustered INDEX Automatically                    This doesnot add any Clustered INDEX Automatically,V.V.Imp
-------------------------------------------------------------------------------------------------------------

alias: Giving another name to the column,table

select E.col1 from emptbl as E; //Table alias
select E1.col1,E2.col2 from emptbl1 as E1,emptbl2 as E2;
select col1 as A, col2 as B from emptbl where emptbl.A=emptbl.B; //Column alias

Joins: This is used to display the records of 2 tables
inner join //similar to intersection
left join/left outer join
right join/right outer join
full outer join //similar to union
self join //No syntax,V.V.Imp

syntax:
=>table1 Join table2 on condition
select tbl1.col1,tbl2.col2 from tbl1 INNER/LEFT OUTER/RIGHT OUTER/FULL OUTER JOIN tbl2 On tbl1.col1=tbl2.col2;

Inner join: Joining 2 tables with matching records of both tables
eg:
select emp1.orders,emp2.customers from emp1 inner join emp2 on emp1.orders=emp2.customers;

Left outer join: Joining 2 tables with all records of left table and matching records of right table
eg:
select emp1.orders,emp2.customers from emp1 left join emp2 on emp1.orders=emp2.customers;

Right outer join: Joining 2 tables with all records of right table and matching records of left table
eg:
select emp1.orders,emp2.customers from emp1 right join emp2 on emp1.orders=emp2.customers;

Full outer join: Joining 2 tables with all records of both tables
eg:
select emp1.orders,emp2.customers from emp1 full outer join emp2 on emp1.orders=emp2.customers;

self join: Joining the columns within the same table itself
select e1.col1,e2.col2 from emp1 as e1,emp1 as e2 where e1.col1=e2.col2; 

*************************************************************************************
V.V.Imp
Query to find employee Name with their corresponding Manager Name,
Given a table Emp with empid,Name,Mgrid
Ans:
select A.Name as EmployeeName,B.Name as ManagerName from Emptbl as A,Emptbl as B where A.sapid=B.sapid;
select A.Name as EmployeeName,B.Name as ManagerName from Emptbl as A inner join Emptbl as B On A.sapid=B.sapid;
*************************************************************************************
V.V.Imp
Statements are of 5 types:
DDL -Data Definition Language
DML -Data Manipulation Language
DRL -Data Retrieval Language
DCL -Data Control Language
TCL -Transaction Control Language

DDL statements: //Keyword 'Table' should be used 
create
alter(ADD,DROP/ENABLE/DISABLE/ALTER/RENAME)
Truncate

ALTER table emptbl
ADD COLUMN sal varchar(2); //Adding New column sal of datatype varchar

ALTER table emptbl
Drop COLUMN sal; //Delete column

ALTER table emptbl
RENAME COLUMN sal TO salary; //Renaming the existing column name with new column name

ALTER table emptbl
ALTER COLUMN sal varchar(6); //changing the column datatype or its size

TRUNCATE table emptbl; //deletes only the records

DROP table emptbl; //deletes the complete table(records,structure)

DML statements:
insert into emptbl(col1,col2) values(20,'Global') //If we want to insert only specified columns 
insert into emptbl values(20,'Global','Mailasandra') //If we want to insert a new record/row completely

update emptbl set emp='Raja' where emp='Damu'

delete colname from emptbl //It will delete the column
delete from emptbl where name='Global' //It will delete the entire record 

DCL statements:
grant //Giving the permissions on the table to other user, so that he can make changes
revoke //Taking the permissions on the table from other user, so that he can make changes

syntax:
GRANT/REVOKE <list of commands> ON tablename TO/FROM username; --this we have to give from owner's login

GRANT insert on emptbl to Damu
GRANT select,insert,update,delete ON emptbl tO Damu
      (or)
Grant All ON emptbl TO damu;  --Giving all permissions to user

REVOKE insert on emptbl from Damu
REVOKE select,insert,update,delete ON emptbl from Damu
      (or)
REVOKE All ON emptbl from damu;  --Giving all permissions to user

TCL statements: //This statements should be used after Each DML statement
commit //When we make any manipulations on the table, this changes need to get reflected from buffer to server
rollback //The data from server will replace with that of buffer

*********************************************************************************************
DRL statements:
SELECT colname from tablename
where filtercondition
GROUP BY colname
HAVING filtercondition   //Accepts only Aggregate functions like sum(),min(),max(),avg(),count()
ORDER BY colname ASC/DESC //Default is ASC

*********************************************************************************************
V.V.Imp
Group by : This is used to group/arrange all similar groups present in column in Alphabetical format
Having: This is a filter condition used for aggregate functions
Ex: 
select name from emptbl group by name
select name,max(sal) from emptbl group by name having max(sal) 
NOTE:Whatever columns we use in group by,having -we have to use them in select,V.V.Imp 
*********************************************************************************************
V.Imp
Subquery:
Co-related subquery: inner query depends on outer query
select col1 from emp1 where col1 = (select col2 from emp2 where emp1.col1=emp2.col2);

Non Co-related subquery: inner query does not depend on outer query
select max(sal) from emptbl where sal < (select max(sal) from emptbl);

select (subquery) 
from (subquery) //Used for getting last n rows
where col>(subquery) //Used for getting 2nd Max salary

Set Operators: 
These are used to combine the Rows returned by 2 or more SELECT queries.
Condition:Both the tables should have same number of columns in same order with same data type.

4 types:
UNION
UNION ALL
INTERSECT
MINUS

UNION: //only unique
This Set operator returns the rows/records of both the tables eliminating duplicates.
syntax:
SELECT * FROM tablename1
UNION
SELECT * FROM tablename2

UNION ALL: //includes duplicates
This Set operator returns the rows of both the tables including duplicates.
syntax:
SELECT * FROM tablename1
UNION ALL
SELECT * FROM tablename2

INTERSECT: //only common records
This returns only the common rows of both the tables.

syntax:
SELECT * FROM tablename1
INTERSECT
SELECT * FROM tablename2

MINUS: 
This eliminates the common rows b/w 2 tables and returns only the left out rows of 1st table.
syntax:
SELECT * FROM tablename1
MINUS
SELECT * FROM tablename2

Views:
Generally whenever we execute a query of a TABLE,the database is being hit as many times as query is executed 
leading to decrease in database performance
So instead of using TABLE, We can Create a VIEW similar to that of TABLE and execute the query.
So, when we run this query of a VIEW,the database gets hit only once in a session and 
from next time onwards, the query gets the data from cache memory only thereby avoiding the Hitting to Database.

Simply we can say that VIEW is an alternate for Table,protecting the DB from multiple Hits.

CREATE VIEW raj_vw AS
SELECT col,count(col) FROM Emp group by col having count(col); //Instead of writing this query multiple times, it is btr to create a view for it

select * from raj_vw; //Query using view

Indexes: 
Generally indexes are used in text books to search for certain topic faster 
similarly indexes in table are used on columns to search data faster.
These are applied on Columns to make search and data retrieval faster in that column.
By default, index sets the column in ASCending order.Indexes are useful in Performance Tuning.
Indexes use B-Tree(Binary Tree) for making searching faster.

Note:
Any Primary key is indexed by default.
Column containing index is called as Index Key.

Types:
Simple/Non-unique Index
Reverse Index //Use REVERSE keyword
Composite Index
Unique Index //Use UNIQUE keyword
Function Based Index
Clustered Index //Use CLUSTERED keyword

Simple/Non-unique Index: Creating index on single column,this column can have duplicte and NULL values
create index emp_idx  
ON emp_tbl(col1);

Function based index: Creating index on functions holding columns
create index emp_idx
ON emp_tbl(UPPER(col1));

Reverse index: This sets the columns in reverse(desc) order,generally indexes will be in asc order
create index emp_idx  
ON emp_tbl(col1) REVERSE;

Composite index: Creating index on 2 or more columns
create index emp_idx
ON emp_tbl(col1,col2);

Unique index: Creating index on Primary or Unique key
create unique index emp_idx
ON emp_tbl(col1);

Clustered index: This stores the data of the table in Leaf nodes of Binary Tree
Primary key has clustered index by default,Only one clustered index exists for a table
create clustered index emp_idx
ON emp_tbl(col1);
*********************************************************************************************














 









