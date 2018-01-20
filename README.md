li
==
li is a line-editor project.

Development Environment
-----------------------
* Operating System: Microsoft Windows 10
* Programing Language: C++

How to use
----------
* Modify makefile (Default is g++ in MinGW)
* Build
* Run li
	* Usage: `li <filename>`

commands
--------
* f  
print current filename

* w  
save to current file

* w [filename]  
save to a file

* e [lineno]  
edit a line

* r [lineno]  
remove a line

* i [lineno]  
insert a line to after a line

* es [lineno]  
edit lines after a line

* is [lineno]  
insert lines to after a line

* o  
open again current file

* o [filename]  
open a file

* p  
print all lines

* p [lineno]  
print a line

* p [from-lineno] [to-lineno]  
print lines

files
-----
* Source file
	* CommandProcess.cpp
	* commands.cpp
	* main.cpp
	* CommandLine.cpp
	* exception.cpp

* Header
	* extern.h
	* function.h
	* constant.h
	* class.h

* Other
	* .gitignore
	* LICENSE
	* makefile
	* README.md

History
-------
* 1.0 (January 20th, 2018)  
	* First version
