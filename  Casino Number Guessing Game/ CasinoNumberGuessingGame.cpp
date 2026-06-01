#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void displayRules();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string playerName;
    double playerBalance = 0.0, bettingAmount = 0.0;
    int randomNumber, playerGuess, attempts = 5, diceValue = 0;
    char playAgain = 'n';
    bool isWinner = false;


    do {
        cout << "Enter your name: ";
        getline(cin, playerName);

        if (playerName.empty()) {
            cout << "Please enter your name to start the game." << endl;
        }
    } while (playerName.empty());
     

    do {
        cout << "Enter your deposit amount: " << endl;
        cin >> playerBalance;

        if(playerBalance <= 0) {
            cout << "Please enter a vailed amount greater then zero." << endl;
        }
    } while (playerBalance <= 0);

    do {
        displayRules();
        cout << "Your current balance is : $" << playerBalance << endl;

        do {
            cout << playerName << ", enter your betting amount ($): ";
            cin >> bettingAmount;

            if(bettingAmount <= 0) {
                cout << "Betting amount must be greater than zero.\n";
            } else if (bettingAmount > playerBalance) {
                cout << "You don't have enough balance.\n";
                cout << "Current balance is : $" << playerBalance << endl;
            }

        } while (bettingAmount <= 0 || bettingAmount > playerBalance);

        do {

            do {
                cout << "Guess a number between 1 to 10 to win the price." << endl;
                cout << "Enter your guess: ";
                cin >> playerGuess;

                if (playerGuess < 1 || playerGuess > 10) {
                    cout << "Invaild choice! Your guess should be between 1 to 10." << endl;
                }
            } while (playerGuess < 1 || playerGuess > 10);

            diceValue = (rand() % 10) + 1;

            if (diceValue == playerGuess) {
                double winnings = bettingAmount * 10;
                playerBalance += winnings;
                cout << "\n🎉 SUCCESS! You won $" << winnings << "!";
                isWinner = true;
                break;
            } else {
                attempts--;
                if (attempts > 0) {
                    cout << "You have " << attempts << " attempt";
                    if (attempts > 1) {
                        cout << "s";
                    }
                    cout << " left." << endl;
                } else {
                    playerBalance -= bettingAmount;
                    cout << "\n❌ Bad luck! You lost $" << bettingAmount << ".";
                }
            }

        } while (attempts > 0 && !isWinner);

        if (!isWinner) {
            cout << "\nYou've used all your attempts for this round.";
        };

        cout << "\nThe winning number was: " << diceValue << endl;
        cout << playerName << ", your remaining balance is: $" << playerBalance << endl;

        if (playerBalance <= 0) {
            cout << "\nYou have no money left to play! Game Over.\n";
            break;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    
    

    return 0;
}

void displayRules() {
    cout << "\n==================================================";
    cout << "\n          WELCOME TO THE CASINO WORLD             ";
    cout << "\n==================================================" << endl;
    cout << "Rules:" << endl;
    cout << "1. The computer will randomly select a number between 1 and 10." << endl;
    cout << "2. You have to guess the number." << endl;
    cout << "3. After each guess, the computer will tell you if your guess is too low, too high, or correct." << endl;
    cout << "4. You have a limited number of attempts to guess the number." << endl;
    cout << "5. If you guess the number within the allowed attempts, you win!" << endl;
    cout << "6. If you fail to guess the number within the allowed attempts, you lose." << endl;
    cout << "Good luck and have fun playing!" << endl;
}