#include <iostream>

#include "pelanggan.h"
#include "bank.h"
#include "relasi.h"
#include <cstdlib>

using namespace std;

void insertPelanggan (List_P &LP) {
    string nama,noid,alamat,ttlahir;
    int usia;
    cout<<"Nama : ";
    cin>>nama;
    cout<<"No KTP : ";
    cin>>noid;
    cout<<"Tempat Tanggal Lahir : ";
    cin>>ttlahir;
    cout<<"Alamat : ";
    cin>>alamat;
    cout<<"Umur : ";
    cin>>usia;
    address_P p = alokasi_P(nama,ttlahir,noid,alamat,usia);
    insertFirst_P(LP,p);
    //insertAscending(LP, nama,ttlahir,noid,alamat,usia,p);
}
void deletePelanggan (List_P &LP, List_R &LR) {
    string noktp;
    cout<<"Masukan No KTP pelanggan yang mau dihapus : ";
    cin>>noktp;
}

void updatePelanggan (List_P &L) {
    string cari;
    printInfo_P(L);
    cout<<"no ktp : ";
    cin>>cari;
    address_P p = findElm_P(L,cari);

    if (p != NULL) {
        cout<<"Nama : ";
        cin>>p->info_P.nama;
        cout<<"No KTP : ";
        cin>>p->info_P.noktp;
        cout<<"Tempat Tanggal Lahir : ";
        cin>>p->info_P.ttl;
        cout<<"Alamat : ";
        cin>>p->info_P.alamat;
        cout<<"Umur : ";
        cin>>p->info_P.usia;

    }
    else {
        cout<<"Pelanggan dengan no KTP "<<cari<<" tidak ditemukan"<<endl;
    }
}
void insertBank (List_B &LB) {
    string bank,kode;
    cout<<"Nama Bank : ";
    cin>>bank;
    cout<<"Kode Bank : ";
    cin>>kode;
    address_B p = alokasi_B(bank,kode);
    insertFirst_B(LB, p);
}
void updateBank (List_B &LB) {
    string cari;
    printInfo_B(LB);
    cout<<"Kode Bank : ";
    cin>>cari;
    address_B p = findElm_B(LB, cari);
    if (p != NULL) {
        cout<<"Nama Bank : ";
        cin>>p->info_B.bank;
        cout<<"Kode Bank : ";
        cin>>p->info_B.kode;
    }
    else {
        cout<<"Bank dengan kode "<<cari<<" tidak ditemukan"<<endl;
    }

}
void insertRelasi (List_P LP, List_B LB, List_R &LR) {
    string cariktp,carikbank;
    cout<<"No KTP : ";
    cin>>cariktp;
    cout<<"Kode Bank : ";
    cin>>carikbank;
    address_P p = findElm_P(LP,cariktp);
    address_B q = findElm_B(LB,carikbank);
    if (p != NULL && q != NULL) {
        address_R r = alokasi_R(p,q);
        insertLast_R(LR,r);
    }
    else if (p != NULL) {
        cout<<"Bank dengan kode "<<carikbank<<" tidak ada"<<endl;
    }
    else {
        cout<<"Pelanggan dengan No KTP "<<cariktp<<" tidak ada"<<endl;
    }
}

int main()
{
    List_P Lcust;
    List_B Lbank;
    List_R LR;
    char menu;
    createList_P(Lcust);
    createList_B(Lbank);
    createList_R(LR);
    do {
        system("cls");
        cout<<"1. Insert Data Pelanggan"<<endl;
        cout<<"2. Insert Data Bank"<<endl;
        cout<<"3. Insert Relasi"<<endl;
        cout<<"4. Delete Data Pelanggan"<<endl;
        cout<<"5. Delete Data Bank"<<endl;
        cout<<"6. Update Data Pelanggan"<<endl;
        cout<<"7. Update Data Bank"<<endl;
        cout<<"8. Tampilkan Data Pelanggan"<<endl;
        cout<<"9. Tampilkan Data Bank"<<endl;
        cout<<"10. Tampilkan Relasi Pelanggan dengan Bank"<<endl;
        cout<<"11. Tampilkan Bank dengan Pelanggan"<<endl;
        cout<<"12. Nasabah Paling Banyak Berlangganan"<<endl;
        cout<<"13. Bank dengan Pelanggan Paling Banyak"<<endl;
        int pil;
        char ulang;
        cout<<"Pilih Menu : ";
        cin>>pil;
        if (pil == 1) {
            do {
                insertPelanggan(Lcust);
                cout<<"Insert Lagi? (y/n)";
                cin>>ulang;
            } while((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 2) {
            do {
                insertBank(Lbank);
                cout<<"Insert Lagi? (y/n)";
                cin>>ulang;
            } while((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 3) {
            printInfo_P(Lcust);
            printInfo_B(Lbank);
            do {
                insertRelasi(Lcust,Lbank,LR);
                cout<<"Insert Lagi? (y/n)";
                cin>>ulang;
            } while((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 4) {
            do {
                printInfo_P(Lcust);
                deletePelanggan(Lcust,LR);
                cout<<"Delete Lagi? (y/n)";
                cin>>ulang;
            } while ((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 6) {
            do {
                updatePelanggan(Lcust);
                cout<<"Update Lagi? (y/n)";
                cin>>ulang;
            } while ((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 7) {
            do {
                updateBank(Lbank);
                cout<<"Update Lagi? (y/n)";
                cin>>ulang;
            } while ((ulang == 'y') || (ulang == 'Y'));
        }
        if (pil == 8) {
            address_P p;
            if (Lcust.first_P == NULL) {
                cout<<"List Kosong"<<endl;
            }
            else {
                p = Lcust.first_P;
                do {
                    cout<<"No KTP : "<<p->info_P.noktp<<endl;
                    cout<<"Nama : "<<p->info_P.nama<<endl;
                    cout<<"TTL : "<<p->info_P.ttl<<endl;
                    cout<<"Umur : "<<p->info_P.usia<<endl;
                    cout<<"Alamat : "<<p->info_P.alamat<<endl;
                    p = p->next_P;

                }while (p != Lcust.first_P);
        }
        }
        if (pil == 9) {
            printInfo_B(Lbank);
        }
        if (pil == 10) {
            printInfo_R(LR,Lcust,Lbank,1);

        }
        if (pil == 11) {
            printInfo_R(LR,Lcust,Lbank,2);

        }
        cout<<"Kembali ke Menu? (y/n) ";
        cin>>menu;
    } while ((menu == 'Y') || (menu == 'y'));
        return 0;

}
