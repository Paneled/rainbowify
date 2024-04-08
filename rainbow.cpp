#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

/*
 *    Black: \u001b[30m
 *    Red: \u001b[31m
 *    Green: \u001b[32m
 *    Yellow: \u001b[33m
 *    Blue: \u001b[34m
 *    Magenta: \u001b[35m
 *    Cyan: \u001b[36m
 *    White: \u001b[37m
 */
//return string from index
char *cycleColors(int index){
    switch (index) {
        case 1:
            return "\u001b[31m";
        case 2:
            return "\u001b[33m";
        case 3:
            return "\u001b[32m";
        case 4:
            return "\u001b[36m";
        case 5:
            return "\u001b[34m";
        case 6:
            return "\u001b[35m";
        default:
            return "";
    }
}

const int MAX_LENGTH = 5000; // provide memory

int main() {
    char inputString[MAX_LENGTH]; char rainbowString[MAX_LENGTH] = ""; //define variables

    cout << "Your string: "; // get user input
    cin.get(inputString, MAX_LENGTH); // assign user input to inputString

    int count = strlen(inputString); // get length of user input for the loop
    int index = 0; // make index

    // do shit
    for (int i = 0; i < count; ++i) { // for each character up to the count
        if(index >= 6){ // increment until 6, then reset
            index = 1;
        } else{
            index++;
        }
        char* result = cycleColors(index);
        strcat(rainbowString, result);
        strncat(rainbowString, &inputString[i], 1); //add prefix to the current character
        strcat(rainbowString, "\u001b[0m");
    }

    cout << rainbowString << endl; //echo string
    cout << "\u001b[37m";
}
