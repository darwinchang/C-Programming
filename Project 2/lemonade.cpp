//Created By Darwin Chang
#include <iostream>
#include <iomanip>
#include "ansiicodes.h"
using namespace std;

int main () {
    //Lemonade Stand Menu
    const int SMALL_LEMONADE_CENTS = 100;
    const int MEDIUM_LEMONADE_CENTS = 200;
    const int LARGE_LEMONADE_CENTS = 800;
    const int DOLLARS_TO_CENTS= 100;

    int smallLemonadeDollars= SMALL_LEMONADE_CENTS / DOLLARS_TO_CENTS;
    int mediumLemonadeDollars= MEDIUM_LEMONADE_CENTS / DOLLARS_TO_CENTS;
    int largeLemonadeDollars= LARGE_LEMONADE_CENTS / DOLLARS_TO_CENTS;
    cout << "Menu:" << endl
         << "*******************" << endl
         << "New-age lemonade sizes:" << endl
         << "   Small:  " << setw(3) << "$" << smallLemonadeDollars << endl
         << "   Medium: " << setw(3) << "$" << mediumLemonadeDollars << endl
         << "   Large:  " << setw(3) << "$" << largeLemonadeDollars << endl;

    //Format Spacing
    cout << endl;


    //Order Header
    cout << "Enter number of drinks purchased..."
         << endl;

    // # small lemonade bought
    int smallLemonadeBought= 0;
    cout << "# Small:  " ;
    cin >> smallLemonadeBought;

    // # medium lemonade bought
    int mediumLemonadeBought= 0;
    cout << "# Medium: " ;
    cin >> mediumLemonadeBought;

    // # large lemonade bought
    int largeLemonadeBought= 0;
    cout << "# Large:  " ;
    cin >> largeLemonadeBought;


    //Format Spacing
    cout << endl;


    //Order Final
    cout << "Your order is:"
         << endl;
    cout << "   Small:   "
         << ANSII_RED << setw(5) << smallLemonadeBought << ANSII_NORMAL << " @ $" << smallLemonadeDollars << " each"
         << endl;
    cout << "   Medium:  "
         << ANSII_RED << setw(5) << mediumLemonadeBought << ANSII_NORMAL << " @ $" << mediumLemonadeDollars << " each"
         << endl;
    cout << "   Large:   "
         << ANSII_RED << setw(5) << largeLemonadeBought << ANSII_NORMAL << " @ $" << largeLemonadeDollars << " each"
         << endl;




    //Amount Owing Header
    cout << "Amount owing:"
         << endl;


    //Subtotal of Each Size
    int smallSubtotal= smallLemonadeBought*SMALL_LEMONADE_CENTS;
    int mediumSubtotal= mediumLemonadeBought*MEDIUM_LEMONADE_CENTS;
    int largeSubtotal= largeLemonadeBought*LARGE_LEMONADE_CENTS;

    //Actual Subtotal
    int subtotal= smallSubtotal+mediumSubtotal+largeSubtotal;
    int subtotalDollars= subtotal/DOLLARS_TO_CENTS;
    int subtotalCents= subtotal%DOLLARS_TO_CENTS;

    //Output Tax
    cout << "   Subtotal: $" << setw(3)
         << subtotalDollars << "."
         << setfill ('0') << setw(2) << subtotalCents << setfill (' ');
    cout << endl;

    //Tax Calculations
    const int TAX_RATE= 12;
    int tax=0;
    tax= subtotal*TAX_RATE/100;
    int taxDollars= 0;
    taxDollars= tax/DOLLARS_TO_CENTS;
    int taxCents= 0;
    taxCents= tax%DOLLARS_TO_CENTS;
    //Output Tax
    cout << "   Tax:      $" << setw(3)
         << taxDollars << "."
         << setfill('0') << setw(2) << taxCents << setfill (' ');
    cout << endl;

    //Total
    int total = subtotal+tax;
    int totalDollars= total/DOLLARS_TO_CENTS;
    int totalCents= total%DOLLARS_TO_CENTS;
    cout << "   Total:    $" <<ANSII_YELLOW << setw(3)
         <<ANSII_YELLOW << ANSII_BOLD << totalDollars << "."
         << setfill('0') << setw(2) << totalCents << setfill(' ') << ANSII_NORMAL;


}

