#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
using namespace std;

// ANSI color codes
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";

// Decorative header
void printHeader() {
    cout << CYAN;
    cout << "###############################################" << endl;
    cout << "#                                             #" << endl;
    cout << "#      Welcome to Rock Paper Scissors!        #" << endl;
    cout << "#                                             #" << endl;
    cout << "###############################################" << endl;
    cout << RESET;
}

// Animated countdown
void countdown() {
    const string words[] = { "Rock...", "Paper...", "Scissors...", "Shoot!" };
    for (const auto& w : words) {
        cout << MAGENTA << w << RESET << endl;
        this_thread::sleep_for(chrono::milliseconds(450));
    }
}

// Get computer move randomly
char getComputerMove() {
    return "rps"[rand() % 3];
}

// Emoji for each move
string emojiForMove(char move) {
    switch (move) {
        case 'r': return "🪨"; // Rock
        case 'p': return "📄"; // Paper
        case 's': return "✂️"; // Scissors
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
    srand(static_cast<unsigned int>(time(nullptr)));

    int wins = 0, losses = 0, draws = 0;
    char playAgain = 'c';

    printHeader();

    while (playAgain == 'c') {
        char playerMove;
        cout << YELLOW << "\nEnter r for Rock, p for Paper, s for Scissors: " << RESET;
        while (true) {
            cin >> playerMove;
            if (playerMove == 'r' || playerMove == 'p' || playerMove == 's') break;
            cout << RED << "Invalid input! Please enter r, p, or s: " << RESET;
        }

        countdown();

        char computerMove = getComputerMove();
        int result = getResults(playerMove, computerMove);

        cout << "Your Move: " << emojiForMove(playerMove) << endl;
        cout << "Computer's Move: " << emojiForMove(computerMove) << endl;

        if (result == 0) {
            cout << YELLOW << "It's a Draw! 🤝" << RESET << endl;
            draws++;
        } else if (result == 1) {
            cout << GREEN << "You won! 🎉" << RESET << endl;
            wins++;
        } else {
            cout << RED << "Computer wins! 💻" << RESET << endl;
            losses++;
        }

        cout << CYAN << "\n-------------------------------------------" << RESET << endl;

        int totalGames = wins + losses + draws;
        double winPercent = 100.0 * wins / totalGames;
        double lossPercent = 100.0 * losses / totalGames;
        double drawPercent = 100.0 * draws / totalGames;

        cout << BLUE << "--- Game Stats ---" << RESET << endl;
        cout << "Total games played: " << totalGames << endl;
        cout << "Wins: " << wins << " (" << winPercent << "%)" << endl;
        cout << "Losses: " << losses << " (" << lossPercent << "%)" << endl;
        cout << "Draws: " << draws << " (" << drawPercent << "%)" << endl;

        cout << "\nType " << GREEN << "'c'" << RESET << " to continue playing, or " << RED << "'e'" << RESET << " to exit: ";
        while (true) {
            cin >> playAgain;
            if (playAgain == 'c' || playAgain == 'e') break;
            cout << RED << "Invalid input! Enter 'c' to continue or 'e' to exit: " << RESET;
        }

        cout << CYAN << "###############################################" << RESET << endl;
    }

    cout << BLUE << "Thanks for playing! Goodbye! 👋" << RESET << endl;
    return 0;
}

