#include <iostream>
#include <string>

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

void tambahJalur() {
    if (jumlahJalur >= MAX_JALUR) {
        cout << "\n[Error] Kapasitas memori array sudah penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH JALUR ===\n";
    cout << "ID / Kode Kereta     : ";
    cin >> daftarJalur[jumlahJalur].idKereta;

    cout << "Nama Stasiun Transit : ";
    cin.ignore();
    getline(cin, daftarJalur[jumlahJalur].stasiunTransit);

    cout << "Dari Jalur (Asal)    : ";
    getline(cin, daftarJalur[jumlahJalur].jalurAsal);

    cout << "Ke Jalur (Tujuan)    : ";
    getline(cin, daftarJalur[jumlahJalur].jalurTujuan);

    cout << "Waktu Pindah (HH:MM) : ";
    cin >> daftarJalur[jumlahJalur].waktu;

    jumlahJalur++;
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
        cout << "\n[Sukses] Data perpindahan jalur kereta '" << keyword << "' berhasil dihapus!\n";
    }
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
