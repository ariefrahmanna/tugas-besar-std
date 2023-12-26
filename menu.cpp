#include "menu.h"
void menu_organisasi(){
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi()
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            //insert Data Organisasi
        } else if (input == "2") {
            //insert Data Anggota
        } else if (input == "3") {
            //search data organisasi
        } else if (input == "4") {
            //search data anggota
        } else if (input == "5") {
            //delete data organisasi
        } else if (input == "6") {
            //delete data anggota
        } else if (input == "7") {
            //show data organisasi
        } else if (input == "8") {
            //show data anggota
        } else if (input == "9") {
            //hitung jumlah organisasi
        } else if (input == "10") {
            //hitung jumlah anggota
        } else if (input == "11") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }
}
void menu_mahasiswa(){
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi()
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            //insert data mahasisiwa
        } else if (input == "2") {
            //insert data peraih
        } else if (input == "3") {
            //search data mahasiswa
        } else if (input == "4") {
            //search data peraih
        } else if (input == "5") {
            //delete data mahasisiwa
        } else if (input == "6") {
            //delete data peraih
        } else if (input == "7") {
            //show data peraih
        } else if (input == "8") {
            //show data peraih
        } else if (input == "9") {
            //hitung jumlah mahasisiwa
        } else if (input == "10") {
            //hitung jumlah peraih
        } else if (input == "11") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }
}
void menu_prestasi(){
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi()
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            //insert data prestasi
        } else if (input == "2") {
            //search data prestasi
        } else if (input == "3") {
            //delete data prestasi
        } else if (input == "4") {
            //show data prestasi
        } else if (input == "5") {
            //hitung jumlah prestasi
        } else if (input == "6") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }

}
void print_prompt_main_menu(){
    cout << "=============  MAIN MENU   =============" << endl;
    cout << "PILIH LIST: " << endl;
    cout << "1. ORGANISASI" << endl;
    cout << "2. MAHASISWA" << endl;
    cout << "3. PRESTASI" << endl;
    cout << "4. EXIT" << endl;
    cout << "========================================" << endl;
}
void print_prompt_menu_organisasi(){
    cout << "=============  ORGANISASI  =============" << endl;
    cout << "1. INSERT DATA ORGANISASI" << endl;
    cout << "2. INSERT DATA ANGGOTA" << endl;
    cout << "3. SEARCH DATA ORGANISASI" << endl;
    cout << "4. SEARCH DATA ANGGOTA" << endl;
    cout << "5. DELETE DATA ORGANISASI" << endl;
    cout << "6. DELETE DATA ANGGOTA" << endl;
    cout << "7. SHOW DATA ORGANISASI" << endl;
    cout << "8. SHOW DATA ANGGOTA" << endl;
    cout << "9. HITUNG JUMLAH ORGANISASI" << endl;
    cout << "10. HITUNG JUMLAH ANGGOTA" << endl;
    cout << "11. EXIT" << endl;
    cout << "========================================" << endl;
}
void print_prompt_menu_mahasiswa(){
    cout << "=============  ORGANISASI  =============" << endl;
    cout << "1. INSERT DATA MAHASISWA" << endl;
    cout << "2. INSERT DATA PERAIH PRESTASI" << endl;
    cout << "3. SEARCH DATA MAHASISWA" << endl;
    cout << "4. SEARCH DATA PERAIH PRESTASI" << endl;
    cout << "5. DELETE DATA MAHASISWA" << endl;
    cout << "6. DELETE DATA PERAIH PRESTASI" << endl;
    cout << "7. SHOW DATA MAHASISWA" << endl;
    cout << "8. SHOW DATA PERAIH PRESTASI" << endl;
    cout << "9. HITUNG JUMLAH MAHASISWA" << endl;
    cout << "10. HITUNG JUMLAH PERAIH PRESTASI" << endl;
    cout << "11. EXIT" << endl;
    cout << "========================================" << endl;
}
void print_prompt_menu_prestasi(){
    cout << "=============  ORGANISASI  =============" << endl;
    cout << "1. INSERT DATA PRESTASI" << endl;
    cout << "2. SEARCH DATA PRESTASI" << endl;
    cout << "3. DELETE DATA PRESTASI" << endl;
    cout << "4. SHOW DATA PRESTASI" << endl;
    cout << "5. HITUNG JUMLAH PRESTASI" << endl;
    cout << "6. EXIT" << endl;
    cout << "========================================" << endl;

}
