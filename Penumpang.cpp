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

Penumpang* head = NULL;
int nomor = 1;
void tambahPenumpang() {
    cout << "\n=== TAMBAH PENUMPANG ===\n";
    string namaP, asalP, tujuanP;

    cin.ignore();
    cout << "Nama Penumpang : "; getline(cin, namaP);
    cout << "Stasiun Asal   : "; getline(cin, asalP);
    if (!cekStasiunAda(asalP)) {
        cout << "\n✗ Stasiun asal '" << asalP << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }
    cout << "Stasiun Tujuan : "; getline(cin, tujuanP);
    if (!cekStasiunAda(tujuanP)) {
        cout << "\n✗ Stasiun tujuan '" << tujuanP << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }
    Penumpang* baru = new Penumpang();
    baru->nomor = nomor++;
    baru->nama = namaP;
    baru->asal = asalP;
    baru->tujuan = tujuanP;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Penumpang* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    tambahRuteOtomatis(asalP, tujuanP);
    cout << "\n✓ Penumpang berhasil ditambahkan! (Nomor: " << baru->nomor << ")\n";
}
void tampilkanPenumpang() {
    cout << "\n=== DAFTAR PENUMPANG ===\n";
    if (head == NULL) {
        cout << "Belum ada data penumpang.\n";
        return;
    }
    cout << "--------------------------------------------\n";
    cout << "No\tNama\t\tAsal\t\tTujuan\n";
    cout << "--------------------------------------------\n";
    Penumpang* temp = head;
    while (temp != NULL) {
        cout << temp->nomor << "\t" << temp->nama << "\t\t"
             << temp->asal << "\t\t" << temp->tujuan << "\n";
        temp = temp->next;
    }
    cout << "--------------------------------------------\n";
}

void cariPenumpang() {
    cout << "\n=== CARI PENUMPANG ===\n";
    string keyword;
    cout << "Masukkan nama penumpang: "; cin.ignore(); getline(cin, keyword);

    Penumpang* temp = head;
    bool ketemu = false;
    while (temp != NULL) {
        if (temp->nama == keyword) {
            cout << "\n✓ Penumpang ditemukan!\n";
            cout << "Nomor  : " << temp->nomor << "\n";
            cout << "Nama   : " << temp->nama << "\n";
            cout << "Asal   : " << temp->asal << "\n";
            cout << "Tujuan : " << temp->tujuan << "\n";
            ketemu = true;
        }
        temp = temp->next;
    }
    if (!ketemu) {
        cout << "✗ Penumpang tidak ditemukan.\n";
    }
}

void hapusPenumpang() {
    cout << "\n=== HAPUS PENUMPANG ===\n";
    if (head == NULL) {
        cout << "Belum ada data penumpang.\n";
        return;
    }
    int nomorHapus;
    cout << "Masukkan nomor penumpang yang dihapus: "; cin >> nomorHapus;

    if (head->nomor == nomorHapus) {
        Penumpang* hapus = head;
        head = head->next;
        delete hapus;
        cout << "✓ Penumpang berhasil dihapus!\n";
        return;
    }

    Penumpang* temp = head;
    while (temp->next != NULL) {
        if (temp->next->nomor == nomorHapus) {
            Penumpang* hapus = temp->next;
            temp->next = hapus->next;
            delete hapus;
            cout << "✓ Penumpang berhasil dihapus!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "✗ Nomor tidak ditemukan.\n";
}

void menuDataPenumpang() {
    int pilihan;
    do {
        cout << "\n=== DATA PENUMPANG ===\n";
        cout << "1. Tambah Penumpang\n";
        cout << "2. Tampilkan Semua Penumpang\n";
        cout << "3. Cari Penumpang\n";
        cout << "4. Hapus Penumpang\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPenumpang();
                break;
            case 2: tampilkanPenumpang();
                break;
            case 3: cariPenumpang();
                break;
            case 4: hapusPenumpang();
                break;
            case 0: cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}
