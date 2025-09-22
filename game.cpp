#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Get computer move randomly
char getComputerMove() {
    int move;
    srand(time(NULL));
    move = rand() % 3;
    if (move == 0) return 'r'; // Rock
    else if (move == 1) return 'p'; // Paper
    return 's'; // Scissors
}

// Determine the result of the game
int getResults(char playerMove, char computerMove) {
    if (playerMove == computerMove) return 0; // Draw

    if ((playerMove == 'r' && computerMove == 's') ||
        (playerMove == 'p' && computerMove == 'r') ||
        (playerMove == 's' && computerMove == 'p')) {
        return 1; // Player wins
    }
    return -1; // Computer wins
}

int main() {
    char playerMove;
    cout << "Welcome to Rock Paper Scissors Game!" << endl;
    cout << "Enter r for Rock, p for Paper, s for Scissors: ";

    while (true) {
        cin >> playerMove;
        if (playerMove == 'r' || playerMove == 'p' || playerMove == 's') break;
        cout << "Invalid input! Please enter r, p, or s: ";
    }

    char computerMove = getComputerMove();
    int result = getResults(playerMove, computerMove);

    if (result == 0) cout << "Game is a Draw!" << endl;
    else if (result == 1) cout << "Congratulations! You won!" << endl;
    else cout << "Computer wins! Try again." << endl;

    cout << "Your Move: " << playerMove << endl;
    cout << "Computer's Move: " << computerMove << endl;

    return 0;
}
