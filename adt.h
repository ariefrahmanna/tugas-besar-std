#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct elm_organisasi *adr_organisasi;
typedef struct elm_mahasiswa *adr_mahasiswa;
typedef struct elm_prestasi *adr_prestasi;
typedef struct elm_anggota *adr_anggota;
typedef struct elm_peraih *adr_peraih;

struct info_organisasi {
    string id;
    string nama;
    string bidang;
    int sejak_tahun;
};

struct info_mahasiswa {
    string nim;
    string nama;
    string jurusan;
    string gender;
    int angkatan;
};

struct info_prestasi {
    string id;
    string nama;
    string bidang;
    int urutan;
};

struct elm_organisasi {
    info_organisasi info;
    adr_organisasi next;
    adr_anggota anggota;
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
    string nim; 
};

struct elm_peraih {
    adr_peraih next;
    adr_prestasi value;
    string id_prestasi;
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

// create list
void create_list_organisasi(list_organisasi &L);
void create_list_mahasiswa(list_mahasiswa &L);
void create_list_prestasi(list_prestasi &L);
// create element
adr_organisasi create_elm_organisasi(info_organisasi x);
adr_mahasiswa create_elm_mahasiswa(info_mahasiswa x);
adr_prestasi create_elm_presadr_prestasi(info_presadr_prestasi x);
// insert
void insert_first_organisasi(list_organisasi &L, adr_organisasi p);
void insert_first_mahasiswa(list_mahasiswa &L, adr_mahasiswa p);
void insert_first_prestasi(list_prestasi &L, adr_prestasi p);
void insert_last_organisasi(list_organisasi &L, adr_organisasi p);
void insert_last_mahasiswa(list_mahasiswa &L, adr_mahasiswa p);
void insert_last_prestasi(list_prestasi &L, adr_prestasi p);
// delete
adr_organisasi delete_last_organisasi(list_organisasi &L);
adr_mahasiswa delete_last_mahasiswa(list_mahasiswa &L);
adr_prestasi delete_last_prestasi(list_prestasi &L);
// searching
adr_organisasi search_organisasi(list_organisasi L, string id_organisasi);
adr_mahasiswa search_mahasiswa(list_mahasiswa L, string nim);
adr_prestasi search_prestasi(list_prestasi L, string id_prestasi);


// insert relation
void insert_anggota(adr_organisasi p, string nim);
void insert_peraih(adr_mahasiswa p, string id_prestasi);
// delete relation
void delete_anggota(adr_organisasi p, string nim);
void delete_peraih(adr_mahasiswa p, string id_prestasi);
// show data
void show_all_organisasi(list_organisasi L);
void show_all_mahasiswa(list_mahasiswa L);
void show_all_prestasi(list_prestasi L);
void show_anggota(list_organisasi L, string id_organisasi);
void show_peraih(list_mahasiswa L, string nim);

#endif // ADT_H_INCLUDED
