
rootfs of linux
folders present in rootfs are
/bin --used for script(.sh) files
/dev
/etc --init process creation
/home
/root
/sys
/tmp
/lib
/usr
/var --used for having log/trace files

*******************************************************
man ASCII -command to get all ASCII values

To get the info about any command, use the following
=>man command //man stands for manual
=>command --help

cat test.cpp //We can view the file content without opening the file on the terminal itself
             //concatenate file and show it on the terminal 

:%s/s1/s2/g  //s stands for substitute s1[string to be replaced],s2[new string],g[globally through out the file]

vim xx.cpp    //vi editor
gcc xx.cpp    //gcc compiler
g++ xx.cpp    //gcc compiler
g++ xx.cpp -lpthread //Compiling cpp file having pthread

*******************************************************
g++ -shared -o a.o b.o -libxx.so //Creating dynamic/shared library
g++ xx.o -libxx.so Exe  //Dynamic Linking
./Exe

ar rcs a.o b.o -libxx.a //Creating static library
g++ xx.o -libxx.a Exe //Static Linking
./Exe

*******************************************************

chmod -R 777 .

//To display anything on the terminal,use echo
echo "Global\nEdge"
Global\nEdge

echo -e "Global\nEdge" //-e for enabling back slashes
Global
Edge

mkdir -p Dir1/Dir2/Dir3  //p stands for parent directories
//Here we can create all these directories using -p option

We can get the data of the file without opening it, data like count of[lines,words,bytes,characters]
wc [option] filename
wc test.cpp
linescount wordscount no.ofbytes 
wc -l test.cpp
linescount
wc -w test.cpp
wordscount
wc -c test.cpp
no.ofbytes
wc -m test.cpp
no.ofcharacters
**************************************************************************

Searches and Replace string with another string within a file,without opening it
sed -i 's/oldstring/newstring/' test.cpp //-i is edit file inplace,3slashes are mandatory,s for substitute 
sed -i "s/oldstring/newstring/" test.cpp 
sed -i s/oldstring/newstring/ test.cpp
//sed stands for StreamEditor

Search/Find the file in the same directory
find -iname "teSt.cpp" //iname indicates case insensitive
find -name 'test.cpp' //name indicates case sensitive

grep command - Used for searching Specified string in the list of files of directory
This commands displays each fileName with LineNumber where the specified string is present 

grep -nr "string" .  =>search in current directory //n is Number of the line,r is Recursively search
grep -nre "string" . //same as above

grep -nr "string" dir1/  =>search in particular directory
grep -nre "string" dir1/ //same as above

FYI: The above commands sed,find,grep does not need quotes
Single/Double/Without quotes anything is Ok

**************************************************************************
man commandname/functionname -This displays complete data of command like Description,Options,Arguments,Return type
NOTE: man means manual is used for commands and functions

commandname --help -This displays the options with description for commands only
NOTE: --help is used for commands only

ls -displays the list of all files without any format,sorting
ls -l -long list format[Permissions,ownername,size of file,timestamp[MON DD HH_24:MM],filename
ls -lt -long list format with timestamp in SORTED order[Newest first,Oldest last] 
ls -lrt -long list format with timestamp in REVERSE SORTED order[Oldest first,Newest last] 
ls -a -displays all hidden files/directories including .

wc -displays the count of words,lines,bytes/characters present in a file without opening the file
wc -l -linescount
wc -w -wordscount
wc -m -bytescount 

mkdir -creates directory
rmdir -removes directory
pwd -displays the path of present working directory 
rm -rf -removes directory
cd -Change directory
chmod -Change permissions of directory/file[chmod -R 777 directoryname]

chown -To change the ownername and groupname of a file
chown newownername xx.cpp
chown :newgroupname xx.cpp  
chown newownername:newgroupname xx.cpp  

cat -concatenates the files and prints on the console without opening the file
echo -prints the output on the terminal/console
touch -changes the timestamp of any file/directory to current timestamp[MON DD HH_24:MM]
tee -Reads the data and Writes it to any file [Use | operator]

cp -To copy files within one linux system
scp -To Secure copy files from one linux system to other
mv -To move/rename the files from one place to other

tar -zip file extraction,creation,view
tar -xvf test.tar //Used for extracting the files
x -extract,v- verbose showing the files progress during extracting,f -file Archieve

tar -cvf des.tar src
tar -cvf C++Programs.tar C++Programs -Here, we are creating the tar file

tar -tvf C++Programs.tar -displays the list of files present within the tar file

sudo -super user do[Admin permissions used for install,update,delete Applications]  
sudo apt-get install ApplicationName 

uname -prints system information 
uname -a  //a stands for all 
          //This prints kernel name,release date,version
          //prints H/w name,S/w OS name,Processor type

df -displays the disk file space of each partition[used,available space]
df -h //h stands for human readable format 
du -displays the disk usage of each file/directory[only used space]
du -sh //h stands for human readable format 

top -displays the list of processes with their PID,Status[R,S,T,Zombie],CPU,RAM utilization,etc
R -Running,S -Sleeping,T -Stop
top -H -diplays the list of threads
top also gives info about CPU spend time on userspace,kernelspace,H/w Interrupts,S/W Interrupts,etc
NOTE: top displays all these features dynamically

ps -displays the list of Running processes only
ps -ef
NOTE: ps display is static 

head filename.cpp -Displays the first 10 lines of file by default

head -n N filename.cpp -Diplays the first n lines of file

tail filename.cpp -Displays the last 10 lines of file by default

tail -n N filename.cpp -Diplays the last n lines of file

tail -f filename.cpp -To view the content of the log files that keep growing //V.V.Imp
-----------------------------------------------------------------------------------------------------------------------------

search commands:

locate -Searches and displays the location/path of the file with specified name in any directory[path starts from rootfs] 
NOTE: This searches only filenames and not strings

find -Searches and displays the location/path of the file with specified name in same directory[path starts from current directory] 
find -name filename.c
find -iname filename.c [i means case insensitive]

grep -nr -Searches the string and displays the lines of files having the specific string within that directory only
NOTE: grep searches in specified directory only

sed -Searches and Replace string with another string within a file,without opening it
sed -i 's/oldstring/newstring/' test.cpp //-i is edit file inplace,3slashes are mandatory,s for substitute 

-----------------------------------------------------------------------------------------------------------------------------
ifconfig -To see the configuration of N/w interface on Linux system



