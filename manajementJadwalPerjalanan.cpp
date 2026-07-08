#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
  string asal;
  string tujuan;
  string waktu;
};

const int MAX = 100;
Jadwal queueJadwal[MAX];

int front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return rear == MAX - 1; }

void tambahJadwal() {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    Jadwal baru;
    cin.ignore();
    cout << "Asal   : ";
    getline(cin, baru.asal);
    if (!cekStasiunAda(baru.asal)) {
        cout << "\n✗ Stasiun asal '" << baru.asal << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }
    cout << "Tujuan : ";
    getline(cin, baru.tujuan);
    if (!cekStasiunAda(baru.tujuan)) {
        cout << "\n✗ Stasiun tujuan '" << baru.tujuan << "' belum terdaftar! Tambahkan dulu di Manajemen Stasiun.\n";
        return;
    }
    cout << "Waktu  : ";
    getline(cin, baru.waktu);
    if (isEmpty())
        front = 0;
    rear++;
    queueJadwal[rear] = baru;
    tambahRuteOtomatis(baru.asal, baru.tujuan);
    cout << "Jadwal berhasil ditambahkan ke queue.\n";
}

void tampilkanJadwal() {
  if (isEmpty()) {
    cout << "Queue kosong.\n";
    return;
  }

  cout << "\n=== DAFTAR JADWAL ===\n";
  for (int i = front; i <= rear; i++) {
    cout << "\nJadwal " << i - front + 1 << endl;
    cout << "Asal   : " << queueJadwal[i].asal << endl;
    cout << "Tujuan : " << queueJadwal[i].tujuan << endl;
    cout << "Waktu  : " << queueJadwal[i].waktu << endl;
  }
}

void cariJadwal() {
  if (isEmpty()) {
    cout << "Queue kosong.\n";
    return;
  }

  string tujuanCari;
  bool ditemukan = false;

  cin.ignore();
  cout << "Masukkan tujuan yang dicari: ";
  getline(cin, tujuanCari);

  for (int i = front; i <= rear; i++) {
    if (queueJadwal[i].tujuan == tujuanCari) {
      cout << "\nData ditemukan:\n";
      cout << "Asal   : " << queueJadwal[i].asal << endl;
      cout << "Tujuan : " << queueJadwal[i].tujuan << endl;
      cout << "Waktu  : " << queueJadwal[i].waktu << endl;
      ditemukan = true;
    }
  }

  if (!ditemukan)
    cout << "Jadwal tidak ditemukan.\n";
}

void hapusJadwal() {
  if (isEmpty()) {
    cout << "Queue kosong.\n";
    return;
  }

  cout << "\nJadwal terdepan dihapus:\n";
  cout << "Asal   : " << queueJadwal[front].asal << endl;
  cout << "Tujuan : " << queueJadwal[front].tujuan << endl;
  cout << "Waktu  : " << queueJadwal[front].waktu << endl;

  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
}

void menuJadwalPerjalanan() {
  int pilih;

  do {
    cout << "\n=== MANAJEMEN JADWAL PERJALANAN ===\n";
    cout << "1. Tambah Jadwal\n";
    cout << "2. Tampilkan Semua Jadwal\n";
    cout << "3. Cari Jadwal\n";
    cout << "4. Hapus Jadwal\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
    cin >> pilih;

    switch (pilih) {
    case 1:
      tambahJadwal();
      break;
    case 2:
      tampilkanJadwal();
      break;
    case 3:
      cariJadwal();
      break;
    case 4:
      hapusJadwal();
      break;
    case 0:
      cout << "Kembali ke menu utama!\n";
      break;
    default:
      cout << "Pilihan tidak valid!\n";
    }
  } while (pilih != 0);
}
