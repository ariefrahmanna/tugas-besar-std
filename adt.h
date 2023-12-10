#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;

void printScreen();

typedef struct elm_organisasi *adr_organisasi;
typedef struct elm_mahasiswa *adr_mahasiswa;
typedef struct elm_prestasi *adr_prestasi;
typedef struct elm_anggota *adr_anggota;
typedef struct elm_peraih *adr_peraih;

struct info_organisasi {
    string nama;
    string bidang;
    int sejak;
};

struct info_mahasiswa {
    string nim;
    string nama;
    string jurusan;
    string gender;
    int tahun;
};

struct info_prestasi {
    string nama;
    string bidang;
    int urutan;
};

struct elm_organisasi {
    info_organisasi info;
    adr_organisasi next;
};

struct elm_mahasiswa {
    info_mahasiswa info;
    adr_mahasiswa next;
};

struct elm_prestasi {
    info_prestasi info;
    adr_prestasi next;
};

struct elm_anggota {
    adr_anggota next;
    adr_mahasiswa value;
    // ... key;
};

struct elm_peraih {
    adr_peraih next;
    adr_prestasi value;
    // ... key;
};

struct list_organisasi {
    adr_organisasi first;
};

struct list_mahasiswa {
    adr_mahasiswa first;
};

struct list_prestasi {
    adr_prestasi first;
};

struct list_anggota {

};

#endif // ADT_H_INCLUDED
