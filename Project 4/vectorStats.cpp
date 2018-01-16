#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;


//basically gets in the user input and puts it into a vector
vector<float>readUserInputFloat(){
    vector<float>inputFloat;
    cout << "Enter Value (0 to end): ";
    float inputtedFloat=0;
    cin >> inputtedFloat;
    while (inputtedFloat!=0){
        inputFloat.push_back(inputtedFloat);
        cout << " ";
        cin >> inputtedFloat;
    }
    cout << "Now exiting float input." << endl;
    return inputFloat;
}

//CHECKS IF FUNCTION IS INCREASING
bool isAscending(vector<float> vect){
    bool ascending = true;
    if (vect.size()!= 0) {
        float currentValue = vect.at(0);

        for (float nextValue:vect) {
            if (currentValue > nextValue)
                ascending = false;
            else
                currentValue = nextValue;


        }
    }
return ascending;
}

//CHECKSI IF FUNCTION IS DECREASING
bool isDescending(vector<float> vect){
    bool descending = true;
    if (vect.size()!= 0) {
        float currentValue = vect.at(0);

        for (float nextValue:vect) {
            if (currentValue < nextValue)
                descending = false;
            else
                currentValue = nextValue;


        }
    }
    return descending;
}

//CHECKS VECTOR AVERAGE
float findAverage(vector<float> vect){
    float sum=0;
    int count=0;
    if (vect.size()!=0) {
        for (float value:vect) {
            sum += value;
            count++;
        }
        float average = sum / count;
        return average;
    }
    else
        return 0;
}

//CHECKS MAX
float findMax(vector<float> vect){
    if (vect.size()!=0)
    {
        float currentMax = vect.at(0);
        for (float nextValue:vect)
        {
            if (currentMax < nextValue)
                currentMax = nextValue;
        }
        return currentMax;
    }
    else
        return 0;
}

//CHECKS MIN
float findMin(vector<float> vect) {
    if (vect.size() != 0) {
        float currentMin = vect.at(0);
        for (float nextValue:vect) {
            if (currentMin > nextValue)
                currentMin = nextValue;
        }
        return currentMin;
    } else
        return 0;
}

//FIND THE OCCURANCES AND HOW MANY TIMES
int countOccurances(vector<float>vect,float value){
    int count = 0;
    for (float vectValue:vect){
        if (vectValue == value){
            count++;
        }

    }
return count;
}


// Occ is short for occurances
float findMostCommonValue(vector<float> vect){
    struct numAndOcc{
        float num;
        int occurances=0;
    };
    numAndOcc mostCommon;
    mostCommon.num = 0;

    if (vect.size()!=0) {
        //Making a vector shortList of Values and Occurances from vector vect
        vector<numAndOcc> shortList;
        for (float value:vect) {
            bool isDuplicate = 0;
            numAndOcc structIter;
            for (unsigned int iter=0; iter < shortList.size();iter++) {
                if (shortList.at(iter).num == value) {
                    isDuplicate = 1;
                }
            }
            if (!isDuplicate) {
                structIter.num = value;
                shortList.push_back(structIter);
            }
        }

        //Counting occurances of each value
        for (unsigned int iter = 0; iter < shortList.size(); iter++) {
            shortList.at(iter).occurances = countOccurances(vect, shortList.at(iter).num);
        }


        //finding most common value
        for (numAndOcc structIter: shortList){
            if (structIter.occurances > mostCommon.occurances){
                mostCommon.num = structIter.num;
                mostCommon.occurances = structIter.occurances;
            }
        }
    }
    return mostCommon.num;
}

//REMOVES THE DUPLICATES
void removeDuplicates(vector<float> &vect){
        vector<float> floatShortList;
        for (float value: vect) {
            bool isDuplicate = 0;
            for (float floatIter: floatShortList) {
                if (floatIter == value) {
                    isDuplicate = 1;
                }
            }
            if (!isDuplicate) {
                floatShortList.push_back(value);
            }
        }

        vect = floatShortList;
    return;
 }

//prints out the vector of the thing
void printFloats(vector<float>vectorInputted) {
    const int NUMBERS_PER_ROW=8;
    cout << fixed <<setprecision(2);
    cout << endl;
    int numberOfEights=1;
    int row=1;
    for(int i=0; i<vectorInputted.size();i++){
        if(row==i+1/numberOfEights){
            cout << setw(8);

        }
        cout << vectorInputted.at(i);
        if(i==(NUMBERS_PER_ROW-1)*numberOfEights){
        }
        if(i!=vectorInputted.size()-1){
            cout << "," << setw(8);

        }
        if(i==NUMBERS_PER_ROW*(row)-1){
            cout << endl;
            row++;
        }

    }
}


int main(){

    vector<float>test=readUserInputFloat();
    const vector<float>original=test;

    cout << endl;

    //1.5 outputting the sample.
    cout << "************************************" << endl
         << "Analysis of the numbers:" << endl
         << "************************************" << endl;

    cout << endl;

    //Prints out the values in table.
    cout << "Values:" << endl
         << "-------";
    printFloats(test);
    cout << endl << endl;

    //Stats
    cout << "statistics on those numbers:" << endl;
    cout << "----------------------------" << endl;
    cout << setw(20) << "Maximum: " << findMax(test) << endl;
    cout << setw(20) << "Minimum: " << findMin(test) << endl;
    cout << setw(20) << "Average: " << findAverage(test) << endl;

    cout << endl;

    //Same but removed dupes
    cout << "Data with duplicates removed: " << endl;
    cout << "----------------------------- ";
    removeDuplicates(test);
    printFloats(test);

    cout << endl;

    //uses original vector to find the value. and not the one used when testing.
    cout << "repitition counts in user data: " << endl;
    cout << "------------------------------- " << endl;
    cout << "Most common value is " << findMostCommonValue(original) << "!";

    cout << endl;

    for(int i=0; i<test.size();i++){
        cout << "The value " << setw(10) << test.at(i) << " occurs "
             << setw(7) << countOccurances(original, test.at(i)) << " times(s)." << endl;
    }


    return 0;
}

