#ifndef PENUMPANG_H
#define PENUMPANG_H

#include <iostream>
#include <string>
using namespace std;

// Struct Node Linked List
struct Penumpang {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    Penumpang* next;
};

// Deklarasi variabel global
extern Penumpang* head;
extern int nomor;

// Deklarasi fungsi
void tambahPenumpang();
void tampilkanPenumpang();
void cariPenumpang();
void hapusPenumpang();
void menuDataPenumpang();

#endif
