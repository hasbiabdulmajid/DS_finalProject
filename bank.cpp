//#ifndef BANK_CPP_INCLUDED
//#define BANK_CPP_INCLUDED
#include <iostream>
#include "bank.h"

void createList_B (List_B &L) {
    L.first_B = NULL;
}

address_B alokasi_B (string bank, string kode) {
    address_B p;
    p = new elmlist_B;
    p->info_B.bank = bank;
    p->info_B.kode = kode;
    p->next_B = NULL;
    return p;
}

void dealokasi_B (address_B &p) {
    delete p;
}

void insertFirst_B (List_B &L, address_B p) {
    if (L.first_B == NULL) {
        L.first_B = p;
    }
    else {
        p->next_B = L.first_B;
        L.first_B = p;
    }
}
address_B findElm_B (List_B L, string carikode) {
    address_B p;
    p = L.first_B;
    while (p->next_B != NULL && p->info_B.kode != carikode) {
        p = p->next_B;
    }
    if (p->info_B.kode == carikode)
        return p;
    else
        return NULL;
}

void deleteFirst_B (List_B &L, address_B &p) {
    if (L.first_B == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        if (L.first_B->next_B == NULL) {
            p = L.first_B;
            L.first_B = NULL;
        }
        else {
            p = L.first_B;
            L.first_B = p->next_B;
            p->next_B = NULL;
        }
    }
}

void deleteLast_B (List_B &L, address_B &p) {
    address_B last;
    if (L.first_B == NULL)
        cout<<"List Kosong"<<endl;
    else {
        if (L.first_B->next_B == NULL) {
            p = L.first_B;
            L.first_B = NULL;
        }
        else {
            p = L.first_B;
            last = p->next_B;
            while (p->next_B->next_B != NULL) {
                p = last;
                p->next_B = NULL;
            }
            last = NULL;
            p->next_B = NULL;
        }
    }
}

void deleteAfter_B(List_B &L, address_B prec, address_B &p) {
    if(L.first_B!=NULL){
            if(prec->next_B!=NULL){
                p = prec->next_B;
                prec->next_B = p->next_B;
                p->next_B = NULL;
            }
        }
}

void printInfo_B (List_B L) {
    address_B p;
    if (L.first_B == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        p = L.first_B;
        while (p != NULL) {
            cout<<"Kode Bank : ";
            cout<<p->info_B.kode<<endl;
            cout<<"Nama Bank : ";
            cout<<p->info_B.bank<<endl;
            cout<<endl;
            p = p->next_B;
        }
        cout<<endl;
    }
}
//#endif
