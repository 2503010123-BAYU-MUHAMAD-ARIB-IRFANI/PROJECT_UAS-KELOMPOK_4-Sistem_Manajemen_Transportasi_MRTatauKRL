#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct NodeRute {
    Node* asalStasiun;
    Node* tujuanStasiun;
    string wilayah;
    NodeRute* next;
};

NodeRute* top = NULL;

bool cekStasiunAda(string nama);
Node* getNodeStasiun(string nama);
bool cekRuteAda(Node* asal, Node* tujuan);
void tambahRuteOtomatis(Node* asal, Node* tujuan);
void saveRute();

void tambahRute() {
    string asalR, tujuanR;
    cin.ignore();

    cout << "\nMasukkan Stasiun Asal   : ";
    getline(cin, asalR);
    if (asalR.empty()) {
        cout << "\n✗ Stasiun asal tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(asalR)) {
        cout << "\n✗ Stasiun asal '" << asalR << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Masukkan Stasiun Tujuan : ";
    getline(cin, tujuanR);
    if (tujuanR.empty()) {
        cout << "\n✗ Stasiun tujuan tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(tujuanR)) {
        cout << "\n✗ Stasiun tujuan '" << tujuanR << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    Node* asalNode = getNodeStasiun(asalR);
    Node* tujuanNode = getNodeStasiun(tujuanR);
    if (!asalNode || !tujuanNode) {
        cout << "\n✗ Stasiun tidak valid!\n";
        return;
    }

    if (cekRuteAda(asalNode, tujuanNode)) {
        cout << "\n✗ Rute '" << asalR << " -> " << tujuanR << "' sudah ada sebelumnya!\n";
        return;
    }

    tambahRuteOtomatis(asalNode, tujuanNode);
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
             << bantu->asalStasiun->namaStasiun
             << " -> "
             << bantu->tujuanStasiun->namaStasiun
             << " [" << bantu->wilayah << "]"
             << "\n";
        bantu = bantu->next;
    }
}

void cariRuteTercepat() {
    tampilkanSemuaRute();
    if (top == NULL) return;

    string asalCari;

    cin.ignore();

    cout << "\nMasukkan Stasiun Asal : ";
    getline(cin, asalCari);

    Node* asalNode = getNodeStasiun(asalCari);
    if (!asalNode) {
        cout << "\nStasiun '" << asalCari << "' tidak ditemukan!\n";
        return;
    }

    NodeRute* bantu = top;
    bool ditemukan = false;

    while (bantu != NULL) {
        if (bantu->asalStasiun == asalNode) {
            cout << "\n===== HASIL PENCARIAN =====\n";
            cout << "Rute : "
                 << bantu->asalStasiun->namaStasiun
                 << " -> "
                 << bantu->tujuanStasiun->namaStasiun
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
            cout << bantu->asalStasiun->namaStasiun << " -> " << bantu->tujuanStasiun->namaStasiun << "\n";
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
            cout << bantu->asalStasiun->namaStasiun << " -> " << bantu->tujuanStasiun->namaStasiun
                 << " [" << bantu->wilayah << "]\n";
            ada = true;
        }
        bantu = bantu->next;
    }
    if (!ada) {
        cout << "Tidak ada rute luar wilayah.\n";
    }
}

void hapusRute() {
    tampilkanSemuaRute();
    if (top == NULL) return;
    NodeRute* hapus = top;
    top = top->next;
    saveRute();

    cout << "\nRute "
         << hapus->asalStasiun->namaStasiun
         << " -> "
         << hapus->tujuanStasiun->namaStasiun
         << " berhasil dihapus!\n";

    delete hapus;
}

bool cekRuteAda(Node* asal, Node* tujuan) {
    NodeRute* bantu = top;
    while (bantu != NULL) {
        if (bantu->asalStasiun == asal && bantu->tujuanStasiun == tujuan) {
            return true;
        }
        bantu = bantu->next;
    }
    return false;
}

void tambahRuteOtomatis(Node* asal, Node* tujuan) {
    if (!cekRuteAda(asal, tujuan)) {
        string keteranganWilayah;

        if (asal->wilayah == tujuan->wilayah) {
            keteranganWilayah = "Dalam Wilayah " + asal->wilayah;
        } else {
            keteranganWilayah = "Luar Wilayah (" + asal->wilayah + " -> " + tujuan->wilayah + ")";
        }

        NodeRute* baru = new NodeRute;
        baru->asalStasiun = asal;
        baru->tujuanStasiun = tujuan;
        baru->wilayah = keteranganWilayah;
        baru->next = top;
        top = baru;

        saveRute();
    }
}

void saveRute() {
    ofstream file("data_rute.txt");
    NodeRute* temp = top;
    while (temp != NULL) {
        file << temp->asalStasiun->namaStasiun << "|"
             << temp->tujuanStasiun->namaStasiun << "|"
             << temp->wilayah << "\n";
        temp = temp->next;
    }
    file.close();
}

void loadRute() {
    ifstream file("data_rute.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos) continue;

        string asalNama = line.substr(0, pos1);
        string tujuanNama = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string wilayahStr = line.substr(pos2 + 1);

        Node* asalNode = getNodeStasiun(asalNama);
        Node* tujuanNode = getNodeStasiun(tujuanNama);
        if (!asalNode || !tujuanNode) continue;

        NodeRute* baru = new NodeRute;
        baru->asalStasiun = asalNode;
        baru->tujuanStasiun = tujuanNode;
        baru->wilayah = wilayahStr;
        baru->next = top;
        top = baru;
    }
    file.close();
}

void hapusRuteByStasiun(Node* stasiun) {
    if (top == NULL) return;

    while (top != NULL && (top->asalStasiun == stasiun || top->tujuanStasiun == stasiun)) {
        NodeRute* hapus = top;
        top = top->next;
        delete hapus;
    }
    if (top == NULL) { saveRute(); return; }

    NodeRute* current = top;
    while (current->next != NULL) {
        if (current->next->asalStasiun == stasiun || current->next->tujuanStasiun == stasiun) {
            NodeRute* hapus = current->next;
            current->next = hapus->next;
            delete hapus;
        } else {
            current = current->next;
        }
    }
    saveRute();
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
