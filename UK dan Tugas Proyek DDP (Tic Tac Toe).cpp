#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
using namespace std;

char board[3][3];
const char player = 'X';
const char computer = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    char response;
    char pilih;

    do{
        winner = ' ';
        response = ' ';
        resetBoard();

    while(winner == ' ' && checkFreeSpaces() !=0){
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
    }
    printBoard();
    printWinner(winner);
    
    cout << "Apakah anda ingin bermain lagi? (Y/T): ";
    cin >> response;
    response = toupper(response);
    }while(response == 'Y');
    cout << "Terimakasih telah bermain!";

    return 0;
}

void resetBoard(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |";
    cout << "\n|---|---|---|\n";
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |";
    cout << "\n|---|---|---|\n";
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |";
    cout << "\n|---|---|---|\n";
}
int checkFreeSpaces(){
    int freeSpaces = 9;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           if(board[i][j] != ' '){
            freeSpaces--;
           }
        }
    }
    return freeSpaces;
}
void playerMove(){
    int x;
    int y;

    cout << "Masukkan baris (1-3): ";
    cin >> x;
    x--;
    cout << "Masukkan kolom (1-3): ";
    cin >> y;
    y--;

    if(board[x][y] != ' '){
        cout << "Langkah tidak valid\n";
    }else{
        board[x][y] = player;
    }
}
void computerMove(){
    //creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces()>0){
        do{
            x = rand() % 3;
            y = rand() % 3;
        }while(board[x][y] != ' ');
        board[x][y] = computer;
    }else{
        printWinner(' ');
    }
}
char checkWinner(){
    //check row
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //check column
    for(int i=0; i<3; i++){
        if(board[0][i] == board [1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    //check diagonal
    if(board[0][0] == board [1][1] && board[0][0] == board[2][2]){
            return board[0][0];
    }
    if(board[0][2] == board [1][1] && board[0][2] == board[2][0]){
            return board[0][2];
    }
    return ' ';
}
void printWinner(char){
    char winner;
    if(winner == player){
        cout << "KAMU MENANG\n";
    }else if(winner == computer){
        cout << "KAMU KALAH\n";
    }
}