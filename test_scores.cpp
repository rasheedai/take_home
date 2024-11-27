//
//  test_scores.cpp
//  
//
//  Created by Rasheed Jeheeb on 11/25/24.
//

/*Write a class for test scores. The class constructor should accept an array of test scores as its argument.
The class should have a member function that returns the average of the test scores.
If any test score in the array is negative or greater than 100, the class should throw an exception. Demonstrate the class in a program.
*/
#include <iostream>
#include <stdexcept>
using namespace std;

class TestScores {
private:
    double scores[100];  // Array Declaration
    int size;            // Number of test scores to be decided

public:
    // Parameterized Constructor
    TestScores(double inputScores[], int numScores) {
        size = numScores;
        // Input Validation
        for (int i = 0; i < size; i++) {
            if (inputScores[i] < 0 || inputScores[i] > 100) { // Conditional Statement
                throw invalid_argument("Test score must be between 0 and 100.") ; // Throw an Exception
            }
            scores[i] = inputScores[i];  // Array Initialization
        }
    }

    // Public Member Function
    double calculateAverage() const {

        double total = 0;
        double average = 0;
        for (int i = 0; i < size; i++) { // Iterating through the Array
            total += scores[i]; // Incrementing the Total
           
            average =  total / size; // Calculate
        }
        return average;  // Return the Average
    }

    // Display Function
    void displayScores() const {
        cout << "Test Scores: ";
        for (int i = 0; i < size; i++) { // Iterating through the Array
            cout << scores[i] << endl;
        }
    }
};

int main() {
    try { // Try
        int numScores;
        // Prompt
        cout << "Enter the number of test scores: " << endl;
        cin >> numScores; // Input

        // Input Validation
        if (numScores <= 0 || numScores > 100) {
            throw invalid_argument("The number of scores must be between 1 and 100."); // Throw an Exception
        }

        // Array Declaration
        double studentScores[numScores];

        // Prompt
        cout << "Enter the test scores (between 0 and 100): " << endl;
        for (int i = 0; i < numScores; i++) {
            cin >> studentScores[i]; // Input
            
            // Input Validation
            if (studentScores[i] < 0 || studentScores[i] > 100) {
                throw invalid_argument("Test score must be between 0 and 100."); // Throw an Exception
            }
        }

        // Create a TestScores Object
        TestScores student(studentScores, numScores);

        // Display
        student.displayScores();

        // Calculate the Average
        double average = student.calculateAverage();
        cout << "Average score: " << average << endl;
    }
    
    catch (const exception& e) {  // Catch Statement
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
