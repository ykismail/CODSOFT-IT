// Tic Tac Toe game (task 3).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
char grid[3][3] = { {'1','2','3'} ,{'4','5' ,'6'}, {'7', '8', '9'} };
void printGrid() {
    std::cout << "   Player 1 (X)   Player 2 (O)\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << std::endl;
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << std::endl;
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << std::endl;
    std::cout << "     |     |     \n";
}
bool Win() {
    //diagonal
    if ((grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])) {
        return true;
    }
    //row and column
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) || (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]))
        {
            return true;
        }
    }
    
    return false;
}
bool Draw() {
    if (grid[0][0]!= '1' && grid[0][1] != '2' && grid[0][2] != '3' && grid[1][0] != '4' && grid[1][1] != '5' && grid[1][2] != '6' && grid[2][0] != '7' && grid[2][1] != '8' && grid[2][2] != '9') {
        return true;
    }
    return false;
}
int main()
{ 
    int playagain=1;
    int choice;
    int row, column;
    int player=1;
    while (playagain == 1) {
        grid[0][0] = '1'; grid[0][1] = '2'; grid[0][2] = '3';
        grid[1][0] = '4'; grid[1][1] = '5'; grid[1][2] = '6';
        grid[2][0] = '7'; grid[2][1] = '8'; grid[2][2] = '9';
        while (!Win() && !Draw()) {
            printGrid();
            if (player == 1) {
                std::cout << "Player " << player << "'s (X) turn!\nPick a Number!\n";
            }
            else {
                std::cout << "Player " << player << "'s (O) turn!\nPick a Number!\n";
            }
            std::cin >> choice;
            switch (choice) {
            case 1: row = 0; column = 0; break;
            case 2: row = 0; column = 1; break;
            case 3: row = 0; column = 2; break;
            case 4: row = 1; column = 0; break;
            case 5: row = 1; column = 1; break;
            case 6: row = 1; column = 2; break;
            case 7: row = 2; column = 0; break;
            case 8: row = 2; column = 1; break;
            case 9: row = 2; column = 2; break;
            default:
                std::cout << "INVALID MOVE!!\n"; break;
            }
            if (player == 1 && grid[row][column] != 'X' && grid[row][column] != 'O') {
                grid[row][column] = 'X';
                player++;
            }
            else if (player == 2 && grid[row][column] != 'X' && grid[row][column] != 'O') {
                grid[row][column] = 'O';
                player--;
            }
            else {
                std::cout << "Box already filled in!! Pick another box!\n";
            }
            Win();
        }
        printGrid();
        if (Win()) {
            if (player == 1) {
                std::cout << "Congratulations Player 2 (O)! You have WON!\n";
            }
            else if (player == 2) {
                std::cout << "Congratulations Player 1 (X)! You have WON!\n";
            }
        }
        else if (Draw()) { std::cout << "It's a DRAW!\n"; }
        std::cout << "Press 1 to play again or 0 to stop playing!\n";
        std::cin >> playagain;
    }
}


