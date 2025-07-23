#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void begin();
void game(string name);

string name = "";
int playerNumOfSoldiers = 0;
int computerNumOfSoldiers = 0;

int score = 0;

int main() { 
    srand(time(0));
    begin();
    cout << "Enter a name for your army: ";
    getline(cin >> ws, name);
    cout << "You are, " << name << endl;
    cout << "Ready to play?" << endl;
    system("PAUSE");
    game(name);
    return 0;
}

void begin() {
    cout << "***************************" << endl;
    cout << "* Welcome to 1D Simulator *" << endl;
    cout << "***************************" << endl;

    int choice;

    do {
        cout << "1. Play" << endl;
        cout << "2. About" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 2:
                cout << "You are in charge of an army. You wager the players, and play a game of rock-paper-scissors!" << endl;
                cout << "You choose how many soldiers to wager without knowing how many soldiers they have.\nWhoever loses all of their soldiers first loses." << endl;
                break;
            case 3:
                exit(0);
                break;
        }

    } while (choice != 1);
}

void game(string name) {
    system("cls");
    playerNumOfSoldiers = rand() % 1000 + 1;
    computerNumOfSoldiers = rand() % 1000 + 1;
    int wager = 0;
    char hand;
    
    // int wagerComputer = 0;
    // char handComputer;
    int wagerComputer = 0;
    int choiceComputer = 0;

    bool win = false;

    cout << "You have " << playerNumOfSoldiers << " soldiers to use!" << endl;

    do {
        cout << "Enter how many soldiers to wager: " << endl;
        cin >> wager;
        if (wager < playerNumOfSoldiers && wager > 0) {
            
        // if (wager > playerNumOfSoldiers) {

        // }
        cout << "Now choose, 'r' = Rock, 'p' = Paper, 's' = Scissors." << endl;
        cin >> hand;

        choiceComputer = rand() % 3 + 1;
        wagerComputer = rand() % computerNumOfSoldiers + 1;
        switch(choiceComputer) {
            case 1:
                if (hand == 'r') {
                    cout << "It's a tie!" << endl;
                }
                else if (hand == 'p') {
                    // cout << "You lose!" << endl;
                    cout << "You lost " << wager << " soldiers!" << endl;
                    playerNumOfSoldiers -= wager;
                }
                else {
                    // cout << "You win!" << endl;
                    cout << "You win " << wager << " score!" << endl;
                    cout << "Enemy lost " << wagerComputer << " soldiers!" << endl;
                    score += wager;
                    computerNumOfSoldiers -= wagerComputer;
                }
                break;
            case 2:
                if (hand == 'r') {
                    // cout << "You win!" << endl;
                    cout << "You win " << wager << " score!" << endl;
                    cout << "Enemy lost " << wagerComputer << " soldiers!" << endl;
                    score += wager;
                    computerNumOfSoldiers -= wagerComputer;
                }
                else if (hand == 'p') {
                    cout << "It's a tie!" << endl;
                }
                else {
                    // cout << "You lose!" << endl;
                    cout << "You lost " << wager << " soldiers!" << endl;
                    playerNumOfSoldiers -= wager;
                }
                break;
            case 3:
                if (hand == 'r') {
                    cout << "You lost " << wager << " soldiers!" << endl;
                    playerNumOfSoldiers -= wager;
                }
                else if (hand == 'p') {
                    cout << "You win " << wager << " score!" << endl;
                    cout << "Enemy lost " << wagerComputer << " soldiers!" << endl;
                    score += wager;
                    computerNumOfSoldiers -= wagerComputer;
                }
                else {
                    cout << "It's a tie!!" << endl;
                }
                break;
            default:
                cout << "Invalid Input!" << endl;
        }
    }
    else {
        cout << "Not enough soldiers" << endl;
    }
        cout << "Score: " << score << endl;
        cout << "Army: " << playerNumOfSoldiers << endl;
        cout << "Enemies: " << computerNumOfSoldiers << endl;

    } while (playerNumOfSoldiers > 0 && computerNumOfSoldiers > 0);

    
    cout << "The game has ended!" << endl;
    if (playerNumOfSoldiers <= 0) {
        cout << "You have lost!" << endl;   
    }
    
    if (computerNumOfSoldiers <= 0) {
        cout << "You have won!" << endl;
    }
    system("PAUSE");
}