#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

//#define next_B(p) p->next_B
//#define prev_B(p) p->prev_B
//#define info_B(p) p->info_B

using namespace std;

struct infotype_B {
    string bank;
    string kode;
    int jum;
};

typedef struct elmlist_B *address_B;
struct elmlist_B {
    infotype_B info_B;
    address_B next_B;
};

struct List_B {
    address_B first_B;
};


void createList_B (List_B &L);
address_B alokasi_B (string bank, string kode);
void dealokasi_B (address_B &p);
void insertFirst_B (List_B &L, address_B p);
address_B findElm_B (List_B L, string kode);
void deleteFirst_B (List_B &L, address_B &p);
void deleteLast_B (List_B &L, address_B &p);
void deleteAfter_B (List_B &L,address_B prec, address_B &p);
void printInfo_B (List_B L);


#endif // BANK_H_INCLUDED
