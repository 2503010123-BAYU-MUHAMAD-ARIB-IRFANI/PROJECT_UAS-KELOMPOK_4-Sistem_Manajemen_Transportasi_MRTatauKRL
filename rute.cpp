#include <iostream>
#include <string>

using namespace std;

struct NodeRute {
    string asal;
    string tujuan;
    string wilayah;
    NodeRute* next;
};

NodeRute* top = NULL;

void tambahRute() {
    string asalR, tujuanR;
    cin.ignore();

    cout << "\nMasukkan Stasiun Asal   : ";
    getline(cin, asalR);
    if (!cekStasiunAda(asalR)) {
        cout << "\n✗ Stasiun asal '" << asalR << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }

    cout << "Masukkan Stasiun Tujuan : ";
    getline(cin, tujuanR);
    if (!cekStasiunAda(tujuanR)) {
        cout << "\n✗ Stasiun tujuan '" << tujuanR << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }

    tambahRuteOtomatis(asalR, tujuanR);
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
             << " [" << bantu->wilayah << "]"
             << "\n";
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

void tampilkanRuteDalamWilayah() {
    if (top == NULL) {
        cout << "\nBelum ada data rute!\n";
        return;
    }
    string wilayahCari;
    cin.ignore();
    cout << "\nMasukkan nama wilayah (contoh: Jakarta) : ";
    getline(cin, wilayahCari);

    NodeRute* bantu = top;
    bool ada = false;
    cout << "\n===== RUTE DALAM WILAYAH " << wilayahCari << " =====\n";
    while (bantu != NULL) {
        if (bantu->wilayah == ("Dalam Wilayah " + wilayahCari)) {
            cout << bantu->asal << " -> " << bantu->tujuan << "\n";
            ada = true;
        }
        bantu = bantu->next;
    }
    if (!ada) {
        cout << "Tidak ada rute dalam wilayah ini.\n";
    }
}

void tampilkanRuteLuarWilayah() {
    if (top == NULL) {
        cout << "\nBelum ada data rute!\n";
        return;
    }
    NodeRute* bantu = top;
    bool ada = false;
    cout << "\n===== RUTE LUAR WILAYAH =====\n";
    while (bantu != NULL) {
        if (bantu->wilayah.substr(0, 13) == "Luar Wilayah ") {
            cout << bantu->asal << " -> " << bantu->tujuan << " [" << bantu->wilayah << "]\n";
            ada = true;
        }
        bantu = bantu->next;
    }
    if (!ada) {
        cout << "Tidak ada rute luar wilayah.\n";
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

bool cekRuteAda(string asal, string tujuan) {
    NodeRute* bantu = top;
    while (bantu != NULL) {
        if (bantu->asal == asal && bantu->tujuan == tujuan) {
            return true;
        }
        bantu = bantu->next;
    }
    return false;
}

void tambahRuteOtomatis(string asal, string tujuan) {
    if (!cekRuteAda(asal, tujuan)) {
        string wilayahAsal = getWilayahStasiun(asal);
        string wilayahTujuan = getWilayahStasiun(tujuan);
        string keteranganWilayah;

        if (wilayahAsal == wilayahTujuan) {
            keteranganWilayah = "Dalam Wilayah " + wilayahAsal;
        } else {
            keteranganWilayah = "Luar Wilayah (" + wilayahAsal + " -> " + wilayahTujuan + ")";
        }

        NodeRute* baru = new NodeRute;
        baru->asal = asal;
        baru->tujuan = tujuan;
        baru->wilayah = keteranganWilayah;
        baru->next = top;
        top = baru;
    }
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
        cout << "\n5. Tampilkan Rute Dalam Wilayah";
        cout << "\n6. Tampilkan Rute Luar Wilayah";
        cout << "\n0. Kembali";
        cout << "\nPilihan : ";
        cin >> pilih;
        switch (pilih) {
        case 1: cariRuteTercepat(); break;
        case 2: tampilkanSemuaRute(); break;
        case 3: tambahRute(); break;
        case 4: hapusRute(); break;
        case 5: tampilkanRuteDalamWilayah(); break;
        case 6: tampilkanRuteLuarWilayah(); break;
        case 0: cout << "\nKembali ke menu utama...\n"; break;
        default: cout << "\nPilihan tidak valid!\n";
        }
    } while (pilih != 0);
}
