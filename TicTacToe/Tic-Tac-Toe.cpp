#include <iostream>
using namespace std;

char space[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Return game status 
int whoWon() {

    int winCombos[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rown wins combo
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Column wins combo
        {1, 5, 9}, {3, 5, 7}             // Diagonal wins combo
    };

    for (int i = 0; i < 8; i++) {

        if (space[winCombos[i][0]] == space[winCombos[i][1]] &&
            space[winCombos[i][1]] == space[winCombos[i][2]]) {
            return 1;  
        }
    }

    for (int i = 1; i <= 9; i++) {

        if (space[i] != 'X' && space[i] != 'O') {
            return -1;  
        }
    }

    return 0;  

}


void intro() {

    cout << "Lets play Tic Tac Toe!" << "\n";
    cout << "Player 1 will be X" << "   Player 2 will be O \n\n"; 

}


 // Drawing the game board
 void board() {

    cout << "\n";
    cout << " " << space[1] << " | " << space[2] << " | " << space[3] << "\n";
    cout << "---+---+--- \n";
    cout << " " << space[4] << " | " << space[5] << " | " << space[6] << "\n";
    cout << "---+---+--- \n";
    cout << " " << space[7] << " | " << space[8] << " | " << space[9] << "\n\n";

 }
 

int main() {
    
    int player = 1, i, choice;
    char place;

    intro();

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", please enter a number to place your mark: ";
        std:: cin >> choice;

        place = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && space[choice] == ('0' + choice)) {
            space[choice] = place;
        } 

        else {
            cout << "This move is invalid, try again!\n\n";
            player--;  
            std:: cin.clear();
            std:: cin.ignore(1000, '\n');
        }

        i = whoWon();
        player++;

    } while (i == -1);

    board();

    
    if (i == 1) {
        cout << "\a Congratulations to Player " << --player << " you won! Great job :)";
    }

    else {
        cout << "\a It's a draw!";
    }

    return 0;

}