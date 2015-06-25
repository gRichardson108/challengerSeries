#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


bool isPalindrome(string input){
    int left = 0;
    int right = input.length() - 1;

    while (left < right){
        if (input.at(left) == input.at(right)){
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}

string reverseString(string input){
    char rev[input.length() + 1];
    string rep;

    int j = 0;
    for (int i = input.length() - 1; i >= 0; i--){
        rev[j] = input.at(i);
        j++;
    }
    rev[input.length()] = '\0';

    return string(rev);
}

int palindromeLen(string input){
    int length;
    int pos = input.length();
    string newString = string(input);
    string reverseSeg = input.substr(pos);
    newString.insert(0, reverseString(reverseSeg));
    //cout << newString << endl;
    while (!isPalindrome(newString)){
        //cout << pos << endl;
        if (pos < 0){
            break;
        }
        reverseSeg = reverseString(input.substr(pos--));
        //cout << "reversed seg: " << reverseSeg << endl;
        newString = string(input);
        newString.insert(0, reverseSeg);
        //cout << "newString: " << newString << endl;
    }

    return newString.length();
}

int main(){
    string input;

    getline(cin, input);

    cout << palindromeLen(input) << endl;

    return 0;
}
