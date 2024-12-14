/*
Title: Chapter 7 Rock Paper Scissors Part 2
File Name: CHapter7_RPS2_Cody_Drumheller.cpp
Programmer: Cody Drumheller
Date: 20241213
Requirements:
Revise the Rock Paper Scissors  using an array  to store multiple games each with the best score for each player.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_GAMES = 5;
const int USER = 0;
const int COMPUTER = 1;

int getComputerChoice();
int getUserChoice();
void displayChoice(int choice);
void determineWinner(int userChoice, int computerChoice, int& userScore, int& computerScore);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int scores[MAX_GAMES][2] = { 0 };
    int gameIndex = 0;

    while (gameIndex < MAX_GAMES) {
        int userScore = 0, computerScore = 0;
        int computerChoice, userChoice;

        cout << "\nGame " << (gameIndex + 1) << ":\n";

        do {
            computerChoice = getComputerChoice();
            userChoice = getUserChoice();

            cout << "Computer chose: ";
            displayChoice(computerChoice);
            cout << "You chose: ";
            displayChoice(userChoice);

            determineWinner(userChoice, computerChoice, userScore, computerScore);
        } while (userChoice == computerChoice);

      
        scores[gameIndex][USER] = userScore;
        scores[gameIndex][COMPUTER] = computerScore;

        cout << "\nFinal scores for Game " << (gameIndex + 1) << ":\n";
        cout << "User: " << userScore << " | Computer: " << computerScore << "\n";

        gameIndex++;
    }


    cout << "\nOverall Scores:\n";
    for (int i = 0; i < MAX_GAMES; ++i) {
        cout << "Game " << (i + 1) << " - User: " << scores[i][USER]
            << " | Computer: " << scores[i][COMPUTER] << "\n";
    }

    return 0;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

int getUserChoice() {
    int choice;
    cout << "Enter your choice:\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1 (Rock), 2 (Paper), or 3 (Scissors): ";
        cin >> choice;
    }

    return choice;
}

void displayChoice(int choice) {
    switch (choice) {
    case 1:
        cout << "Rock\n";
        break;
    case 2:
        cout << "Paper\n";
        break;
    case 3:
        cout << "Scissors\n";
        break;
    }
}

void determineWinner(int userChoice, int computerChoice, int& userScore, int& computerScore) {
    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
        (userChoice == 3 && computerChoice == 2) ||
        (userChoice == 2 && computerChoice == 1)) {
        cout << "You win this round!\n";
        userScore++;
    }
    else {
        cout << "Computer wins this round!\n";
        computerScore++;
    }
}











