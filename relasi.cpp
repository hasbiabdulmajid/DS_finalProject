#ifndef RELASI_CPP_INCLUDED
#define RELASI_CPP_INCLUDED
#include "relasi.h"
void createList_R (List_R &L) {
    L.first_R = NULL;
}

address_R alokasi_R (address_P p, address_B q) {
    address_R r;
    r = new elmlist_R;
    r->info_R.pelanggan = p;
    r->info_R.bank = q;
    r->next_R = NULL;
    return r;
}

void dealokasi_R (address_R &p) {
    delete p;
}

void insertLast_R (List_R &L, address_R p) {
    if (L.first_R == NULL) {
        L.first_R = p;
    }
    else {
        address_R q = L.first_R;
        while (q->next_R != NULL) {
            q = q->next_R;
        }
        q->next_R = p;
    }
}

address_R findElm_R(List_R L, address_P p,address_B b){
        address_R r;

        if((p!=NULL) && (b!=NULL)) {
            r = L.first_R;
            while((r!=NULL) && (r->info_R.pelanggan!=p) || (r->info_R.bank!=b)){
                p=p->next_P;
            }

            if((r->info_R.pelanggan==p) && (r->info_R.bank==b)) {
                return r;
            }
            else {
                return NULL;
            }
        }
        else if(p!=NULL){
            r = L.first_R;
            while((r!=NULL) && (r->info_R.pelanggan!=p)){
                r=r->next_R;
            }

            if((r->info_R.pelanggan==p)) {
                return r;
            }
            else {
                return NULL;
            }
        }
        else if(b!=NULL){
            r = L.first_R;
            while((r!=NULL) && (r->info_R.bank!=b)){
                r=r->next_R;
            }

            if((r->info_R.bank==b)) {
                return r;
            }
            else {
                return NULL;
            }
        }

}

void deleteFirst_R (List_R &L, address_R &p) {
    if (L.first_R == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        if (L.first_R->next_R == NULL) {
            p = L.first_R;
            L.first_R = NULL;
        }
        else {
            p = L.first_R;
            L.first_R = next_R(p);
            next_R(p) = NULL;
        }
    }
}

void deleteLast_R (List_R &L, address_R &p) {
    address_R last;
    if (L.first_R == NULL)
        cout<<"List Kosong"<<endl;
    else {
        if (L.first_R->next_R == NULL) {
            p = L.first_R;
            L.first_R = NULL;
        }
        else {
            p = L.first_R;
            last = next_R(p);
            while (next_R(p)->next_R != NULL) {
                p = last;
                next_R(p) = NULL;
            }
            last = NULL;
            next_R(p) = NULL;
        }
    }
}

void deleteAfter_R(List_R &L, address_R prec, address_R &p) {
    if(L.first_R!=NULL){
            if(next_R(prec)!=NULL){
                p = next_R(prec);
                next_R(prec) = next_R(p);
                next_R(p) = NULL;
            }
        }
}

void deleteRelasi(List_R &LR,List_P LP,List_B LB){
        string cariktp,carikode;

        address_P pelangganE1;
        address_B bankE2;
        address_R cariR;
            cout<<"No KTP  = ";
            cin>>cariktp;
            cout<<"Kode Bank = ";
            cin>>carikode;
            pelangganE1 = findElm_P(LP,cariktp);
            bankE2 = findElm_B(LB,carikode);

            if((pelangganE1!=NULL) && (bankE2 != NULL)) {
                cariR = findElm_R(LR,pelangganE1,bankE2);
                if(cariR!=NULL) {
                    if(LR.first_R==cariR) {
                        deleteFirst_R(LR,cariR);
                        cout<<"DATA TERHAPUS !!!"<<endl;
                    }
                    else if(cariR->next_R==NULL) {
                        deleteLast_R(LR,cariR);
                        cout<<"DATA TERHAPUS !!!"<<endl;
                    }
                    else {
                        address_R prec = LR.first_R;
                        while(prec->next_R!=cariR){
                            prec=prec->next_R;
                        }
                        deleteAfter_R(LR,prec,cariR);
                        cout<<"DATA TERHAPUS !!!"<<endl;
                    }
                }
                else {
                    cout<<"NIP atau NIS TIDAK ADA!!"<<endl;

                }
            }
            else if(pelangganE1==NULL) {
                cout<<"No KTP TIDAK DITEMUKAN!!"<<endl;
            }
            else {
                cout<<"KODE BANK TIDAK DITEMUKAN!!"<<endl;
            }
}

void printInfo_R(List_R LR,List_P LP,List_B LB,int tipe){
    if(LR.first_R!=NULL){
        if(tipe==1){
                address_P tempP_sebelumnya;
                address_P tempP_pelanggan;

                address_B tempB_bank;
                int i=1;
                cout<<endl;
                cout<< "==================================================="<<endl;
                cout<< "=      List Data Relasi Pelanggan Dengan Bank     ="<<endl;
                cout<< "==================================================="<<endl;
                cout<< "= No.| Nama Pelanggan |  Bank Dilanggan           ="<<endl;
                cout<< "==================================================="<<endl;

                        address_R p = LR.first_R;
                        while(p!=NULL){
                            tempP_pelanggan = p->info_R.pelanggan;
                            if(tempP_pelanggan!= tempP_sebelumnya){
                                cout <<"= "<<i<<" ";
                                cout <<" | "<<  tempP_pelanggan->info_P.nama   <<"     ";
                                cout<<endl;

                                    address_R x = LR.first_R;
                                    while(x!=NULL) {
                                        if(tempP_pelanggan == x->info_R.pelanggan) {
                                            tempB_bank = x->info_R.bank;
                                            cout<<"                   "<<tempB_bank->info_B.bank<<endl;
                                        }
                                        x = x->next_R;
                                    }

                                cout << endl;
                                i++;
                            }

                            tempP_sebelumnya = p->info_R.pelanggan;
                            p = p->next_R;
                        }

                cout<< "==================================================="<<endl;
        }
        else if(tipe==2){
            address_R p = LR.first_R;
            address_B w;

            address_B q;
            address_P r;
            int i=1;
                cout<<endl;
                cout<< "==================================================="<<endl;
                cout<< "=       List Data Relasi Bank Yang Dilanggan      ="<<endl;
                cout<< "==================================================="<<endl;
                cout<< "= No.| Bank |  Dilanggan Oleh                   ="<<endl;
                cout<< "==================================================="<<endl;


                    while(p!=NULL){
                        q = p->info_R.bank;

                        if(q!=w){
                        cout <<"= "<<i<<" ";
                        cout <<" | "<<  q->info_B.bank   <<"     ";
                        cout<<endl;

                        address_R x = LR.first_R;
                            while(x!=NULL) {
                                if(q == x->info_R.bank) {
                                    r = x->info_R.pelanggan;
                                    cout<<"                   "<<r->info_P.nama<<endl;
                                }
                                x = x->next_R;
                            }
                        cout << endl;
                        i++;
                        }

                        w = p->info_R.bank;
                        p = p->next_R;



                    }

                cout<< "==================================================="<<endl;
        }
    }
    else {
        cout<<"RELASI KOSONG"<<endl;
    }

}

/*void deletePelangganByID(List_R LR,List_P LP,string cariktp){

    address_R q;
    if (LP.first_P==NULL){
        cout << "PELANGGAN TIDAK DITEMUKAN";
    }
    else{
        address_R p = LR.first_R;
        address_R last = LR.first_R;
        while (last->next_R != NULL) {
            last = last->next_R;
        }
        while(p!=NULL){
            if (p->info_R.pelanggan->info_P.noktp == cariktp){
                if(p==LR.first_R){
                    deleteFirst_R(LR,p);
                }
                else if (p==last){
                    deleteLast_R(LR,p);
                }
                else{
                    address_R prec;
                    while (prec->next_R != p) {
                        prec = prec->next_R;
                    }
                    deleteAfter_R(LR,prec,p);
                }
            }
        }
    }
}

void deletePelangganAsli(List_R &LR,List_P &LP,string cariktp){
    deletePelangganByID(LR,LP,cariktp);
    address_P p = findElm_P(LP,cariktp);
    if (p!=NULL){
        address_P q;
        if(p==LP.first_P){
            deleteFirst_P(LP,q);
        }
        else if(p==LP.last_P){
            deleteLast_P(LP,q);
        }
        else{
            address_P prec = p->prev_P;
            deleteAfter_P(LP,prec,q);
        }
    }
}*/



#endif // RELASI_CPP_INCLUDED
