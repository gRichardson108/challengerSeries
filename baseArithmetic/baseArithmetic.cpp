//Problem        : Base Arithmetic
////Language       : C++
////Compiled Using : g++
////Version        : GCC 4.9.1
////Input for your program will be provided from STDIN
////Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

char getMaxChar(string str){
    char max = 30;//corresponds to ASCII 0
    char c;
    for (int i = 0; i < str.length(); i++){
       char c = str.at(i);
       if (c > max){
          max = c;
       }
    }
    return max;
}

int getLowestBase(string str){
    int base;
    char max = getMaxChar(str);

    if ((max >= 48) && (max <= 57)){
        base = max - 47;//'0' is the 48th ASCII character
    } else if ((max >= 65) && (max <= 70)){
        base = max - 54;//uppercase letters start at 65 on the ascii table, decimal characters end at 57 with '9'
    } else {
        base = 0;//error state when not 2 <= base <= 16
    }
    
    return base;
}

//Converts the string to a decimal number, given the base that
//we want to convert the string from. Performs no error checking - assumes
//the string is in the correct format to be interpreted as the given base
int convertStringToDecimal(string str, int base){
    int sum = 0;
    int baseVal = 1;//which power the base is raised to. base^0 = 1
    int c;
    if (str.length() > 0){
        for (int i = str.length() - 1; i >= 0; i--){
            c = str.at(i);
            if (c == '\n'){
                break;
            }
            if ((c >= 48) && (c <= 57)){
                c = c - 48;
            } else if ((c >= 65) && (c <= 70)){
                c = c - 55;
            }

            c = (c * (baseVal));
            sum += c;
            baseVal = baseVal * base;//increase the exponent
        }
    }
    return sum;
}
                
            







int main() {
    string x_line;
    string y_line;

    getline(cin, x_line);
    getline(cin, y_line);

    /*

    cout << "max char in x: " << getMaxChar(x_line) << endl;
    cout << "lowest base in x: " << getLowestBase(x_line) << endl;
    cout << "as a decimal from the above base: " << convertStringToDecimal(x_line, getLowestBase(x_line)) << endl;
    cout << "max char in y: " << getMaxChar(y_line) << endl;
    cout << "lowest base in y: " << getLowestBase(y_line) << endl;
    cout << "as a decimal from the above base: " << convertStringToDecimal(y_line, getLowestBase(y_line)) << endl;

    cout << endl;*/

    cout << convertStringToDecimal(x_line, getLowestBase(x_line)) + convertStringToDecimal(y_line, getLowestBase(y_line)) << endl;


    return 0;
}
