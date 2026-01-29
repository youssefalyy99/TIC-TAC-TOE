#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

    //INITIALIZATION OF GRID, GLOBAL VARIABLES AND FUNCTIONS PROTOTYPES

void markx (int number);
void marko (int number);
void winnerx();
void winnero();
char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char PlayerToStart[50];
char PlayerToEnd[50];
int winnerDetection=0;
int errorDetection=0;


int main(){
    //INITIALIZATION OF LOCAL VARIABLES

    char player1[50];
    char player2[50];
    int num;

    //FANCY WAY TO START THE GAME
    printf("==========================================================================\n");
    printf("████████╗██╗░█████╗░  ████████╗░█████╗░░█████╗░  ████████╗░█████╗░███████╗\n");
    printf("╚══██╔══╝██║██╔══██╗  ╚══██╔══╝██╔══██╗██╔══██╗  ╚══██╔══╝██╔══██╗██╔════╝\n");
    printf("░░░██║░░░██║██║░░╚═╝  ░░░██║░░░███████║██║░░╚═╝  ░░░██║░░░██║░░██║█████╗░░\n");
    printf("░░░██║░░░██║██║░░██╗  ░░░██║░░░██╔══██║██║░░██╗  ░░░██║░░░██║░░██║██╔══╝░░\n");
    printf("░░░██║░░░██║╚█████╔╝  ░░░██║░░░██║░░██║╚█████╔╝  ░░░██║░░░╚█████╔╝███████╗\n");
    printf("░░░╚═╝░░░╚═╝░╚════╝░  ░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░  ░░░╚═╝░░░░╚════╝░╚══════╝\n");
    printf("==========================================================================\n");
    printf("----------------------Welcome To Tic Tac Toe!!----------------------------\n");

    // GETTING NAME FROM USERS

    printf("PLAYER 1 :");
    scanf("%s",player1);

    printf("PLAYER 2 :");
    scanf("%s",player2);

    printf("\n");
    // VIRTUAL COIN TOSS TO GET PLAYER FIRST TO START
    srand(time(NULL));
    int value = (rand() / 1000);

    if(value % 2 == 0){
        printf("---> {{ %s }} Will Start The Game As (X) And {{ %s }} As (O)!\n",player1,player2);
        strcpy(PlayerToStart,player1);
        strcpy(PlayerToEnd,player2);
        printf("\n");
    }
    else{
        printf("---> {{ %s }} Will Start The Game As (X) And {{ %s }} As (O)!\n",player2,player1);
        strcpy(PlayerToStart,player2);
        strcpy(PlayerToEnd,player1);
        printf("\n");
    }

     // INSTRUCTIONS FOR GRID AND HOW TO PLAY

    printf("This Will Be Your Grid, Pick A Number To Put Your Mark!\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n");
    printf("\n");

for(int i = 0; i < 5 ; i++){
    //TAKES INPUT FROM PLAYER 1
        printf("{{ %s }}, Please Enter Your Number: ",PlayerToStart);
        if(scanf("%d",&num) != 1){
             printf("INVALID, Entered Value Is NOT a Number...\n");
             return 1; //code 1: user did not submit a number
        }
        printf("\n");
        if(num > 9 || num < 1){
             printf("INVALID, Grid Boundries is From 1 To 9... \n");
             return 2; //code 2: user submitted a number out of the grid boundries
        }

        //MARKING X AS WELL AS CHECKING IF IT'S NOT ALREADY TAKEN
        markx(num);

        if(errorDetection == 1){
            return 3;//code 3: user submitted a number that is already taken
        }

        // SETTING FLAG TO 1 IF PLAYER 1 IS DETECTED AS WINNER
        winnerx();
        if(winnerDetection == 1){
            return 0;
        }


        //EXIT STATUES IF A DRAW OCCUERS
        if(i == 4){
            printf("DRAW!\n");
            return 0;
        }

        //TAKES INPUT FROM PLAYER 2
        printf("{{ %s }}, Please Enter Your Number: ",PlayerToEnd);
        if(scanf("%d",&num) != 1){
            printf("INVALID, Entered Value Is NOT a Number...\n");
            return 1;//code 1: user did not submit a number
        }

        printf("\n");

        if(num > 9 || num < 1){
             printf("INVALID, Grid Boundries is From 1 To 9... \n");
             return 2; //code 2: user submitted a number out of the grid boundries
        }


        //MARKING 0 AS WELL AS CHECKING IF IT'S NOT ALREADY TAKEN
        marko(num);
        if(errorDetection == 1){
            return 3; //code 3: user submitted a number that is already taken
        }


        // SETTING FLAG TO 1 IF PLAYER 2 IS DETECTED AS WINNER
        winnero();
        if(winnerDetection == 1){
            return 0;
        }


}
}


//MARK X FUNCTION: MARKS X WHERE PLAYER 1 WANTS AND CHECKING IF ALREADY MARKED

void markx (int number) {

    int row = (number - 1)/3;
    int col = (number - 1)%3;

    if (grid[row][col] == 'O'){
        printf("INVALID, O is Already Marked There...\n");
        errorDetection = 1;
    }
if(errorDetection == 0){
    grid[row][col] = 'X';
    for (int k = 0; k < 3; k++) {
        for (int m = 0; m < 3; m++) {
            printf(" %c ", grid[k][m]);
            if (m < 2) printf("|");  // vertical separators
        }
        printf("\n");
        if (k < 2) printf("---+---+---\n"); // horizontal separators
    }
    printf("\n");
    }
}

//MARK O FUNCTION: MARKS O WHERE PLAYER 1 WANTS AND CHECKING IF ALREADY MARKED
void marko (int number) {

    int row = (number - 1)/3;
    int col = (number - 1)%3;

    if (grid[row][col] == 'X'){
        printf("INVALID, X is Already Marked There...\n");
        errorDetection = 1;
    }

    if( errorDetection == 0){
    grid[row][col] = 'O';
    for (int k = 0; k < 3; k++) {
        for (int m = 0; m < 3; m++) {
            printf(" %c ", grid[k][m]);
            if (m < 2) printf("|");
        }
        printf("\n");
        if (k < 2) printf("---+---+---\n");
    }
    printf("\n");
}

    }

// WINNER X FUNCTION : DETECTS IF PLAYER (X) WINS
void winnerx(){

for( int k = 0 ; k <3 ; k++){
    if( (grid[k][0] == grid [k][1]) && (grid[k][1] == grid [k][2]) ){
       printf("{{ %s }} WINS!\n" , PlayerToStart);
       winnerDetection = 1;
       break;
    }else if( (grid[0][k] == grid [1][k]) && (grid[1][k] == grid [2][k]) ){
       printf("{{ %s }} WINS!\n" , PlayerToStart);
       winnerDetection = 1;
       break;
    }else if( (grid[0][0] == grid [1][1]) && (grid[1][1] == grid [2][2]) ){
       printf("{{ %s }} WINS!\n" , PlayerToStart);
       winnerDetection = 1;
       break;
    }else if( (grid[0][2] == grid [1][1]) && (grid[1][1] == grid [2][0]) ){
       printf("{{ %s }} WINS!\n" , PlayerToStart);
       winnerDetection = 1;
       break;
    }
}
}

// WINNER O FUNCTION : DETECTS IF PLAYER (O) WINS

void winnero(){

for( int k = 0 ; k <3 ; k++){
    if( (grid[k][0] == grid [k][1]) && (grid[k][1] == grid [k][2]) ){
       printf("{{ %s }} WINS!\n" , PlayerToEnd);
       winnerDetection = 1;
       break;
    }else if( (grid[0][k] == grid [1][k]) && (grid[1][k] == grid [2][k]) ){
       printf("{{ %s }} WINS!\n" , PlayerToEnd);
       winnerDetection = 1;
       break;
    }else if( (grid[0][0] == grid [1][1]) && (grid[1][1] == grid [2][2]) ){
       printf("{{ %s }} WINS!\n" , PlayerToEnd);
       winnerDetection = 1;
       break;
    }else if( (grid[0][2] == grid [1][1]) && (grid[1][1] == grid [2][0]) ){
       printf("{{ %s }} WINS!\n" , PlayerToEnd);
       winnerDetection = 1;
       break;
    }
}
}
