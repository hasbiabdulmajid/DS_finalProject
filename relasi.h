#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "pelanggan.h"
#include "bank.h"

#define next_R(p) p->next_R
#define info_R(p) p->info_R

using namespace std;

struct infotype_R {
    address_P pelanggan;
    address_B bank;
};

typedef struct elmlist_R *address_R;

struct elmlist_R {
    infotype_R info_R;
    address_R next_R;
};

struct List_R {
    address_R first_R;
};


void createList_R (List_R &L);
address_R alokasi_R (address_P p, address_B q);
void dealokasi_R (address_R &p);
void insertLast_R (List_R &L, address_R p);
void insertFirst_R (List_R &L, address_R p);
address_R findElm_R(List_R L, address_P p,address_B b);
void deleteFirst_R (List_R &L, address_R &p);
void deleteLast_R (List_R &L, address_R &p);
void deleteAfter_R (List_R &L,address_R prec, address_R &p);
void deleteRelasi(List_R &LR,List_P LP,List_B LB);
void printInfo_R(List_R LR,List_P LP,List_B LB,int tipe);
//void deletePelangganAsli(List_R &LR,List_P &LP,string cariktp);
//void deletePelangganByID(List_R LR,List_P LP,string cariktp);


#endif // RELASI_H_INCLUDED

