#include "adt.h"

void create_list_organisasi(list_organisasi &L) {
    L.first = NULL;
}

void create_list_mahasiswa(list_mahasiswa &L) {
    L.first = NULL;
}



adr_organisasi create_elm_organisasi(info_organisasi x) {
    adr_organisasi p = new elm_organisasi();

    p->info = x;
    p->next = NULL;
    p->anggota = NULL;

    return p;
}


adr_prestasi create_elm_prestasi(info_prestasi x) {
    adr_prestasi p = new elm_prestasi();

    p->info = x;
    p->next = NULL;

    return p;
}

void insert_first_organisasi(list_organisasi &L, adr_organisasi p) {
    if (L.first != NULL) {
        p->next = L.first;
    }

    L.first = p;
}

void insert_first_mahasiswa(list_mahasiswa &L, adr_mahasiswa p) {
    if (L.first != NULL) {
        p->next = L.first;
    }

    L.first = p;
}

void insert_last_organisasi(list_organisasi &L, adr_organisasi p) {
    adr_organisasi last;

    if (L.first == NULL) {
        L.first = p;
    } else {
        last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = p;
    }
}

void insert_last_mahasiswa(list_mahasiswa &L, adr_mahasiswa p) {
    adr_mahasiswa last;

    if (L.first == NULL) {
        L.first = p;
    } else {
        last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = p;
    }
}


adr_organisasi delete_organisasi(list_organisasi &L, string id_organisasi) {
    adr_organisasi p, prec;

    p = search_organisasi(L, id_organisasi);

    if (p == NULL) return NULL;

    if (p == L.first) {
        L.first = L.first->next;
    } else {
        prec = L.first;

        while (prec->next != p) {
            prec = prec->next;
        }

        prec->next = p->next;
    }

    p->next = NULL;

    return p;
}

adr_mahasiswa delete_mahasiswa(list_mahasiswa &L, string nim) {
    adr_mahasiswa p, prec;

    p = search_mahasiswa(L, nim);

    if (p == NULL) return NULL;

    if (p == L.first) {
        L.first = L.first->next;
    } else {
        prec = L.first;

        while (prec->next != p) {
            prec = prec->next;
        }

        prec->next = p->next;
    }

    p->next = NULL;

    return p;
}



adr_organisasi search_organisasi(list_organisasi L, string id_organisasi) {
    adr_organisasi p = L.first;

    while (p != NULL) {
        if (p->info.id == id_organisasi) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

adr_mahasiswa search_mahasiswa(list_mahasiswa L, string nim) {
    adr_mahasiswa p = L.first;

    while (p != NULL) {
        if (p->info.nim == nim) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void edit_organisasi(adr_organisasi p, string new_nama, string new_bidang, int new_sejak_tahun) {
    p->info.nama = new_nama;
    p->info.bidang = new_bidang;
    p->info.sejak_tahun = new_sejak_tahun;
}

void edit_mahasiswa(adr_mahasiswa p, string new_nama, string new_jurusan) {
    p->info.nama = new_nama;
    p->info.jurusan = new_jurusan;
}

void edit_prestasi(adr_prestasi p, string new_nama, string new_bidang, int new_urutan) {
    p->info.nama = new_nama;
    p->info.bidang = new_bidang;
    p->info.urutan = new_urutan;
}

int count_organisasi(list_organisasi L) {
    int n = 0;
    adr_organisasi p = L.first;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

int count_mahasiswa(list_mahasiswa L) {
    int n = 0;
    adr_mahasiswa p = L.first;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

void show_all_organisasi(list_organisasi L) {
    adr_organisasi p = L.first;
    if (L.first == NULL) {
        cout << "==========    LIST  KOSONG    ==========" << endl;
    } else {
        cout << "==========     ORGANISASI     ==========" << endl;
        cout << endl;

        while (p != NULL) {
            cout << "ID             :" << p->info.id << endl;
            cout << "NAMA           :" << p->info.nama << endl;
            cout << "BIDANG         :" << p->info.bidang << endl;
            cout << "TAHUN BERDIRI  :" << p->info.sejak_tahun << endl;
            cout << endl;
            p = p->next;
        }

        cout << "========================================" << endl;
    }
}

void show_all_mahasiswa(list_mahasiswa L) {
    adr_mahasiswa p = L.first;
    if (L.first == NULL) {
        cout << "==========    LIST KOSONG    ==========" << endl;
    } else {
        cout << "==========     MAHASISWA     ==========" << endl;
        cout << endl;

        while (p != NULL) {
            cout << "NIM        :" << p->info.nim << endl;
            cout << "NAMA       :" << p->info.nama << endl;
            cout << "JURUSAN    :" << p->info.jurusan << endl;
            cout << "GENDER     :" << p->info.gender << endl;
            cout << "ANGKATAN   :" << p->info.angkatan << endl;
            cout << endl;
            p = p->next;
        }

        cout << "=======================================" << endl;
    }
}

void show_organisasi(adr_organisasi p) {
    if (p == NULL) {
        cout << "======= DATA KOSONG ========" << endl;
        return;
    }

    cout << "ID             :" << p->info.id << endl;
    cout << "NAMA           :" << p->info.nama << endl;
    cout << "BIDANG         :" << p->info.bidang << endl;
    cout << "TAHUN BERDIRI  :" << p->info.sejak_tahun << endl;
}

void show_mahasiswa(adr_mahasiswa p) {
    if (p == NULL) {
        cout << "======= DATA KOSONG ========" << endl;
        return;
    }

    cout << "NIM        :" << p->info.nim << endl;
    cout << "NAMA       :" << p->info.nama << endl;
    cout << "JURUSAN    :" << p->info.jurusan << endl;
    cout << "GENDER     :" << p->info.gender << endl;
    cout << "ANGKATAN   :" << p->info.angkatan << endl;
}

void show_prestasi(adr_prestasi p) {
    if (p == NULL) {
        cout << "======= DATA KOSONG ========" << endl;
        return;
    }

    cout << "ID         :" << p->info.id << endl;
    cout << "NAMA       :" << p->info.nama << endl;
    cout << "BIDANG     :" << p->info.bidang << endl;
    cout << "URUTAN     :" << p->info.urutan << endl;
}

adr_anggota search_anggota(adr_organisasi p, string nim) {
    adr_anggota q = p->anggota;

    while (q != NULL) {
        if (q->nim == nim) {
            return q;
        }

        q = q->next;
    }

    return NULL;
}
adr_prestasi search_prestasi(adr_mahasiswa p, string id_prestasi){
    adr_prestasi q = p->prestasi;

    while (q != NULL) {
        if (q->info.id == id_prestasi) {
            return q;
        }

        q = q->next;
    }

    return NULL;
}

void insert_anggota(list_mahasiswa L, adr_organisasi p, string nim) {
    adr_mahasiswa q = search_mahasiswa(L, nim);
    adr_anggota r, s;

    if (q != NULL) {
        r = new elm_anggota;
        r->next = NULL;
        r->value = q;
        r->nim = q->info.nim;

        if (p->anggota == NULL) {
            p->anggota = r;
        } else {
            s = p->anggota;
            while (s->next != NULL) {
                s = s->next;
            }

            s->next = r;
        }
    }
}

void insert_prestasi(adr_mahasiswa p, adr_prestasi q){
    adr_prestasi last;

    if (p->prestasi == NULL) {
        p->prestasi = q;
    } else {
        last = p->prestasi;

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = q;
    }
}

adr_anggota delete_anggota(adr_organisasi p, string nim) {
    adr_anggota q = search_anggota(p, nim);
    adr_anggota r;

    if (q != NULL) {
        if (q == p->anggota) {
            p->anggota = p->anggota->next;
        } else {
            r = p->anggota;

            while (r->next != q) {
                r = r->next;
            }

            r->next = q->next;
        }

        q->next = NULL;

        return q;
    }

    return NULL;
}

adr_prestasi delete_prestasi(adr_mahasiswa p, string id_prestasi) {
    adr_prestasi q = search_prestasi(p, id_prestasi);
    adr_prestasi prec;

    if (q != NULL) {
        if (q == p->prestasi) {
            p->prestasi = p->prestasi->next;
        } else {
            prec = p->prestasi;

            while (prec->next != q) {
                prec = prec->next;
            }

            prec->next = q->next;
        }

        q->next = NULL;

        return q;
    }

    return NULL;

}


int count_anggota(adr_organisasi p) {
    int n = 0;
    adr_anggota q = p->anggota;

    while (q != NULL) {
        q = q->next;
        n++;
    }

    return n;
}

int count_prestasi(adr_mahasiswa p){
    int n = 0;
    adr_prestasi q = p->prestasi;

    while (q != NULL) {
        q = q->next;
        n++;
    }

    return n;
}

void show_all_anggota(adr_organisasi p) {
    adr_anggota q = p->anggota;

    if (q == NULL) {
        cout << "======= LIST KOSONG ========" << endl;
    } else {
        while (q != NULL) {
            cout << "========    DATA ANGGOTA     ========" << endl;
            cout << "NIM        :" << q->value->info.nim << endl;
            cout << "NAMA       :" << q->value->info.nama << endl;
            cout << "JURUSAN    :" << q->value->info.jurusan << endl;
            cout << "GENDER     :" << q->value->info.gender << endl;
            cout << "ANGKATAN   :" << q->value->info.angkatan << endl;
            cout << "=====================================" << endl;
            cout << endl;

            q = q->next;
        }
    }
}

void show_prestasi(adr_prestasi p) {
    cout << "ID         :" << p->info.id << endl;
    cout << "NAMA       :" << p->info.nama << endl;
    cout << "BIDANG     :" << p->info.bidang << endl;
    cout << "URUTAN     :" << p->info.urutan << endl;
}
