#ifndef PELANGGAN_H_INCLUDED
#define PELANGGAN_H_INCLUDED
#include <iostream>

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info

using namespace std;

struct infotype_P {
    string nama;
    string ttl;
    int usia;
    string noktp;
    int jum;
    string alamat;
};

typedef struct elmlist_P *address_P;

struct elmlist_P {
    infotype_P info_P;
    address_P next_P;
    address_P prev_P;
};

struct List_P {
    address_P first_P;
    address_P last_P;
};

void createList_P (List_P &L);
address_P alokasi_P (string nama, string ttl, string noktp, string alamat, int usia);
void dealokasi_P (address_P &p);
void insertFirst_P (List_P &L, address_P p);
void insertAfter_P (List_P &L, address_P prec, address_P p);
void insertLast_P (List_P &L, address_P p);
address_P findElm_P (List_P L, string noktp);
void deleteFirst_P (List_P &L, address_P &p);
void deleteAfter_P (List_P &L,address_P prec, address_P &p);
void deleteLast_P (List_P &L, address_P &p);
void insertAscending (List_P &L, string nama, string ttl, string noktp, string alamat, int usia,address_P &r);
void printInfo_P (List_P L);





#endif // ENTITAS1_H_INCLUDED
