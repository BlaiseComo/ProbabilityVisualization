#include <iostream>
#include <iomanip>
#include <vector>

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

    while (flag == false) {

        string userInputString;
        displayMenu();
        getline(cin, userInputString);

        vector<char> vectorOfChars;

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

            cout << "Enter character to denote the main probability you gave earlier: ";
            getline(cin, mainProbability);

            cout << "Describe the main probability: ";
            getline(cin, mainProbabilityDescription);

            cout << "Enter character to denote the other probability: ";
            getline(cin, otherProbability);

            cout << "Describe the other probability: ";
            getline(cin, otherProbabilityDescription);

            cout << mainProbability << " - " << mainProbabilityDescription << endl;
            cout << otherProbability << " - " << otherProbabilityDescription << endl;

            for (int i = 0; i < totalNumOfGrids; i++) {

                if (i % 10 == 0) {
                    cout << endl;
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

            flag = true;

        }

        else if (userInputString == "2") {
            
            

        }

        else if (userInputString == "3") {



        }

        else if (userInputString == "4") {



        }

        else {



        }

    }

}