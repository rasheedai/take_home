//
//  dice_game.cpp
//  
//
//  Created by Rasheed Jeheeb on 11/25/24.
//

#include <iostream>
#include <string>
using namespace std;

class Player { // Class Declaration
    private: // Private Member Variables
        int score;
        string name;

    public: // Public Member Variables

    // Parameterized Constructor
    Player(string n) {
        name = n;
        score = 0;
    }

    // Constructor for the computer with default score
    Player() {
        name = "Computer";
        score = 0;
    }

    // Accessors
    string getName()
    { return name; }
    
    int getScore()
    { return score; }

    // Mutators
    void setScore(int s)
    { score = s; }

    // Dice roll
    int diceRoll() {
        int roll = (rand() % 6) + 1;  // Simulate Rolling Dice
        score += roll; // Increment Score Member Variable by Rolling
        return roll;
    }

    //  Display Function
    void printScore() {
        cout << name << "'s score: " << score << endl;
    }
};

void letsPlay(Player &player, Player &computer) { // Public Member Function
    string choice;
    bool end = false; // Flag Variable

    // Computer's Turn
    cout << "Computer's turn...\n";
    while (computer.getScore() < 18) // Access Private Variable through Public Functions
    {
        int roll;
        roll = computer.diceRoll();
        cout << "Computer rolled a " << roll << ". Total score: " << computer.getScore() << endl;
        if (computer.getScore() > 21) { // Conditional Statement
            cout << "Computer busts! You win!" << endl;
            end = true;
            break;
        }
    }

    // Player's turn
    while (!end) {
        cout << player.getName() << "'s current score is: " << player.getScore() << endl;
        cout << "Do you want to roll the dice? (Y/N): ";
        cin >> choice;

        if (choice == "Y") { // Conditional Statement
            int roll;
            roll = player.diceRoll();
            cout << player.getName() << " rolled a " << roll << ". Total score: " << player.getScore() << endl;
            
            if (player.getScore() > 21) { // Conditional Statement
                cout << player.getName() << " busts! Computer wins!" << endl;
                end = true;
                break;
            }
        }
        else if (choice == "N") { // Conditional Statement
            cout << player.getName() << " decided to stop rolling.\n";
            break;
        }
        else { // Default Case
            cout << "Invalid input! Please enter 'Y' to roll or 'N' to stop." << endl;
        }
    }

    // Final Results
    if (!end) {
        cout << "\nFinal scores:\n";
        player.printScore();
        computer.printScore();
        if (player.getScore() > computer.getScore() && player.getScore() <= 21) { //  Conditional Statement
            cout << player.getName() << " wins!" << endl;
        } else if (computer.getScore() > player.getScore() && computer.getScore() <= 21) {  // Conditional Statement
            cout << "Computer wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }
    }
}

int main() {
   

    // Create a player and computer objects of the Player class
    Player user("Player");
    Player computer;

    // Play the game
    letsPlay(user, computer);

    return 0;
}
