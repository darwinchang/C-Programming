#include <iostream>
#include <ctime>
#include "iomanip"
#include "ansiicodes.h"
#include <cstdlib>
using namespace std;

//Title Funcion
void displayWelcome(){
    cout << "***********************************************" << endl
         << "Welcome to he Roller's Un-Random house of dice!" << endl
         << "***********************************************" << endl;
}

//Getting the user's first name (function)
string getUserName(){
    cout << "What is your name?(First Name Only) :";
    string name;
    cin >> name;
    return name;
}

//Choosing the type of random (function)
void seedGame(){
    cout << "Would you like to pick an un-random game, or let the timer pick? " << endl
         << "Enter 0 for timer, or pick your own un-random game: ";
    int seedChoice=1;
    cin >> seedChoice;
    if (seedChoice==0){
        srand(time(nullptr));
        cout << "THE TIMER! A daring choice! " << endl << endl;
    }
    else if (seedChoice!=0){
        srand(seedChoice);
        rand();
        cout << seedChoice << "! A wise and safe choice. " << endl << endl;
    }
}

//The actual dice rolling function
int getRandomRolling(){
    const int MAX_VALUE=6;
    const int MIN_VALUE=1;
    int diceValue;
    diceValue=rand()%MAX_VALUE+MIN_VALUE;
    return diceValue;
}

//prompts user What is the Max Bet Possible? and restrictions
int getMaxBet(){
    int maxBet = 0;
    const int MIN_BET_POSSIBLE=1;
    while (maxBet <= 0) {
        cout << "What would you like to be the maximum bet? :";
        cin >> maxBet;
        if (maxBet < MIN_BET_POSSIBLE) {
            cout << ANSII_RED << "The maximum bet must be greater than or equal to 1." << ANSII_NORMAL << endl;
        }
    }
    return maxBet;
}

//betting values and the restrictions
int getUserBet(int currentScore, int maxBet){
    int betValue=0;
    while (betValue<=0){
        cout << "Enter your bet: ";
        cin >> betValue;
        if (betValue<1){
            cout << ANSII_RED << "Your bet must be at least 1" << ANSII_NORMAL << endl;
            betValue=0;
        }
        else if (betValue>maxBet){
            cout << ANSII_RED << "You must not bet more than he maximum bet ("<< maxBet << ")" << ANSII_NORMAL << endl;
            betValue=0;
        }
        else if (betValue>currentScore){
            cout << ANSII_RED << "Your bet must not exceed your current score (" << currentScore << ")" << ANSII_NORMAL << endl;
            betValue=0;
        }
    }
}



int main(){

    //displays title
    displayWelcome();

    //Get Name of Player
    string name;
    name=getUserName();

    //Set the Seed Random or Set
    seedGame();

    //Setup the Max bet value
    int maxBet=0;
    maxBet=getMaxBet();

    //Down to the Game itself.
    int userScore=50;
    int roundNumber=1;

    const int WINNING_SCORE=100;
    const int LOSING_SCORE=0;
    while (userScore>LOSING_SCORE && userScore<WINNING_SCORE){
        cout << endl << "Round " << roundNumber << ". You have " << ANSII_CYAN << userScore << ANSII_NORMAL << " points." << endl;
        roundNumber++;
        //Variable for Roll Numbers
        int cmptRollNumberOne=getRandomRolling();
        int cmptRollNumberTwo=getRandomRolling();

        //The computer rolls
        int totalCmptRoll= cmptRollNumberOne+cmptRollNumberTwo;
        cout << "Dealer Rolls: "
             << cmptRollNumberOne << " + " << cmptRollNumberTwo << " = " << ANSII_CYAN << totalCmptRoll << ANSII_NORMAL;
        cout << "                     ";

        int roundBet=0;
        roundBet=getUserBet(userScore, maxBet);

        //The user rolls
        int userRollNumberOne=getRandomRolling();
        int userRollNumberTwo=getRandomRolling();
        int totalUserRoll= userRollNumberOne+userRollNumberTwo;
        cout << "Your roll: "
             << "    " << userRollNumberOne << " + " << userRollNumberTwo << " = " << ANSII_CYAN << totalUserRoll << ANSII_NORMAL<< endl;

        //Checking for which Value is Bigger cmpt or user
        if (totalCmptRoll<totalUserRoll){
            userScore += roundBet;
            cout << ANSII_GREEN << name << ", you won. :-)" << ANSII_NORMAL << endl;
        }

        else if (totalCmptRoll>totalUserRoll){
            userScore-= roundBet;
            cout << ANSII_RED << name << ", you lost. :-(" << ANSII_NORMAL << endl;
        }

        else if (totalCmptRoll==totalUserRoll){
            cout << ANSII_MAGENTA << name << ", you tied, lol try again." << ANSII_NORMAL << endl;
        }
        cout << "Current Score " <<ANSII_CYAN << userScore <<ANSII_NORMAL << endl;
    }

    //Once you have lost or won, display winning/losing message
    if (userScore>=WINNING_SCORE){
        cout << ANSII_GREEN << ANSII_BOLD
             << "Conratulations " << name << "! You win the game with a score of " << userScore
             << ANSII_NORMAL;
    }
    else if (userScore<=LOSING_SCORE){
        cout << ANSII_RED << ANSII_RED
             << "I'm sorry,  " << name << ". You are out of points so you lose. "
             << ANSII_NORMAL;
    }


}

// ( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)
// Created by darwinchang on 19/10/16.
//











































































































//( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)