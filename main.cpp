#include "adt.h"
#include "menu.h"
#include "utilities.h"

using namespace std;

int main() {
    list_organisasi L1;
    list_mahasiswa L2;
    list_prestasi L3;
    string input;

    while (true) {
        clear_screen();
        // print_prompt();
        cout << "Pilih [1/2/3/4]: ";
        cin >> input;

        if (input == "1") {
            menu_organisasi();
        } else if (input == "2") {
            menu_mahasiswa();
        } else if (input == "3") {
            menu_prestasi();
        } else if (input == "4") {
            break;
        } else {
            // TODO
            // cetak "salah input!"
            wait_for_enter();
        }
    }

    clear_screen();
    cout << "bye" << endl;

    return 0;
}
