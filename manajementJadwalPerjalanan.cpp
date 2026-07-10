#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Jadwal {
    string asal;
    string tujuan;
    string waktu;
    string status;
};

const int MAX = 100;
Jadwal queueJadwal[MAX];
int front = -1, rear = -1;

bool cekStasiunAda(string nama);
Node* getNodeStasiun(string nama);
void tambahRuteOtomatis(Node* asal, Node* tujuan);
void saveJadwal();

bool isEmpty() {
    return front == -1;
}
bool isFull() {
    return rear == MAX - 1;
}

bool cekJadwalAda(string asal, string tujuan, string waktu) {
    if (isEmpty()) return false;
    for (int i = front; i <= rear; i++) {
        if (queueJadwal[i].asal == asal && queueJadwal[i].tujuan == tujuan && queueJadwal[i].waktu == waktu) {
            return true;
        }
    }
    return false;
}

void tambahJadwal() {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }

    Jadwal baru;
    cin.ignore();

    cout << "Asal   : ";
    getline(cin, baru.asal);
    if (baru.asal.empty()) {
        cout << "\n✗ Stasiun asal tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(baru.asal)) {
        cout << "\n✗ Stasiun asal '" << baru.asal << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Tujuan : ";
    getline(cin, baru.tujuan);
    if (baru.tujuan.empty()) {
        cout << "\n✗ Stasiun tujuan tidak boleh kosong!\n";
        return;
    }
    if (!cekStasiunAda(baru.tujuan)) {
        cout << "\n✗ Stasiun tujuan '" << baru.tujuan << "' belum terdaftar!\n";
        cout << "-> Silakan ke Menu Utama > pilih '1. Manajemen Stasiun' > pilih '1. Tambah Stasiun' terlebih dahulu.\n";
        return;
    }

    cout << "Waktu (HH:MM) : ";
    getline(cin, baru.waktu);
    if (baru.waktu.empty()) {
        cout << "\n✗ Waktu tidak boleh kosong!\n";
        return;
    }

    if (cekJadwalAda(baru.asal, baru.tujuan, baru.waktu)) {
        cout << "\n✗ Jadwal '" << baru.asal << " -> " << baru.tujuan << " (" << baru.waktu << ")' sudah ada sebelumnya!\n";
        return;
    }

    baru.status = "Scheduled";

    if (isEmpty())
        front = 0;
    rear++;
    queueJadwal[rear] = baru;

    {
        Node* asalNode = getNodeStasiun(baru.asal);
        Node* tujuanNode = getNodeStasiun(baru.tujuan);
        if (asalNode && tujuanNode) tambahRuteOtomatis(asalNode, tujuanNode);
    }
    saveJadwal();

    cout << "Jadwal berhasil ditambahkan ke queue. (Status: Scheduled)\n";
}

void tampilkanJadwal() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "\n=== DAFTAR JADWAL ===\n";
    for (int i = front; i <= rear; i++) {
        cout << "\nJadwal " << i - front + 1 << "\n";
        cout << "Asal   : " << queueJadwal[i].asal << "\n";
        cout << "Tujuan : " << queueJadwal[i].tujuan << "\n";
        cout << "Waktu  : " << queueJadwal[i].waktu << "\n";
        cout << "Status : " << queueJadwal[i].status << "\n";
    }
}

void cariJadwal() {
    tampilkanJadwal();
    if (isEmpty()) return;
    string tujuanCari;
    bool ditemukan = false;
    cin.ignore();
    cout << "Masukkan tujuan yang dicari: ";
    getline(cin, tujuanCari);
    for (int i = front; i <= rear; i++) {
        if (queueJadwal[i].tujuan == tujuanCari) {
            cout << "\nData ditemukan:\n";
            cout << "Asal   : " << queueJadwal[i].asal << "\n";
            cout << "Tujuan : " << queueJadwal[i].tujuan << "\n";
            cout << "Waktu  : " << queueJadwal[i].waktu << "\n";
            cout << "Status : " << queueJadwal[i].status << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan)
        cout << "Jadwal tidak ditemukan.\n";
}

void ubahStatusJadwal() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }
    tampilkanJadwal();

    string tujuanCari;
    cin.ignore();
    cout << "\nMasukkan tujuan jadwal yang mau diubah statusnya: ";
    getline(cin, tujuanCari);

    bool ditemukan = false;
    for (int i = front; i <= rear; i++) {
        if (queueJadwal[i].tujuan == tujuanCari) {
            cout << "\nPilih status baru:\n";
            cout << "1. Scheduled\n2. In-Progress\n3. Completed\n4. Delayed\n";
            cout << "Pilihan : ";
            int pilihStatus;
            cin >> pilihStatus;

            switch (pilihStatus) {
                case 1: queueJadwal[i].status = "Scheduled"; break;
                case 2: queueJadwal[i].status = "In-Progress"; break;
                case 3: queueJadwal[i].status = "Completed"; break;
                case 4: queueJadwal[i].status = "Delayed"; break;
                default:
                    cout << "\n✗ Pilihan tidak valid, status tidak diubah.\n";
                    return;
            }
            saveJadwal();
            cout << "\n✓ Status berhasil diubah menjadi " << queueJadwal[i].status << "\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n✗ Jadwal dengan tujuan tersebut tidak ditemukan.\n";
    }
}

void hapusJadwal() {
    tampilkanJadwal();
    if (isEmpty()) return;
    cout << "\nJadwal terdepan dihapus:\n";
    cout << "Asal   : " << queueJadwal[front].asal << "\n";
    cout << "Tujuan : " << queueJadwal[front].tujuan << "\n";
    cout << "Waktu  : " << queueJadwal[front].waktu << "\n";
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    saveJadwal();
}

void saveJadwal() {
    ofstream file("data_jadwal.txt");
    if (!isEmpty()) {
        for (int i = front; i <= rear; i++) {
            file << queueJadwal[i].asal << "|" << queueJadwal[i].tujuan << "|"
                 << queueJadwal[i].waktu << "|" << queueJadwal[i].status << "\n";
        }
    }
    file.close();
}

void loadJadwal() {
    ifstream file("data_jadwal.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

        Jadwal j;
        j.asal = line.substr(0, pos1);
        j.tujuan = line.substr(pos1 + 1, pos2 - pos1 - 1);
        j.waktu = line.substr(pos2 + 1, pos3 - pos2 - 1);
        j.status = line.substr(pos3 + 1);

        if (isFull()) break;
        if (isEmpty()) front = 0;
        rear++;
        queueJadwal[rear] = j;
    }
    file.close();
}

void hapusJadwalByNamaStasiun(string nama) {
    if (isEmpty()) return;
    int newFront = -1, newRear = -1;
    for (int i = front; i <= rear; i++) {
        if (queueJadwal[i].asal != nama && queueJadwal[i].tujuan != nama) {
            if (newFront == -1) newFront = 0;
            newRear++;
            queueJadwal[newRear] = queueJadwal[i];
        }
    }
    front = newFront;
    rear = newRear;
    saveJadwal();
}

void menuJadwalPerjalanan() {
    int pilih;
    do {
        cout << "\n=== MANAJEMEN JADWAL PERJALANAN ===\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Tampilkan Semua Jadwal\n";
        cout << "3. Cari Jadwal\n";
        cout << "4. Hapus Jadwal\n";
        cout << "5. Ubah Status Jadwal\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilih;
        switch (pilih) {
            case 1: tambahJadwal(); break;
            case 2: tampilkanJadwal(); break;
            case 3: cariJadwal(); break;
            case 4: hapusJadwal(); break;
            case 5: ubahStatusJadwal(); break;
            case 0: cout << "Kembali ke menu utama...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);
}
