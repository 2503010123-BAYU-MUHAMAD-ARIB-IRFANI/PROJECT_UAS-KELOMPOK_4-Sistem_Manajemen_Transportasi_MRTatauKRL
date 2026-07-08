#include <iostream>
#include <string>
using namespace std;

#include "stasiun.cpp"
<<<<<<< HEAD
#include "manajementJadwalPerjalanan.cpp"
#include "perpindahan_jalur.cpp"
=======
>>>>>>> 5833b4b1fe25d242ab360bb8b08cc20f68e6d0ce
#include "rute.cpp"
#include "Penumpang.cpp"
#include "manajementJadwalPerjalanan.cpp"
#include "perpindahan_jalur.cpp"

int main() {
    inisialisasiRute();

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
            case 1: menuManajemenStasiun(); break;
            case 2: menuJadwalPerjalanan(); break;
            case 3: menuPerpindahanJalur(); break;
            case 4: menuPencarianRute(); break;
            case 5: menuDataPenumpang(); break;
            case 0: cout << "\nTerima kasih! Sampai jumpa!\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
