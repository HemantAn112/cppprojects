//i m going to make a tic tac toe game in c++
#include <bits/stdc++.h>
using namespace std;
class TicTacToe {
    public:
   // vector<vector<char>> board;
    char player1, player2;
        TicTacToe() {
        // Initialize the board with empty spaces
        // board = vector<vector<char>>(3, vector<char>(3, ' '));
        player1 = 'X';
        player2 = 'O';


 }

 vector<vector<char>> board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    //next we will make a function to print the board
    void printBoard() {
        for (int i = 0; i < 3; i++) {
           
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];

                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }

        cout << endl;
    }

    //next we will make a function to make a move
    void makeMove(int row, int col, char player){

        if(board[row][col] == ' '){
            board[row][col] = player;
        }
        else{
            cout << "Invalid move! Cell already occupied." << endl;
        }

    }

    //check for win or draw
    bool checkWin(char player){

        //check rows
        for(int i=0;i<3;i++){
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
                return true;
            }
        }

        //check columns
        for(int i=0;i<3;i++){
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
                return true;
            }
        }

        //check diagonals
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
            return true;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
            return true;
        }

        return false;
    }


    //next we will make a function to check for draw
};

int main(){



    TicTacToe game;

    game.printBoard();
// i  want to take moves from the user and update the board accordingly

    int row, col;
    char player = game.player1;

    for (int i = 0; i < 9; i++) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;

        game.makeMove(row, col, player);
        game.printBoard();

        // Check for win or draw
        if (game.checkWin(player)) {
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        else if (i == 8) {
            cout << "It's a draw!" << endl;
        }

        // Switch players
    
        player = (player == game.player1) ? game.player2 : game.player1;
    }


    return 0;



}