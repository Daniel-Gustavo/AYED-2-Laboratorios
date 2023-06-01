#include <stdlib.h>
#include <stdio.h>  
#include <stdbool.h> 
int mN = 5; //tamano matriz
#include <assert.h> 
#define CELL_MAX (mN * mN - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[mN][mN])
{
    int cell = 0;

    print_sep(mN);
    for (int row = 0; row < mN; ++row) {
        for (int column = 0; column < mN; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(mN);
    }
}

char get_winner(char board[mN][mN])
{
    char winner = '-';
    int hayGanador = 0;
    int i,j,contX, contO;
    // chequeo fila 

    for (i=0; i<mN && hayGanador==0; i++){
        contX = 0, contO = 0;
        for (j=0; j<mN && hayGanador==0; j++){
            if (board[i][j] == 'X' && hayGanador==0){
                contX++;
            }
            else if(board[i][j] == 'O' && hayGanador==0){
                contO++;
            }
        }
        if (contX==mN){
            hayGanador = 1;
            winner='X';        
        }
        else if (contO==mN){
            hayGanador = 1;
            winner='O';        
        }
        else{
            contX = 0, contO = 0;
        }
    }

    // chequeo para columna

    for (i=0; i<mN && hayGanador==0; i++){
        contX = 0, contO = 0;
        for (j=0; j<mN && hayGanador==0; j++){
            if (board[j][i] == 'X'){
                contX++;
            }
            else if (board[j][i] == 'O'){
                contO++;
            }
        }
        if (contX==mN){
            hayGanador = 1;
            winner = 'X';
        }
        else if (contO==mN){
            hayGanador = 1;
            winner='O';        
        }
        else{
            contX = 0, contO = 0;
        }
    }

    // chequeo diagonal

    contX = 0, contO = 0;
    for (i=0; i<mN && hayGanador==0; i++){
        if (board[i][i]=='X'){
            contX++;
        }
        else if (board[i][i]=='O'){
            contO++;        
        }
        if (contX==mN){
            hayGanador = 1;
            winner = 'X';
        }
        else if (contO==mN){
            hayGanador = 1;
            winner='O';        
        }
    }

    // chequeo inversa de diagonal

    contX = 0, contO = 0;
    j = mN-1;
    for (i=0; i<mN && hayGanador==0; i++){
        if (board[i][j]=='X'){
            contX++;
        }
        else if(board[i][j]=='O'){
            contO++;
        }
        if (contX==mN){
            hayGanador = 1;
            winner = 'X';
        }
        else if (contX==mN){
            hayGanador = 1;
            winner='O';        
        }
        j--;
    }


    //
    return winner;
}

bool has_free_cell(char board[mN][mN])
{
    bool free_cell;
    //
    free_cell = 1;
    int i,j;
    int cont = 0;

    for (i=0;i<mN;i++){
        for (j=0;j<mN;j++){
            if (board[i][j] != '-'){
                cont++;
            }
        }
    }
    if (cont==(mN*mN)){
        free_cell = 0;
    }
    
    return free_cell;
}


int main(void)
{
    printf("TicTacToe de TABO!\n");

    char board[mN][mN];
    int i,j;
    for (i=0;i<mN;i++){
        for (j=0;j<mN;j++){
            board[i][j]='-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / mN;
            int colum = cell % mN;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
}