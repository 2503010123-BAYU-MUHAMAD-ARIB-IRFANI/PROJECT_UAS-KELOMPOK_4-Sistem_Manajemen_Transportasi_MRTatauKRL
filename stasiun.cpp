#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaStasiun;
    string wilayah;
    Node* next;
};

Node* headStasiun = NULL;

void tambahStasiun() {
    string nama, wilayah;
    cin.ignore();
    cout << "Masukkan Nama Stasiun : ";
    getline(cin, nama);
    cout << "Masukkan Wilayah (contoh: Jakarta/Bandung/Tasikmalaya) : ";
    getline(cin, wilayah);

    Node* baru = new Node;
    baru->namaStasiun = nama;
    baru->wilayah = wilayah;
    baru->next = NULL;
    if (headStasiun == NULL) {
        headStasiun = baru;
    } else {
        Node* temp = headStasiun;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Stasiun berhasil ditambahkan!\n";
}

void tampilkanStasiun() {
    if (headStasiun == NULL) {
        cout << "Belum ada data stasiun!\n";
        return;
    }
    Node* temp = headStasiun;
    int no = 1;
    cout << "\n=== DAFTAR STASIUN ===\n";
    while (temp != NULL) {
        cout << no++ << ". " << temp->namaStasiun << " (Wilayah: " << temp->wilayah << ")\n";
        temp = temp->next;
    }
}

void cariStasiun() {
    if (headStasiun == NULL) {
        cout << "Data kosong!\n";
        return;
    }
    string cari;
    cin.ignore();
    cout << "Masukkan nama stasiun yang dicari : ";
    getline(cin, cari);
    Node* temp = headStasiun;
    while (temp != NULL) {
        if (temp->namaStasiun == cari) {
            cout << "Stasiun ditemukan!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Stasiun tidak ditemukan!\n";
}

void hapusStasiun() {
    if (headStasiun == NULL) {
        cout << "Data kosong!\n";
        return;
    }
    string nama;
    cin.ignore();
    cout << "Masukkan nama stasiun yang akan dihapus : ";
    getline(cin, nama);
    Node* temp = headStasiun;
    Node* prev = NULL;
    while (temp != NULL && temp->namaStasiun != nama) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Stasiun tidak ditemukan!\n";
        return;
    }
    if (prev == NULL) {
        headStasiun = headStasiun->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Stasiun berhasil dihapus!\n";
}

bool cekStasiunAda(string nama) {
    Node* temp = headStasiun;
    while (temp != NULL) {
        if (temp->namaStasiun == nama) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

string getWilayahStasiun(string nama) {
    Node* temp = headStasiun;
    while (temp != NULL) {
        if (temp->namaStasiun == nama) {
            return temp->wilayah;
        }
        temp = temp->next;
    }
    return "";
}

void menuManajemenStasiun() {
    int pilih;
    do {
        cout << "\n=== MANAJEMEN STASIUN ===\n";
        cout << "1. Tambah Stasiun\n";
        cout << "2. Tampilkan Semua Stasiun\n";
        cout << "3. Cari Stasiun\n";
        cout << "4. Hapus Stasiun\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilihan : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambahStasiun();
                break;
            case 2:
                tampilkanStasiun();
                break;
            case 3:
                cariStasiun();
                break;
            case 4:
                hapusStasiun();
                break;
            case 0:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);
}
