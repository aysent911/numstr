#include <iostream>
#include <string>
#include <numstr.h>

using namespace std;

int main()
{/*This program continually converts user-provided string on console
to a double and a rounded integer.To stop, enter 'X' or 'x'.*/
    string input_string;
    double output_double;
    int output_integer;
    bool loop = true;
    while(loop){
      cout<<"Enter a string of numbers(Key in X to exit):";
      getline(cin, input_string);
      if((input_string=="X")||(input_string=="x")){
        loop =false;
        cout<<"THANK YOU FOR TESTING ME, BYE! BYE!"<<endl;
      }else{
        output_double=string_to_double(input_string);
        output_integer=string_to_integer(input_string);
        cout <<"Double:"<<output_double<< endl;
        cout <<"Integer:"<<output_integer<< endl;
      }
    }
    return 0;
}
