# TIC-TAC-TOE
#### Video Demo:  https://youtu.be/ja_gr0IiRCo
#### Description:

# Introduction

The project is a command line implentation of the simple game Tic-Tac-Toe a fully functional game written in C language. it
demonstrates alot of fundemental programming concepts like arrays, loops, and conditionals which i gained throughtout the journey
of CS50, the idea of the program is simple, a two player based game that takes turns until a win or a draw situation occers, it
features detection of winner or draw, a coin toss mechanism, input validation, and a fully interactive 3x3 grid.


# How Does The Game Works

Firstly, as you run the program the players will be introduced with a fancy interface then the first user will be prompted to
enter their name and then the other player name will be prompted the same , then a virtual coin toss will occur to determine
whether the first player or the other player get to start the game, then a 3x3 grid will appear showing numbers from 1 to 9 in
which the players will take turns giving input to place their mark on the grid, the game will keep on getting input until one
player forms a line of three marks in a row, column or diagonal, if the grid is full without a winning line the game announces a
draw.

# Program Flow

as you are greeted the welcome banner, a scanf function is called to get names from both players, to implement the virtual coin
toss function i called a time function and a rand function that helps getting a random value of numbers everytime running the
program then checking whether the value called is even or odd so chances are always 50/50 and determining which player takes the
X symbol and which player take the O symbol, then a simple numbered grid is shown to tell the players how to get input from them
to the program, futhermore a loop takes place in which all of the actual game takes place as follows taking input from player one
validating the input as implemented in the markx funtion then takes input from player two in the marko function till the program
detect a winner situation in both winnerx and winnero function as the program will announce the winner and ends immediately, the
program detects a draw if the nine grids are taken and the winnerx and winnero function are not yet called till this moment using
an if statment inside of the for loop.


# Error Handling

you cannot trust the input of the user as it could cause malfunctioning to the program, so first i got to check if the value
entered from user to the grid is a number or a character, if is not a number it breaks out of the program with return value of
one, but what if the player enter a valid number but the number is NOT in the boundries of the grid from 1 to 9, it also breaks
out of the program with a return value of two, finally what happens in case of inputing a number another player have already
entered? it also breaks out with a return value of three as i have implemented a flag errorDectection inside the marko funtion
and markx fuction that is initially set to zero if an error is detected it will set that flag to value of one allowing to break
of the program, in each case a message is shown in the treminal acknowledging the error occered. if the program succesfully ends
with a win situation or a draw situation it will return a value of 0 which indicates that the program ended succesfully.

# Limitaions And Future Improvments

1- Only supporting two human players with no AI player option

the game currently supports having two players only so you cannot play this game on solo mode maybe adding it to the program will
allow flexability and possibly different difficulties like easy, normal and hard.

2- Limited with the command line interface

the game could possibly look much better in color and having a graphical interface which could be made in the future by various
number of ways like programming is html, css and javascript

3- No score tracking

the game only supports one round so that the program ends after it, a future implementation could be adding a restart option
having the player that lost the last round begin first

4- improving player customization

the game will always make sure that the player that wins the coin toss always get to play as the X symbol and the other player
gets to play with O, a future improvment is adding a customization option in which the players can choose their own symbols,
maybe a different character or even an emoji!
