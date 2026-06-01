#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    string selected, computerChoice;
    string choices[] = {"Rock","Paper","Scissor"};

    srand(time(0));

    cout << "1. Rock\n" << "2. Paper\n" << "3. Scissor\n";

    int len = choices->length() - 1;

    cout << "Place enter your choice: ";
    cin >> selected;

    computerChoice = choices[rand() % len];

    auto present = find(begin(choices), end(choices), selected);

    cout << "Computer selected choice: " << computerChoice << endl;

    if (present != end(choices)) {
        if (selected == computerChoice) {
            cout << "Match Draw!" << endl;
        } else if (
        (selected == "Rock" && computerChoice == "Scissor") ||
        (selected == "Paper" && computerChoice == "Rock") ||
        (selected == "Scissor" && computerChoice == "Paper")
        ) {
            cout << "You Win!" << endl;
        } else {
            cout << "Computer Wins!" << endl;
        }
    } else {
        cout << "Please enter a vaild choice." << endl;
    }

    return 0;
}