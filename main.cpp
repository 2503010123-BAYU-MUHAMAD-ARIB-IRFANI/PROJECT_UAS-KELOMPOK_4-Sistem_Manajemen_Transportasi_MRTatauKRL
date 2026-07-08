#include <iostream>
#include <string>
using namespace std;

#include "Penumpang.cpp"
#include "stasiun.cpp"
#include "manajementJadwalPerjalanan.cpp"
#include "perpindahan_jalur.cpp"
#include "rute.cpp"

int main() {
    int pilihan;
    do {
        cout << "\n======================================\n";
        cout << "  SISTEM MANAJEMEN TRANSPORTASI MRT/KRL\n";
        cout << "======================================\n";
        cout << "1. Manajemen Stasiun\n";
        cout << "2. Manajemen Jadwal Perjalanan\n";
        cout << "3. Perpindahan Jalur\n";
        cout << "4. Pencarian Rute\n";
        cout << "5. Data Penumpang\n";
        cout << "0. Keluar\n";
        cout << "--------------------------------------\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1: menuManajemenStasiun();
                break;
            case 2: menuJadwalPerjalanan();
                break;
            case 3: menuPerpindahanJalur();
                break;
            case 4: menuPencarianRute();
                break;
            case 5: menuDataPenumpang();
                break;
            case 0: cout << "\nTerima kasih! Sampai jumpa!\n";
                break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
