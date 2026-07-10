#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Penumpang {
    int nomor;
    string nama;
    Node* asalStasiun;
    Node* tujuanStasiun;
    Penumpang* next;
};

Penumpang* head = NULL;
int nomor = 1;

bool cekStasiunAda(string nama);
Node* getNodeStasiun(string nama);
void tambahRuteOtomatis(Node* asal, Node* tujuan);
void savePenumpang();

void tambahPenumpang() {
    cout << "\n=== TAMBAH PENUMPANG ===\n";
    string namaP, asalP, tujuanP;

    cin.ignore();
    cout << "Nama Penumpang : "; getline(cin, namaP);
    if (namaP.empty()) {
        cout << "\n✗ Nama penumpang tidak boleh kosong!\n";
        return;
    }

    cout << "Stasiun Asal   : "; getline(cin, asalP);
    if (asalP.empty()) {
        cout << "\n✗ Stasiun asal tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(asalP)) {
        cout << "\n✗ Stasiun asal '" << asalP << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Stasiun Tujuan : "; getline(cin, tujuanP);
    if (tujuanP.empty()) {
        cout << "\n✗ Stasiun tujuan tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(tujuanP)) {
        cout << "\n✗ Stasiun tujuan '" << tujuanP << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    Node* asalNode = getNodeStasiun(asalP);
    Node* tujuanNode = getNodeStasiun(tujuanP);
    if (!asalNode || !tujuanNode) {
        cout << "\n✗ Stasiun tidak valid!\n";
        return;
    }

    Penumpang* baru = new Penumpang();
    baru->nomor = nomor++;
    baru->nama = namaP;
    baru->asalStasiun = asalNode;
    baru->tujuanStasiun = tujuanNode;
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

    tambahRuteOtomatis(asalNode, tujuanNode);
    savePenumpang();

    cout << "\n✓ Penumpang berhasil ditambahkan! (Nomor: " << baru->nomor << ")\n";
}

void tampilkanPenumpang() {
    cout << "\n=== DAFTAR PENUMPANG ===\n";
    if (head == NULL) {
        cout << "Belum ada data penumpang.\n";
        return;
    }
    cout << "------------------------------------------------------------\n";
    cout << "No\tNama\t\tAsal\t\tTujuan\n";
    cout << "------------------------------------------------------------\n";
    Penumpang* temp = head;
    while (temp != NULL) {
        cout << temp->nomor << "\t" << temp->nama << "\t\t"
             << temp->asalStasiun->namaStasiun << "\t\t"
             << temp->tujuanStasiun->namaStasiun << "\n";
        temp = temp->next;
    }
    cout << "------------------------------------------------------------\n";
}

void cariPenumpang() {
    tampilkanPenumpang();
    if (head == NULL) return;
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
            cout << "Asal   : " << temp->asalStasiun->namaStasiun << "\n";
            cout << "Tujuan : " << temp->tujuanStasiun->namaStasiun << "\n";
            ketemu = true;
        }
        temp = temp->next;
    }
    if (!ketemu) {
        cout << "✗ Penumpang tidak ditemukan.\n";
    }
}

void hapusPenumpang() {
    tampilkanPenumpang();
    if (head == NULL) return;
    cout << "\n=== HAPUS PENUMPANG ===\n";
    int nomorHapus;
    cout << "Masukkan nomor penumpang yang dihapus: "; cin >> nomorHapus;

    if (head->nomor == nomorHapus) {
        Penumpang* hapus = head;
        head = head->next;
        delete hapus;
        savePenumpang();
        cout << "✓ Penumpang berhasil dihapus!\n";
        return;
    }

    Penumpang* temp = head;
    while (temp->next != NULL) {
        if (temp->next->nomor == nomorHapus) {
            Penumpang* hapus = temp->next;
            temp->next = hapus->next;
            delete hapus;
            savePenumpang();
            cout << "✓ Penumpang berhasil dihapus!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "✗ Nomor tidak ditemukan.\n";
}

void savePenumpang() {
    ofstream file("data_penumpang.txt");
    Penumpang* temp = head;
    while (temp != NULL) {
        file << temp->nomor << "|" << temp->nama << "|"
             << temp->asalStasiun->namaStasiun << "|"
             << temp->tujuanStasiun->namaStasiun << "\n";
        temp = temp->next;
    }
    file.close();
}

void loadPenumpang() {
    ifstream file("data_penumpang.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        size_t p1 = line.find("|");
        size_t p2 = line.find("|", p1 + 1);
        size_t p3 = line.find("|", p2 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;

        Penumpang* baru = new Penumpang();
        baru->nomor = stoi(line.substr(0, p1));
        baru->nama = line.substr(p1 + 1, p2 - p1 - 1);
        baru->asalStasiun = getNodeStasiun(line.substr(p2 + 1, p3 - p2 - 1));
        baru->tujuanStasiun = getNodeStasiun(line.substr(p3 + 1));
        baru->next = NULL;

        if (!baru->asalStasiun || !baru->tujuanStasiun) {
            delete baru;
            continue;
        }

        if (head == NULL) {
            head = baru;
        } else {
            Penumpang* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = baru;
        }

        if (baru->nomor >= nomor) {
            nomor = baru->nomor + 1;
        }
    }
    file.close();
}

void hapusPenumpangByStasiun(Node* stasiun) {
    if (head == NULL) return;

    while (head != NULL && (head->asalStasiun == stasiun || head->tujuanStasiun == stasiun)) {
        Penumpang* hapus = head;
        head = head->next;
        delete hapus;
    }
    if (head == NULL) { savePenumpang(); return; }

    Penumpang* current = head;
    while (current->next != NULL) {
        if (current->next->asalStasiun == stasiun || current->next->tujuanStasiun == stasiun) {
            Penumpang* hapus = current->next;
            current->next = hapus->next;
            delete hapus;
        } else {
            current = current->next;
        }
    }
    savePenumpang();
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
