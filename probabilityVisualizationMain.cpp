#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

/*
Thoughts:
- Write a menu for the user

    - In Menu, include an option for if the user wants to start a new probablity problem that would require a new grid

- Right above where the grid will be printed, (given that the chars inside the grid will only be one character), write a legend that connects the characters to whatever the user wants them to describe for space purposes

- Grids should be in the simple form [c] where c is any given character, so if the user stated that something had a 1/3 chance of happening, the grid would look like [0][1][1]

- Write the program so that it not only displays the grid, but also tells you the probability of something happening once the grid becomes more complex

- Make an option so the user can edit a certain part of the grid

- 
*/

void findSpecificProbability(vector<double> mainPercentages, vector<double> otherPercentages, vector<string> vectorOfCharsMain, vector<string> vectorOfCharsOther, vector<string> vectorOfDescriptionsMain, vector<string> vectorOfDescriptionsOther, string desiredChar) {

    cout << endl;

    for (int i = 0; i < vectorOfCharsMain.size(); i++) {

        if (vectorOfCharsMain[i] == desiredChar) {

            cout << "There is a " << mainPercentages[i] << " percent chance of " << vectorOfCharsMain[i] << "(" << vectorOfDescriptionsMain[i] << ")" << " happening!" << endl;

        }

        else if (vectorOfCharsOther[i] == desiredChar) {

            cout << "There is a " << otherPercentages[i] << " percent chance of " << vectorOfCharsOther[i] << "(" << vectorOfDescriptionsOther[i] << ")" << " happening!" << endl;

        } 

    }

    cout << endl;

}

void displayPercentageData(vector<double> mainPercentages, vector<double> otherPercentages, vector<string> vectorOfCharsMain, vector<string> vectorOfCharsOther) {

    for (int i = 0; i < vectorOfCharsMain.size(); i++) {

        cout << fixed << setprecision(0);
        cout << "There is a " << mainPercentages[i] << " percent chance of " << vectorOfCharsMain[i] << " happening!" << endl;
        cout << "There is a " << otherPercentages[i] << " percent chance of " << vectorOfCharsOther[i] << " happening!" << endl;

    }

    cout << endl;

}

void printUserCharData(vector<string> vectorOfCharsMain, vector<string> vectorOfCharsOther, vector<string> vectorOfDescriptionsMain, vector<string> vectorOfDescriptionsOther) {

    cout << endl;

    for (int i = 0; i < (vectorOfCharsMain.size()); i++) {

        cout << vectorOfCharsMain[i] << " - " << vectorOfDescriptionsMain[i] << endl;
        cout << vectorOfCharsOther[i] << " - " << vectorOfDescriptionsOther[i] << endl;

    }

    cout << endl;
}

void getUserCharData(string &mainProbability, string &otherProbability, string &mainProbabilityDescription, string &otherProbabilityDescription, string charToChange) {

    cout << "Enter character to denote the probability you gave earlier: ";
    getline(cin, mainProbability);

    cout << "Describe the main probability: ";
    getline(cin, mainProbabilityDescription);
    if (charToChange != "") {
        mainProbabilityDescription += " (Subset of " + charToChange + ")";
    }

    cout << "Enter character to denote the other probability: ";
    getline(cin, otherProbability);

    cout << "Describe the other probability: ";
    getline(cin, otherProbabilityDescription);\
    if (charToChange != "") {
        otherProbabilityDescription += " (Subset of " + charToChange + ")";
    }

}

void getFractionValues(string userInputFraction, string &denominator, string &numerator) {

    bool isDenominator = false;

    for (int i = 0; i < userInputFraction.length(); i++) {

        if (userInputFraction[i] == '/') {

            isDenominator = true;

        }

        else if (isDenominator == false) {

            numerator += userInputFraction[i];

        }

        else if (isDenominator == true) {

            denominator += userInputFraction[i];

        }

    }

}

void displayMenu() {

    cout << "Choose from an option below (remember to input a number corresponding to that option): " << endl;
    cout << "1. Start a probability calculation" << endl;
    cout << "2. Edit part of the probablity calculation (Instructions will follow if you choose this option)" << endl;
    cout << "3. Find probability of a specific instance (using one of your chosen characters)" << endl;
    cout << "4. Quit" << endl;

}

int main() {

    bool flag = false;

    cout << "Welcome to the probability calculator!" << endl;

    vector<string> vectorOfCharsMain;
    vector<string> vectorOfCharsOther;

    vector<string> vectorOfDescriptionsMain;
    vector<string> vectorOfDescriptionsOther;

    vector<double> mainPercentages;
    vector<double> otherPercentages;

    while (flag == false) {

        string userInputString;
        displayMenu();
        getline(cin, userInputString);

        if (userInputString == "1") {

            vectorOfCharsMain.clear();
            vectorOfCharsOther.clear();
            vectorOfDescriptionsMain.clear();
            vectorOfDescriptionsOther.clear();
            mainPercentages.clear();
            otherPercentages.clear();

            string userInputFraction;
            string denominator;
            string numerator;

            cout << "What is the probability of this instance happening? (Please input as a fraction using /) ";
            getline(cin, userInputFraction);

            getFractionValues(userInputFraction, denominator, numerator);

            int denominatorInt = stoi(denominator);
            int numeratorInt = stoi(numerator);

            int totalNumOfGrids = denominatorInt;

            string mainProbability;
            string otherProbability;

            string mainProbabilityDescription;
            string otherProbabilityDescription;

            getUserCharData(mainProbability, otherProbability, mainProbabilityDescription, otherProbabilityDescription, "");

            vectorOfDescriptionsMain.push_back(mainProbabilityDescription);
            vectorOfDescriptionsOther.push_back(otherProbabilityDescription);

            vectorOfCharsMain.push_back(mainProbability);
            vectorOfCharsOther.push_back(otherProbability);

            printUserCharData(vectorOfCharsMain, vectorOfCharsOther, vectorOfDescriptionsMain, vectorOfDescriptionsOther);

            double mainPercentage = ((float)numeratorInt / (float)denominatorInt) * 100;
            double otherPercentage = 100 - mainPercentage;

            mainPercentages.push_back(mainPercentage);
            otherPercentages.push_back(otherPercentage);

            displayPercentageData(mainPercentages, otherPercentages, vectorOfCharsMain, vectorOfCharsOther);

            cout << endl;

        }

        /*
        This else if statement will ask the user what character of the grid they want to edit, and then essentially repeat most of the functionality of else if 1 for that part of the grid
        In the description above the grid, say that the new chars are a subset of their old char
        */

        else if (userInputString == "2") {
            
            string desiredCharToChange;
    
            cout << "What part of the current probability calculation would you like to change? (input the character that represents that probability) ";
            getline(cin, desiredCharToChange);

            string userInputFraction;
            string denominator;
            string numerator;

            cout << "What is the probability of this instance happening inside the instance you have chosen (enter your input as a fraction with /) ";
            getline(cin, userInputFraction);

            getFractionValues(userInputFraction, denominator, numerator);

            int denominatorInt = stoi(denominator);
            int numeratorInt = stoi(numerator);

            double importantNum;

            for (int i = 0; i < vectorOfCharsMain.size(); i++) {

                if (vectorOfCharsMain[i] == desiredCharToChange) {

                    importantNum = mainPercentages[i];
                    
                }

                else if (vectorOfCharsOther[i] == desiredCharToChange) {

                    importantNum = otherPercentages[i];
                    
                }

            }

            double mainPercentage = ((((float)numeratorInt / (float)denominatorInt) * (importantNum / 100)) * 100);
            double otherPercentage = (((float)denominatorInt - (float)numeratorInt) / (float)denominatorInt) * (importantNum / 100) * 100;
            
            string mainProbability;
            string otherProbability;

            string mainProbabilityDescription;
            string otherProbabilityDescription;

            getUserCharData(mainProbability, otherProbability, mainProbabilityDescription, otherProbabilityDescription, desiredCharToChange);

            vectorOfCharsMain.push_back(mainProbability);
            vectorOfCharsOther.push_back(otherProbability);

            vectorOfDescriptionsMain.push_back(mainProbabilityDescription);
            vectorOfDescriptionsOther.push_back(otherProbabilityDescription);

            mainPercentages.push_back(mainPercentage);
            otherPercentages.push_back(otherPercentage);

            printUserCharData(vectorOfCharsMain, vectorOfCharsOther, vectorOfDescriptionsMain, vectorOfDescriptionsOther);
            displayPercentageData(mainPercentages, otherPercentages, vectorOfCharsMain, vectorOfCharsOther);

            /*
            Figure out how to replace all of the desired chars in the grid with the two new chars that the user will have chosen for that portion of the grid, but also keep the previous char stowed away somewhere so it can be used in descriptions above the grid
            */

        }

        else if (userInputString == "3") {

            string desiredChar;

            cout << "Enter the character denoting the probability you would like to see: ";
            getline(cin, desiredChar);

            findSpecificProbability(mainPercentages, otherPercentages, vectorOfCharsMain, vectorOfCharsOther, vectorOfDescriptionsMain, vectorOfDescriptionsOther, desiredChar);

        }

        else if (userInputString == "4") {

            cout << "GoodBye! Hope you enjoyed this probability calculator!" << endl;

            flag = true;

        }

        else {

            cout << "Wrong Input! Try Again" << endl;

        }

    }

}