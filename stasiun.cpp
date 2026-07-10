#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string namaStasiun;
    string wilayah;
    Node* next;
};

Node* headStasiun = NULL;

bool cekStasiunAda(string nama);
string getWilayahStasiun(string nama);
Node* getNodeStasiun(string nama);
void saveStasiun();

// Forward declarations for cascade delete
void hapusRuteByStasiun(Node* stasiun);
void hapusPenumpangByStasiun(Node* stasiun);
void hapusJadwalByNamaStasiun(string nama);
void hapusJalurByNamaStasiun(string nama);

void tambahStasiun() {
    string nama, wilayah;
    cin.ignore();
    cout << "Masukkan Nama Stasiun : ";
    getline(cin, nama);

    if (nama.empty()) {
        cout << "\n✗ Nama stasiun tidak boleh kosong!\n";
        return;
    }
    if (cekStasiunAda(nama)) {
        cout << "\n✗ Stasiun '" << nama << "' sudah terdaftar sebelumnya!\n";
        return;
    }

    cout << "Masukkan Wilayah (contoh: Jakarta/Bandung/Tasikmalaya) : ";
    getline(cin, wilayah);
    if (wilayah.empty()) {
        cout << "\n✗ Wilayah tidak boleh kosong!\n";
        return;
    }

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
    saveStasiun();
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
    tampilkanStasiun();
    if (headStasiun == NULL) {
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
    tampilkanStasiun();
    if (headStasiun == NULL) {
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
    // Cascade delete: hapus semua data yang terkait dengan stasiun ini
    hapusRuteByStasiun(temp);
    hapusPenumpangByStasiun(temp);
    hapusJadwalByNamaStasiun(temp->namaStasiun);
    hapusJalurByNamaStasiun(temp->namaStasiun);

    if (prev == NULL) {
        headStasiun = headStasiun->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    saveStasiun();
    cout << "Stasiun berhasil dihapus! Data terkait juga ikut terhapus.\n";
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

Node* getNodeStasiun(string nama) {
    Node* temp = headStasiun;
    while (temp != NULL) {
        if (temp->namaStasiun == nama) return temp;
        temp = temp->next;
    }
    return NULL;
}

void saveStasiun() {
    ofstream file("data_stasiun.txt");
    Node* temp = headStasiun;
    while (temp != NULL) {
        file << temp->namaStasiun << "|" << temp->wilayah << "\n";
        temp = temp->next;
    }
    file.close();
}

void loadStasiun() {
    ifstream file("data_stasiun.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        size_t pos = line.find("|");
        if (pos == string::npos) continue;
        string nama = line.substr(0, pos);
        string wilayah = line.substr(pos + 1);

        Node* baru = new Node;
        baru->namaStasiun = nama;
        baru->wilayah = wilayah;
        baru->next = NULL;

        if (headStasiun == NULL) {
            headStasiun = baru;
        } else {
            Node* temp = headStasiun;
            while (temp->next != NULL) temp = temp->next;
            temp->next = baru;
        }
    }
    file.close();
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
