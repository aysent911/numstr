 *numstr.h
 *exports string to double and string to integer functions in addition to:
 *i	providing support for fraction expressions such as "-781/345".
 *ii.	exception handling where invalid characters occur in the input string expression.
 *	"56r.67" will throw an exception, whereas, stod() and stoi() functions
 *	defined in stdlib will output 56.
 *iii.	returns round integers rather than truncating.	
 *
 *
 *Function_name:string_to_double
 *Example:	double x = string_to_double(str)
 *str can be any string expression of the form:
 *"+567.4566"	positive decimal
 *"-120,687"	negative decimal, comma (,) is treated as a decimal point like (.)
 *"-49"		negative integer
 *"3001"	positive integer
 *"821/503"	positive fraction
 *"-185/761" 	negative fraction
 *any other character witthin the string will throw an exception
 *
 *
 *Function_name:string_to_integer
 *Example:	integer y = string_to_integer(str)
 *str can be any string expression of the form:
 *"+567.4566"	positive decimal
 *"-120,687"	negative decimal, comma (,) is treated as a decimal point like (.)
 *"-49"		negative integer
 *"3001"	positive integer
 *"821/503"	positive fraction
 *"-185/761" 	negative fraction
 *any other character witthin the string will throw an exception
 *returns rounded integer.
 *
 *numstr.cpp
 *Contains definition of string_to_double(str) and string_to_integer(str).
 
 *example.cpp
 *illustrates usage of string_to_double(str) and string_to_integer(str) functions.
 *This program continually converts user-provided string on console to a double and a rounded integer.
 *To stop, enter 'X' or 'x'.
 *
 *Makefile
 *Build script for the example.cpp project
 *How To Use
 1.copy numstr.h to system include folder (/usr/include on debian)
 2.open terminal in the numstr directory
 3.run make
 4.run ./example.x
