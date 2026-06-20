#include <iostream>
#include <string>

using namespace std;

struct NodeRute {
    string asal;
    string tujuan;
    NodeRute* next;
};

NodeRute* top = NULL;

void tambahRute() {

    NodeRute* baru = new NodeRute;

    cin.ignore();

    cout << "\nMasukkan Stasiun Asal   : ";
    getline(cin, baru->asal);

    cout << "Masukkan Stasiun Tujuan : ";
    getline(cin, baru->tujuan);

    baru->next = top;
    top = baru;

    cout << "\nRute berhasil ditambahkan!\n";
}

void tampilkanSemuaRute() {

    if (top == NULL) {
        cout << "\nBelum ada data rute!\n";
        return;
    }

    NodeRute* bantu = top;
    int no = 1;

    cout << "\n===== DAFTAR RUTE =====\n";

    while (bantu != NULL) {

        cout << no++ << ". "
             << bantu->asal
             << " -> "
             << bantu->tujuan
             << endl;

        bantu = bantu->next;
    }
}

void cariRuteTercepat() {

    if (top == NULL) {
        cout << "\nData rute kosong!\n";
        return;
    }

    string asalCari;

    cin.ignore();

    cout << "\nMasukkan Stasiun Asal : ";
    getline(cin, asalCari);

    NodeRute* bantu = top;
    bool ditemukan = false;

    while (bantu != NULL) {

        if (bantu->asal == asalCari) {

            cout << "\n===== HASIL PENCARIAN =====\n";
            cout << "Rute : "
                 << bantu->asal
                 << " -> "
                 << bantu->tujuan
                 << endl;

            ditemukan = true;
            break;
        }

        bantu = bantu->next;
    }

    if (!ditemukan) {
        cout << "\nRute tidak ditemukan!\n";
    }
}

void hapusRute() {

    if (top == NULL) {

        cout << "\nData rute kosong!\n";
        return;
    }

    NodeRute* hapus = top;

    top = top->next;

    cout << "\nRute "
         << hapus->asal
         << " -> "
         << hapus->tujuan
         << " berhasil dihapus!\n";

    delete hapus;
}

void inisialisasiRute() {

    NodeRute* r1 = new NodeRute;
    r1->asal = "Lebak Bulus";
    r1->tujuan = "Bundaran HI";
    r1->next = top;
    top = r1;

    NodeRute* r2 = new NodeRute;
    r2->asal = "Bogor";
    r2->tujuan = "Manggarai";
    r2->next = top;
    top = r2;

    NodeRute* r3 = new NodeRute;
    r3->asal = "Bekasi";
    r3->tujuan = "Tanah Abang";
    r3->next = top;
    top = r3;
}

void menuPencarianRute() {

    int pilih;

    do {

        cout << "\n====================================";
        cout << "\n      PENCARIAN RUTE MRT/KRL";
        cout << "\n====================================";
        cout << "\n1. Cari Rute Tercepat";
        cout << "\n2. Tampilkan Semua Rute";
        cout << "\n3. Tambah Rute";
        cout << "\n4. Hapus Rute";
        cout << "\n0. Kembali";
        cout << "\nPilihan : ";
        cin >> pilih;

        switch (pilih) {

        case 1:
            cariRuteTercepat();
            break;

        case 2:
            tampilkanSemuaRute();
            break;

        case 3:
            tambahRute();
            break;

        case 4:
            hapusRute();
            break;

        case 0:
            cout << "\nKembali ke menu utama...\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while (pilih != 0);
}
