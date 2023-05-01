#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <numstr.h>

using namespace std;

class bad_input: public exception{
 public:
 virtual const char * what() throw() {
   return "Input is invalid! ONLY (+|-|)(0-9)*(.|,|/)(0-9)* is accepted!";
 }
}bad_one;
double string_to_double(string input_string){
  double output_real=0;
  int state=0;
  int index=0;
  try{ /*this  method uses NFA of 6 states 0-5 to validate the expression.*/
    if((input_string[0]=='-')||(input_string[0]=='+')){
      state=1;  /*if expression starts with sign transit from state 0 to 1*/
    }else if((input_string[0]>='0')&&(input_string[0]<='9')){
      input_string="+"+input_string;
      state=1; /*if no sign insert + at the beginning to sign it*/
      //cout<<input_string<<endl; /*test point 1*/
    }
    if(state==1){ /*transit to 2 if state is 1 and character read is digit*/
      for(index=1;(input_string[index]>='0')&&(input_string[index]<='9')
       &&(index<(int)input_string.length());index++){
        state=2; /*loop in state 2 until end of stream of digits*/
        output_real=output_real*10 +(input_string[index]-'0');
      }
    }
    if((state==2)&&(index==(int)input_string.length())){
      state=3; /*if string ends at state 2, transit to 3 and accept*/
      //cout<<"state "<<state<<endl; /*test point 2*/
      if(input_string[0]=='-'){ output_real*=-1;}
      //cout<<output_real<<endl; /*test point 3*/
      return output_real;
    }else if((state==2)&&((input_string[index]=='.')||(input_string[index]=='/')
     ||(input_string[index]==','))){
      int decimal_place=index;
      int whole_part = output_real;
      int fraction_part=0;
      index++; /*advance to next character in the expression*/
      for(index=index;(input_string[index]>='0')&&(input_string[index]<='9')
       &&(index<(int)input_string.length());index++){
        state=4; /*transit to state 4 if symbol after ',', ',' or '/'* is digit*/
       /*loop in state 4 until end of digit stream*/
        if(input_string[decimal_place]=='/'){ /*operate fraction input*/
          fraction_part=fraction_part*10 +(input_string[index]-'0');
          output_real=whole_part/(double)fraction_part;
        }else{  /*both '.' and ',' are decimal points*/
          output_real=output_real+(input_string[index]-'0')*pow(0.1,(index-decimal_place));
        }
      }
    }
    if((state==4)&&(index==(int)input_string.length())){
      state=5; /*if string ends at state 4, transit to 5 and accept*/
      //cout<<"state "<<state<<endl; /*test point 4*/
      if(input_string[0]=='-'){ output_real*=-1;}
      return output_real;
    }else{
      throw bad_one;  /*if is not accepted throw exception of bad_input type*/
    }
  }
  catch(bad_input& ex){
    output_real=0;     //if input is invalid zero is returned.
    cout<<ex.what()<<endl;
  }
  catch(...){
    output_real=0;     //if input is invalid zero is returned.
    cout<<"Unknown exception!"<<endl;
  }
  return output_real;
}
int string_to_integer(string input_buffer){
  return round(string_to_double(input_buffer));
}
