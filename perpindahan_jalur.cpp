#include <iostream>
#include <string>

using namespace std;

// Batas maksimum data riwayat perpindahan jalur dalam array
const int MAX_PERPINDAHAN = 100;

// Struktur data untuk mencatat informasi perpindahan jalur kereta di stasiun transit
struct PerpindahanJalur {
    string idKereta;
    string stasiunTransit;
    string jalurAsal;
    string jalurTujuan;
    string waktu;
};

// Array global dan counter untuk menyimpan data di memori
PerpindahanJalur daftarPerpindahan[MAX_PERPINDAHAN];
int jumlahPerpindahan = 0;

// Fungsi internal 1: Mencatat data perpindahan jalur baru (Create)
void tambahPerpindahan() {
    if (jumlahPerpindahan >= MAX_PERPINDAHAN) {
        cout << "\n[Error] Kapasitas memori array sudah penuh!\n";
        return;
    }

    cout << "\n=== Tambah Data Perpindahan Jalur ===\n";
    cout << "ID / Kode Kereta     : ";
    cin >> daftarPerpindahan[jumlahPerpindahan].idKereta;
    
    cout << "Nama Stasiun Transit : ";
    cin.ignore();
    getline(cin, daftarPerpindahan[jumlahPerpindahan].stasiunTransit);
    
    cout << "Dari Jalur (Asal)    : ";
    getline(cin, daftarPerpindahan[jumlahPerpindahan].jalurAsal);
    
    cout << "Ke Jalur (Tujuan)    : ";
    getline(cin, daftarPerpindahan[jumlahPerpindahan].jalurTujuan);
    
    cout << "Waktu Pindah (HH:MM) : ";
    cin >> daftarPerpindahan[jumlahPerpindahan].waktu;

    jumlahPerpindahan++;
    cout << "\n[Sukses] Data perpindahan jalur berhasil dicatat!\n";
}

// Fungsi internal 2: Menampilkan seluruh daftar perpindahan jalur (Read)
void tampilkanPerpindahan() {
    cout << "\n=== Daftar Perpindahan Jalur MRT/KRL ===\n";
    if (jumlahPerpindahan == 0) {
        cout << "Belum ada log atau data perpindahan jalur.\n";
        return;
    }

    for (int i = 0; i < jumlahPerpindahan; i++) {
        cout << i + 1 << ". ID Kereta      : " << daftarPerpindahan[i].idKereta << endl;
        cout << "   Stasiun Transit: " << daftarPerpindahan[i].stasiunTransit << endl;
        cout << "   Perpindahan    : Jalur " << daftarPerpindahan[i].jalurAsal << " -> Jalur " << daftarPerpindahan[i].jalurTujuan << endl;
        cout << "   Waktu          : " << daftarPerpindahan[i].waktu << endl;
        cout << "-------------------------------------------\n";
    }
}

// FUNGSI UTAMA YANG DIPANGGIL OLEH MAIN.CPP
// Nama fungsi harus persis dengan prototype: void menuPerpindahanJalur();
void menuPerpindahanJalur() {
    int pilihanSub;
    do {
        cout << "\n=====================================\n";
        cout << "   MENU PERPINDAHAN JALUR (ARRAY)    \n";
        cout << "=====================================\n";
        cout << "1. Tambah Log Perpindahan Jalur\n";
        cout << "2. Lihat Semua Riwayat Perpindahan\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "-------------------------------------\n";
        cout << "Pilihan: "; cin >> pilihanSub;

        switch (pilihanSub) {
            case 1:
                tambahPerpindahan();
                break;
            case 2:
                tampilkanPerpindahan();
                break;
            case 0:
                cout << "\nKembali ke menu utama sistem MRT/KRL...\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihanSub != 0);
}

