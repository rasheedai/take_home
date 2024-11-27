//
//  Ackermann.cpp
//  
//
//  Created by Rasheed Jeheeb on 11/25/24.
//

/*
Ackermann’s Function is a recursive mathematical algorithm that can be used to test how well a computer performs recursion.
Write a function A(m,n) that solves Ackermann’s Function. Use the following logic in your function:
If m=0 then return n+1
If n = 0 then return A(m-1, 1)
Otherwise, return A(m-1, A(m, n-1)
Test your function in a driver program that displays the following values: A(0, 0) A(0, 1) A(1, 1) A(1, 2) A(1, 3) A(2, 2) A(3, 2)
*/

using namespace std;
#include <iostream>

int Ackermann(int m, int n){
    if (m == 0) { return n+1;} // Base Case Conditional Statement
    
if (n == 0) {return Ackermann(m-1, 1);} // Base Case Conditional Statement

else {return Ackermann((m-1), Ackermann(m, n-1));};  // Base Case Default Condition
return 0;
    } // Function Definition
    
int main(){
   // int m,n ;
   /* cout << "Pick a value for m" << endl;
    cin >> m ;
     cout << "Pick a value for n" <<endl;
    cin >> n ;
    */
cout << Ackermann(0, 0) << endl;
cout <<Ackermann(0, 1) << endl;
cout <<Ackermann(1, 1)  << endl;
cout <<Ackermann(1, 2)  << endl;
cout <<Ackermann(1, 3)  << endl;
cout <<Ackermann(2, 2)  << endl;
cout <<Ackermann(3, 2) << endl;
   /* int mail;
     mail = Ackermann(m, n);
    cout << mail;
    */
    return 0; // Must Return 0
    } // Main Function 
