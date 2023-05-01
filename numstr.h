/*
 *Filename:	numstr.h
 *desciption:	numstr.h exports string to double and string to integer functions in addition to:
 *i.	providing support for fraction expressions such as "-781/345".
 *ii.	exception handling where invalid characters occur in the input string expression.
 *	"56r.67" will throw an exception, whereas, stod() and stoi() functions
 *	defined in stdlib will output 56.
 *iii.	returns round integers rather than truncating.	
 */

#ifndef _numstr_h
#define _numstr_h

#include <iostream>
#include <string>
#include <cmath>
#include <exception>


using namespace std;
/*
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
 */
double string_to_double(string);

/*
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
 */
int string_to_integer(string);

#endif
