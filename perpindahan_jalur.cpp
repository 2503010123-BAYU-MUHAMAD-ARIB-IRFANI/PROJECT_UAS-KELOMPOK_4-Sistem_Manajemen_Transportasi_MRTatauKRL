#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_JALUR = 100;

struct PerpindahanJalur {
    string idKereta;
    string stasiunTransit;
    string jalurAsal;
    string jalurTujuan;
    string waktu;
};

PerpindahanJalur daftarJalur[MAX_JALUR];
int jumlahJalur = 0;

bool cekStasiunAda(string nama);
void tambahRuteOtomatis(string asal, string tujuan);
void saveJalur();

bool cekJalurAda(string asalCek, string tujuanCek) {
    for (int i = 0; i < jumlahJalur; i++) {
        if (daftarJalur[i].jalurAsal == asalCek && daftarJalur[i].jalurTujuan == tujuanCek) {
            return true;
        }
    }
    return false;
}

void tambahJalur() {
    if (jumlahJalur >= MAX_JALUR) {
        cout << "\n[Error] Kapasitas memori array sudah penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH JALUR ===\n";
    string idK, transit, asalJ, tujuanJ, waktuJ;

    cout << "ID / Kode Kereta     : ";
    cin >> idK;
    if (idK.empty()) {
        cout << "\n[Error] ID Kereta tidak boleh kosong!\n";
        return;
    }

    cin.ignore();
    cout << "Nama Stasiun Transit : ";
    getline(cin, transit);
    if (transit.empty()) {
        cout << "\n[Error] Stasiun transit tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(transit)) {
        cout << "\n[Error] Stasiun transit '" << transit << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Dari Jalur (Asal)    : ";
    getline(cin, asalJ);
    if (asalJ.empty()) {
        cout << "\n[Error] Stasiun asal tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(asalJ)) {
        cout << "\n[Error] Stasiun asal '" << asalJ << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Ke Jalur (Tujuan)    : ";
    getline(cin, tujuanJ);
    if (tujuanJ.empty()) {
        cout << "\n[Error] Stasiun tujuan tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(tujuanJ)) {
        cout << "\n[Error] Stasiun tujuan '" << tujuanJ << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    if (cekJalurAda(asalJ, tujuanJ)) {
        cout << "\n[Error] Jalur '" << asalJ << " -> " << tujuanJ << "' sudah ada sebelumnya!\n";
        return;
    }

    cout << "Waktu Pindah (HH:MM) : ";
    cin >> waktuJ;
    if (waktuJ.empty()) {
        cout << "\n[Error] Waktu tidak boleh kosong!\n";
        return;
    }

    daftarJalur[jumlahJalur].idKereta = idK;
    daftarJalur[jumlahJalur].stasiunTransit = transit;
    daftarJalur[jumlahJalur].jalurAsal = asalJ;
    daftarJalur[jumlahJalur].jalurTujuan = tujuanJ;
    daftarJalur[jumlahJalur].waktu = waktuJ;

    jumlahJalur++;

    tambahRuteOtomatis(asalJ, tujuanJ);
    saveJalur();

    cout << "\n[Sukses] Data perpindahan jalur berhasil ditambahkan!\n";
}

void tampilkanSemuaJalur() {
    cout << "\n=== TAMPILKAN SEMUA JALUR ===\n";
    if (jumlahJalur == 0) {
        cout << "Belum ada data perpindahan jalur yang tercatat.\n";
        return;
    }

    for (int i = 0; i < jumlahJalur; i++) {
        cout << "Data Ke-" << i + 1 << "\n";
        cout << "   ID Kereta      : " << daftarJalur[i].idKereta << "\n";
        cout << "   Stasiun Transit: " << daftarJalur[i].stasiunTransit << "\n";
        cout << "   Perpindahan    : Jalur " << daftarJalur[i].jalurAsal << " -> Jalur " << daftarJalur[i].jalurTujuan << "\n";
        cout << "   Waktu          : " << daftarJalur[i].waktu << "\n";
        cout << "-------------------------------------------\n";
    }
}

void cariJalurPerpindahan() {
    cout << "\n=== CARI JALUR PERPINDAHAN ===\n";
    if (jumlahJalur == 0) {
        cout << "Data kosong. Tidak dapat melakukan pencarian.\n";
        return;
    }

    string keyword;
    cout << "Masukkan ID Kereta yang dicari: ";
    cin >> keyword;

    bool ditemukan = false;
    for (int i = 0; i < jumlahJalur; i++) {
        if (daftarJalur[i].idKereta == keyword) {
            cout << "\n[Data Ditemukan pada indeks array ke-" << i << "]\n";
            cout << "   ID Kereta      : " << daftarJalur[i].idKereta << "\n";
            cout << "   Stasiun Transit: " << daftarJalur[i].stasiunTransit << "\n";
            cout << "   Perpindahan    : Jalur " << daftarJalur[i].jalurAsal << " -> Jalur " << daftarJalur[i].jalurTujuan << "\n";
            cout << "   Waktu          : " << daftarJalur[i].waktu << "\n";
            cout << "-------------------------------------------\n";
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "\n[Informasi] Data dengan ID Kereta '" << keyword << "' tidak ditemukan.\n";
    }
}

void hapusJalur() {
    cout << "\n=== HAPUS JALUR ===\n";
    if (jumlahJalur == 0) {
        cout << "Data kosong. Tidak ada jalur yang bisa dihapus.\n";
        return;
    }

    string keyword;
    cout << "Masukkan ID Kereta dari jalur yang ingin dihapus: ";
    cin >> keyword;

    int indeksDitemukan = -1;
    for (int i = 0; i < jumlahJalur; i++) {
        if (daftarJalur[i].idKereta == keyword) {
            indeksDitemukan = i;
            break;
        }
    }

    if (indeksDitemukan == -1) {
        cout << "\n[Error] Data dengan ID Kereta '" << keyword << "' tidak ditemukan.\n";
    } else {
        for (int i = indeksDitemukan; i < jumlahJalur - 1; i++) {
            daftarJalur[i] = daftarJalur[i + 1];
        }
        jumlahJalur--;
        saveJalur();
        cout << "\n[Sukses] Data perpindahan jalur kereta '" << keyword << "' berhasil dihapus!\n";
    }
}

void saveJalur() {
    ofstream file("data_jalur.txt");
    for (int i = 0; i < jumlahJalur; i++) {
        file << daftarJalur[i].idKereta << "|"
             << daftarJalur[i].stasiunTransit << "|"
             << daftarJalur[i].jalurAsal << "|"
             << daftarJalur[i].jalurTujuan << "|"
             << daftarJalur[i].waktu << "\n";
    }
    file.close();
}

void loadJalur() {
    ifstream file("data_jalur.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        size_t p1 = line.find("|");
        size_t p2 = line.find("|", p1 + 1);
        size_t p3 = line.find("|", p2 + 1);
        size_t p4 = line.find("|", p3 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos || p4 == string::npos) continue;

        if (jumlahJalur >= MAX_JALUR) break;

        daftarJalur[jumlahJalur].idKereta = line.substr(0, p1);
        daftarJalur[jumlahJalur].stasiunTransit = line.substr(p1 + 1, p2 - p1 - 1);
        daftarJalur[jumlahJalur].jalurAsal = line.substr(p2 + 1, p3 - p2 - 1);
        daftarJalur[jumlahJalur].jalurTujuan = line.substr(p3 + 1, p4 - p3 - 1);
        daftarJalur[jumlahJalur].waktu = line.substr(p4 + 1);

        jumlahJalur++;
    }
    file.close();
}

void menuPerpindahanJalur() {
    int pilihan;
    do {
        cout << "\n=== PERPINDAHAN JALUR ===\n";
        cout << "1. Tambah Jalur\n";
        cout << "2. Tampilkan Semua Jalur\n";
        cout << "3. Cari Jalur Perpindahan\n";
        cout << "4. Hapus Jalur\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "-------------------------\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahJalur();
                break;
            case 2:
                tampilkanSemuaJalur();
                break;
            case 3:
                cariJalurPerpindahan();
                break;
            case 4:
                hapusJalur();
                break;
            case 0:
                cout << "\nKembali ke Menu Utama...\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 0);
}
