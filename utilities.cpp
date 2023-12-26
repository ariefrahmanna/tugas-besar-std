#include "utilities.h"
#include <stdio.h>

void validate_repeat(string &input, string prompt) {
    input = "";

    while (input != "y" && input != "n" && input != "Y" && input != "N") {
        cout << prompt;
        cin >> input;
    }
}

void clear_screen() {
    printf("\033[H\033[2J");
}

void wait_for_enter() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
