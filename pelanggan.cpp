//#ifndef PELANGGAN_CPP_INCLUDED
//#define PELANGGAN_CPP_INCLUDED
#include <iostream>
#include "pelanggan.h"

void createList_P (List_P &L) {
    L.first_P = NULL;
    L.last_P = NULL;
}

address_P alokasi_P (string nama, string ttl, string noktp, string alamat, int usia) {
    address_P p;
    p = new elmlist_P;
    p->info_P.nama = nama;
    p->info_P.ttl = ttl;
    p->info_P.noktp = noktp;
    p->info_P.alamat = alamat;
    p->info_P.usia = usia;
    p->next_P = NULL;
    p->prev_P = NULL;

    return p;
}

void dealokasi_P (address_P &p) {
    delete p;
}

void insertFirst_P (List_P &L, address_P p) {
    if (L.first_P == NULL) {
        L.first_P = p;
        L.last_P = p;
        p->next_P = L.first_P;
        p->prev_P = L.last_P;
    }
    else {
        p->next_P = L.first_P;
        L.first_P->prev_P = p;
        L.first_P = p;
        L.last_P->next_P = L.first_P;
        p->prev_P = L.last_P;
    }
}
void insertAfter_P (List_P &L, address_P prec, address_P p) {
    if (L.first_P == NULL) {
        L.first_P = p;
        L.last_P = p;
        p->next_P = L.first_P;
        p->prev_P = L.last_P;
    }
    else {
        if (prec == L.last_P) {
            insertLast_P(L,p);
        }
        else {
            p->next_P = prec->next_P;
            p->next_P->prev_P = p;
            p->prev_P = prec;
            prec->next_P =p;
        }
    }
}

void insertLast_P (List_P &L, address_P p) {
    if (L.first_P == NULL && L.last_P == NULL) {
        L.first_P = p;
        L.last_P = p;
        L.last_P->next_P = L.first_P;
        p->prev_P = L.last_P;
    }
    else {
        L.last_P->next_P = p;
        p->prev_P = L.last_P;
        L.last_P = p;
        L.last_P->next_P = L.first_P;
    }
}

address_P findElm_P (List_P L, string cariktp) {
    address_P p;
    p = L.first_P;
    while (p->next_P != L.first_P && p->info_P.noktp != cariktp) {
        p = p->next_P;
    }
    if (p->info_P.noktp == cariktp) {
        return p;
    }
    else {
        return NULL;
    }
}

void deleteFirst_P (List_P &L, address_P &p) {
    if (L.first_P == NULL) {
        return;
    }
    else {
        if (L.first_P == L.last_P) {
            p = L.first_P;
            L.first_P = NULL;
            L.last_P = NULL;
        }
        else {
            p = L.first_P;
            L.first_P = L.first_P->next_P;
            L.first_P->prev_P = L.last_P;
            L.last_P ->next_P = L.first_P;
            p->next_P = NULL;
            p->prev_P = NULL;
        }
    }
}

void deleteAfter_P (List_P &L,address_P prec, address_P &p) {
    if (prec->next_P == NULL) {
        return;
    }
    else {
        p = prec->next_P;
        prec->next_P = p->next_P;
        p->next_P-> prev_P = prec;
        p->next_P = NULL;
        p->prev_P = NULL;
    }
}
void deleteLast_P (List_P &L, address_P &p) {
    if (L.first_P == NULL) {
        return;
    }
    else {
        if (L.first_P == L.last_P) {
            p = L.first_P;
            L.first_P = NULL;
            L.last_P = NULL;
        }
        else {
            p = L.last_P;
            L.last_P = L.last_P->prev_P;
            L.last_P->next_P = L.first_P;
            L.first_P->prev_P = L.last_P;
            p->next_P = NULL;
            p->prev_P = NULL;
        }
    }
}

void insertAscending_P (List_P &L, string nama, string ttl, string noktp, string alamat, int usia,address_P &r) {
    address_P p,q;
    p = alokasi_P(nama,ttl,noktp,alamat,usia);
    if (L.first_P == NULL) {
        insertFirst_P(L,p);
    }
    else {
        q = L.first_P;
        if (p->info_P.usia < L.first_P->info_P.usia) {
            insertFirst_P(L,p);
        }
        else {
            while ((q->next_P != NULL) && (q->next_P->info_P.usia < usia)) {
                q = q->next_P;
            }
            if (q->next_P == NULL) {
                insertLast_P(L, p);
            }
            else {
                insertAfter_P(L, q, p);
            }
        }
    }
}

void printInfo_P (List_P L) {
    address_P p;
    if (L.first_P == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        p = L.first_P;
        do {
            cout<<"No KTP : "<<p->info_P.noktp<<endl;
            cout<<"Nama : "<<p->info_P.nama<<endl;
            cout<<"TTL : "<<p->info_P.ttl<<endl;
            cout<<"Umur : "<<p->info_P.usia<<endl;
            cout<<"Alamat : "<<p->info_P.alamat<<endl;
            p = p->next_P;
        } while (p != L.first_P);
       // cout<<endl;
    }

}
//#endif
