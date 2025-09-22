#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// ANSI color codes for text
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

// Get computer move randomly
char getComputerMove() {
    int move;
    srand(time(NULL));
    move = rand() % 3;
    if (move == 0) return 'r'; // Rock
    else if (move == 1) return 'p'; // Paper
    return 's'; // Scissors
}

// Emoji for each move
string emojiForMove(char move) {
    switch (move) {
        case 'r': return "🪨"; // Rock emoji
        case 'p': return "📄"; // Paper emoji
        case 's': return "✂️"; // Scissors emoji
    }
    return "";
}

// Determine the result of the game
int getResults(char playerMove, char computerMove) {
    if (playerMove == computerMove) return 0; // Draw
    if ((playerMove == 'r' && computerMove == 's') ||
        (playerMove == 'p' && computerMove == 'r') ||
        (playerMove == 's' && computerMove == 'p'))
        return 1; // Player wins
    return -1; // Computer wins
}

int main() {
    char playerMove;
    cout << BLUE << "Welcome to Rock Paper Scissors Game! " << RESET << endl;
    cout << YELLOW << "Enter r for Rock, p for Paper, s for Scissors: " << RESET;

    while (true) {
        cin >> playerMove;
        if (playerMove == 'r' || playerMove == 'p' || playerMove == 's')
            break;
        cout << RED << "Invalid input! Please enter r, p, or s: " << RESET;
    }

    char computerMove = getComputerMove();
    int result = getResults(playerMove, computerMove);

    cout << "\nYour Move: " << emojiForMove(playerMove) << endl;
    cout << "Computer's Move: " << emojiForMove(computerMove) << endl;

    if (result == 0)
        cout << YELLOW << "It's a Draw! 🤝" << RESET << endl;
    else if (result == 1)
        cout << GREEN << "Congratulations! You won! 🎉" << RESET << endl;
    else
        cout << RED << "Computer wins! Try again. 💻" << RESET << endl;

    return 0;
}

