#ifndef STASIUN_H
#define STASIUN_H

#include <string>
using namespace std;

struct Node {
    string namaStasiun;
    Node* next;
};

void tambahStasiun();
void tampilkanStasiun();
void cariStasiun();
void hapusStasiun();
void menuManajemenStasiun();

#endif
