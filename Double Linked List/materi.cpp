#include <iostream>

using namespace std;

struct node
{
    string tujuan;
    node *depan;
    node *belakang;
};

node *kereta;
node *head;
node *tail;

void inisialisasi () {
    head = NULL;
    tail = NULL;
}




int main () {
    inisialisasi ();

    kereta = new node;
    kereta->tujuan = "Bali";
    kereta->depan = NULL;
    kereta->belakang = NULL;
    head = kereta;
    tail = kereta;

    //Tambah Belakang
    kereta = new node;
    kereta->tujuan = "Bandung";
    kereta->depan = NULL;
    kereta->belakang=NULL;
    tail->belakang=kereta;
    kereta->depan=tail;
    tail=kereta;

    //Tambah Tengah
    kereta = new node;
    kereta->tujuan = "Semarang";
    kereta->belakang=NULL;
    kereta->depan=NULL;
    head->belakang=kereta;
    kereta->depan=head;
    tail->depan=kereta;
    kereta->belakang=tail;
/*
    head->depan=tail;
    tail->belakang=head;
*/

    //tambah tengah other
    node *bantu;
    kereta = new node;
    kereta->tujuan="Ciamis";
    kereta->depan=NULL;
    kereta->belakang=NULL;
    bantu=head->belakang;
    bantu=bantu->belakang;
    bantu->belakang=kereta;
    tail->depan=kereta;
    kereta->depan=bantu;
    kereta->belakang=tail;

    //=======================
    

    return 0;
}