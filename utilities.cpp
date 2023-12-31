#include "utilities.h"

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
    cout << WAIT_FOR_ENTER_PROMPT;
    fflush(stdin);
    getchar();
    cout << endl;
}
