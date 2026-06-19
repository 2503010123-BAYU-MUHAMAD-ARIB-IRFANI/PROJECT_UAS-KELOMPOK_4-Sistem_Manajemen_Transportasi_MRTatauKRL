#ifndef PENUMPANG_H
#define PENUMPANG_H

#include <iostream>
#include <string>
using namespace std;

struct Penumpang {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    Penumpang* next;
};

extern Penumpang* head;
extern int nomor;

void tambahPenumpang();
void tampilkanPenumpang();
void cariPenumpang();
void hapusPenumpang();
void menuDataPenumpang();

#endif
