#include <iostream>
#include "ansiicodes.h"
using namespace std;


int main() {

    cout << "Enter your height" << ANSII_RED << " (inches):" << endl;

    //intialize entered height, conversion rate, and final converted height
    int heightIn= 0;
    cin>>heightIn;

    int conversionFtToIn=12;
    int convertedHeight= 0;
    int leftoverHeightIn;
    convertedHeight= heightIn/conversionFtToIn;
    leftoverHeightIn= heightIn%conversionFtToIn;

    //This is for feet/inches
    cout << ANSII_GREEN << ANSII_BOLD << "I'm " << convertedHeight << "\'" << leftoverHeightIn << "\"" << " tall! ";

    //This is total inches
    cout << ANSII_NORMAL <<"\\"
         << ANSII_MAGENTA << ANSII_BOLD << " I'm "
         <<  heightIn << "\" tall!";


    return 0;
}