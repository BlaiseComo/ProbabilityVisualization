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

void getUserCharData(string &mainProbability, string &otherProbability, string &mainProbabilityDescription, string &otherProbabilityDescription) {

    cout << "Enter character to denote the main probability you gave earlier: ";
    getline(cin, mainProbability);

    cout << "Describe the main probability: ";
    getline(cin, mainProbabilityDescription);

    cout << "Enter character to denote the other probability: ";
    getline(cin, otherProbability);

    cout << "Describe the other probability: ";
    getline(cin, otherProbabilityDescription);

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
    cout << "1. Start a probability grid" << endl;
    cout << "2. Edit part of the probablity grid (Instructions will follow if you choose this option)" << endl;
    cout << "3. Calculate probability of a given outcome" << endl;
    cout << "4. Quit" << endl;

}

int main() {

    bool flag = false;

    cout << "Welcome to the probability grid!" << endl;

    vector<char> vectorOfChars;

    while (flag == false) {

        string userInputString;
        displayMenu();
        getline(cin, userInputString);

        if (userInputString == "1") {

            vectorOfChars.clear();

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

            getUserCharData(mainProbability, otherProbability, mainProbabilityDescription, otherProbabilityDescription);

            cout << mainProbability << " - " << mainProbabilityDescription << endl;
            cout << otherProbability << " - " << otherProbabilityDescription << endl;

            bool flag2 = false;

            for (int i = 0; i < totalNumOfGrids; i++) {

                if (i >= numeratorInt && flag2 == false) {
                    cout << endl;
                    flag2 = true;
                }

                if (i < numeratorInt) {
                    
                    vectorOfChars.push_back(mainProbability[0]);

                    cout << "[" << mainProbability << "]";

                }

                else if (i >= numeratorInt) {

                    vectorOfChars.push_back(otherProbability[0]);

                    cout << "[" << otherProbability << "]";
                }
                
            }

            cout << endl;

        }

        /*
        This else if statement will ask the user what character of the grid they want to edit, and then essentially repeat most of the functionality of else if 1 for that part of the grid
        In the description above the grid, say that the new chars are a subset of their old char
        */

        else if (userInputString == "2") {
            
            string desiredCharToChange;
    
            cout << "What part of the current probability grid would you like to change? (input the character that represents that gridspace) ";
            getline(cin, desiredCharToChange);

            char desiredChar = desiredCharToChange[0];

            int vectorSize = vectorOfChars.size();

            int numOfChars = 0;

            for (int i = 0; i < vectorSize; i++) {
                
                if (vectorOfChars[i] == desiredChar) {

                    numOfChars++;

                }

            }

            string userInputFraction;
            string denominator;
            string numerator;

            cout << "What is the probability of this instance happening inside the instance you have chosen (enter your input as a fraction with /) ";
            getline(cin, userInputFraction);

            getFractionValues(userInputFraction, denominator, numerator);

            int denominatorInt = stoi(denominator);
            int numeratorInt = stoi(numerator);

            double userDecimal = (float)numeratorInt / (float)denominatorInt;

            int finalUserIntNumerator = round(userDecimal * (float)numOfChars);

            flag = true;

        }

        else if (userInputString == "3") {



        }

        else if (userInputString == "4") {



        }

        else {



        }

    }

}