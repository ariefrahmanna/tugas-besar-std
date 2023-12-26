#include "menu.h"

void menu_organisasi(list_organisasi &LP, list_mahasiswa &LC) {
    string input, nim, id_organisasi;
    info_organisasi info;
    adr_organisasi p;
    adr_anggota q;
    int n;

    while (true) {
        clear_screen();
        print_prompt_menu_organisasi();
        cout << "Pilih: ";
        cin >> input;

        if (input == "1") {     // insert data organisasi
            cout << "Masukkan data Organisasi" << endl;
            cout << "ID             : " ; cin >> info.id;
            cout << "Nama           : " ; cin >> info.nama;
            cout << "Bidang         : " ; cin >> info.bidang;
            cout << "Tahun Berdiri  : " ; cin >> info.sejak_tahun;

            if (search_organisasi(LP, info.id) != NULL) {
                cout << "!!! ORGANISASI SUDAH TERDATA !!!" << endl;
            } else {
                insert_last_organisasi(LP, create_elm_organisasi(info));
                cout << "=== ORGANISASI BERHASIL DITAMBAHKAN ===" << endl;
            }
        } else if (input == "2") {      // insert data anggota
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;

            while (search_organisasi(LP, id_organisasi) == NULL) {
                cout << "!!! ID ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }

            cout << "Masukkan NIM anggota   : ";
            cin >> nim;

            while (search_mahasiswa(LC, nim) == NULL) {
                cout << "!!! NIM TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan NIM anggota : ";
                cin >> nim;
            }

            p = search_organisasi(LP, id_organisasi);

            if (search_anggota(p, nim) != NULL) {
                cout << "!!! ANGGOTA SUDAH TERDATA !!!" << endl;
            } else {
                insert_anggota(LC, p, nim);
                cout << "=== ORGANISASI BERHASIL DITAMBAHKAN ===" << endl;
            }

            cout << "=== ANGGOTA BERHASIL DITAMBAHKAN ===" << endl;
        } else if (input == "3") {      // search data organisasi
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;

            p = search_organisasi(LP, id_organisasi);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "========   DATA ORGANISASI    ========" << endl;
                show_organisasi(p);
                cout << "======================================" << endl;
            }
        } else if (input == "4") {      // search data anggota
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            cout << "Masukkan NIM Anggota : ";
            cin >> nim;

            p = search_organisasi(LP, id_organisasi);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                q = search_anggota(p, nim);

                if (q == NULL) {
                    cout << "!!! ANGGOTA TIDAK DITEMUKAN !!!" << endl;
                } else {
                    cout << "========    DATA ANGGOTA     ========" << endl;
                    show_mahasiswa(q->value);
                    cout << "=====================================" << endl;
                }
            }
        } else if (input == "5") {      // delete data organisasi
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;

            delete_organisasi(LP, id_organisasi);
            cout << "DATA ORGANISASI BERHASIL DIHAPUS" << endl;
        } else if (input == "6") {      // delete data anggota
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            p = search_organisasi(LP, id_organisasi);

            while (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
                p = search_organisasi(LP, id_organisasi);
            }

            cout << "Masukkan NIM Anggota : ";
            cin >> nim;

            delete_anggota(p, nim);
            cout << "DATA ANGGOTA BERHASIL DIHAPUS" << endl;
        } else if (input == "7") {      // show data organisasi
            show_all_organisasi(LP);
        } else if (input == "8") {      // show data anggota
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;

            while (search_organisasi(LP, id_organisasi) == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }

            show_all_anggota(search_organisasi(LP, id_organisasi));
        } else if (input == "9") {      // hitung jumlah organisasi
            n = count_organisasi(LP);
            cout << "Jumlah Organisasi adalah " << n << endl;
        } else if (input == "10") {     // hitung jumlah anggota
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;

            while (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
                p = search_organisasi(LP, id_organisasi);
            }

            n = count_anggota(p);
            cout << "Jumlah Anggota Organisasi adalah " << n << endl;
        } else if (input == "11") {     // exit
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }
}

void menu_mahasiswa(list_mahasiswa &LP, list_prestasi &LC) {
    string input;
    while (true) {
        clear_screen();
        print_prompt_menu_organisasi();
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

void menu_prestasi(list_prestasi &L) {
    string input;
    while (true) {
        clear_screen();
        print_prompt_menu_organisasi();
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

void print_prompt_main_menu() {
    cout << "=============  MAIN MENU   =============" << endl;
    cout << "PILIH LIST: " << endl;
    cout << "1. ORGANISASI" << endl;
    cout << "2. MAHASISWA" << endl;
    cout << "3. PRESTASI" << endl;
    cout << "4. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_organisasi() {
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

void print_prompt_menu_mahasiswa() {
    cout << "=============  MAHASISWA  =============" << endl;
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

void print_prompt_menu_prestasi() {
    cout << "=============  PRESTASI  =============" << endl;
    cout << "1. INSERT DATA PRESTASI" << endl;
    cout << "2. SEARCH DATA PRESTASI" << endl;
    cout << "3. DELETE DATA PRESTASI" << endl;
    cout << "4. SHOW DATA PRESTASI" << endl;
    cout << "5. HITUNG JUMLAH PRESTASI" << endl;
    cout << "6. EXIT" << endl;
    cout << "========================================" << endl;
}
