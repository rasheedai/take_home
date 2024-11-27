//
//  string_converter.cpp
//  
//
//  Created by Rasheed Jeheeb on 11/25/24.
//Write a program that accepts as input a sentence in which all of the words are run together but the first character of each word is uppercase. Convert the sentence to a string in which the words are separated by spaces and only the first word starts with an uppercase letter. For example, the string “HaveASafeHoliday.” would be converted to “Have a safe holiday.”

#include <string>
#include <iostream>
using namespace std;

string convertSentence(const string& talk){
        // Pass the given sentence by reference to change its value in memory
        string convertedString = " "  ;
        // Start with a blank string

        for (int i = 0; i < talk.length(); i++)
        {
    //    if (isupper(talk[0])){
    //        convertedString += " ";  // after it, put a space
      //      }
         if(isupper(talk[i])){  // a character of the string is uppercase
        convertedString += " ";  // after it, put a space
        convertedString += tolower(talk[i]); // Convert that letter to a lowercase
        }
        else {
        convertedString += talk[i];
        }
     
    }
    cout << convertedString;
    return convertedString;
};

int main(){
  
convertSentence("HelloWorld");
return 0;
}
