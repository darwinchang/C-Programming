#include <iostream>
#include "ansiicodes.h"
#include <iomanip>
using namespace std;

int main () {

    //Formatting Spaces
    int spacingValue = 7;

    //Local Fruit Box Calculator Header (green)

    cout << ANSII_GREEN << ANSII_BOLD
         << "**************************" << endl;
    cout << "Local Fruit Box Calculator" << endl;
    cout << "**************************" << endl;
    cout <<ANSII_NORMAL;

    cout << endl;

    /*initialize apples, oranges and fruitsperbasket
    prompts user to enter number of each fruit and fruit per basket (numbers red)*/
    int applesDonated= 0;
    cout << "Enter the number of " << ANSII_RED << "apples donated: " << ANSII_NORMAL;
    cin>> applesDonated;
    int orangesDonated= 0;
    cout << "Enter the number of " << ANSII_RED << "oranges donated: " << ANSII_NORMAL;
    cin>> orangesDonated;
    int fruitsPerBasket= 0;
    cout << "Enter the number of " << ANSII_RED << "fruit pieces per basket: " << ANSII_NORMAL;
    cin>> fruitsPerBasket;

    //spacing Between groupings
    cout << endl << endl;

    //"input values" header (green)
    cout << ANSII_GREEN << ANSII_BOLD
         << "Input Values:" << endl;
    cout << "-------------" << endl;
    cout << ANSII_NORMAL;

    //Review of inputs
    cout << "# Apples Donated:          " << ANSII_RED << setw(spacingValue) << applesDonated << ANSII_NORMAL << endl;
    cout << "# Oranges Donated:         " << ANSII_RED << setw(spacingValue) << orangesDonated << ANSII_NORMAL << endl;
    cout << "# Fruit Pieces per Basket: " << ANSII_RED << setw(spacingValue) << fruitsPerBasket << ANSII_NORMAL << endl;

    cout << endl << endl;

    //"Basket Creation Numbers:" header
    cout << ANSII_GREEN<< ANSII_BOLD
         <<"Basket Creation Numbers:" << endl;
    cout <<"------------------------";
    cout << ANSII_NORMAL;
    cout << endl;

    //int basket to create
    int basketToCreate= 0;
    int totalAmountFruits= (applesDonated+orangesDonated);
    basketToCreate= totalAmountFruits / fruitsPerBasket;
    cout << "# of basket(s) to create:  " << ANSII_RED << setw(spacingValue) << basketToCreate << ANSII_NORMAL<< endl;

    //min # of apples per basket
    int minApplesBasket=0;
    minApplesBasket= applesDonated/basketToCreate;
    cout << "Min # apples per basket:   " << ANSII_RED << setw(spacingValue) << minApplesBasket << ANSII_NORMAL;
    cout << endl;

    //min # of oranges per basket
    int minOrangesBasket=0;
    minOrangesBasket= orangesDonated/basketToCreate;
    cout << "Min # oranges per basket:  " << ANSII_RED << setw(spacingValue) << minOrangesBasket << ANSII_NORMAL;
    cout << endl;

    //# Ribbons to tie Baskets
    int ribbonsNeeded=0;
    int ribbonsPerBasket= 3;
    ribbonsNeeded= basketToCreate*ribbonsPerBasket;
    cout << "# Ribbons to tie baskets:  " << ANSII_RED << setw(spacingValue) << ribbonsNeeded << ANSII_NORMAL;
    cout << endl;

    //Pieces needed to make one more basket
    int piecesForMoreBasket=0;
    piecesForMoreBasket=fruitsPerBasket-(totalAmountFruits % fruitsPerBasket);
    cout << "# Pieces needed to complete one more basket: " << ANSII_RED << setw(spacingValue) << piecesForMoreBasket<< ANSII_NORMAL;
    cout << endl;
    cout << endl;


    return 0;

}







