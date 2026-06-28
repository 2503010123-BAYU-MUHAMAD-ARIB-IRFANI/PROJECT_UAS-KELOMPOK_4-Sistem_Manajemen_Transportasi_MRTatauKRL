# 🚇 Sistem Manajemen Transportasi MRT/KRL

## 📋 Deskripsi Proyek
Aplikasi berbasis C++ untuk mengelola sistem transportasi MRT/KRL, mencakup manajemen stasiun, jadwal perjalanan, pencarian rute, perpindahan jalur, dan data penumpang. Proyek ini dikembangkan sebagai tugas UAS Praktikum Algoritma dan Struktur Data.

---

## 👥 Anggota Kelompok 4

| No | Nama | NIM | Fitur | Struktur Data |
|----|------|-----|-------|---------------|
| 1 | Bayu Muhamad Arib Irfani | 2503010123 | Data Penumpang | Linked List |
| 2 | Ade Sodik | 2503010113 | Manajemen Stasiun | Linked List |
| 3 | Bimo Alviana Sofian | 2403010071 | Manajemen Jadwal | Queue |
| 4 | Fajri Presetya Permana | 2503010140 | Pencarian Rute | Stack |
| 5 | Zofan Aryaguna | 2503010109 | Perpindahan Jalur | Array |

---

## 🎯 Fitur Aplikasi

### 1. Manajemen Stasiun (Ade)
- Tambah Stasiun
- Tampilkan Semua Stasiun
- Cari Stasiun
- Hapus Stasiun

### 2. Manajemen Jadwal Perjalanan (Bimo)
- Tambah Jadwal
- Tampilkan Semua Jadwal
- Cari Jadwal
- Hapus Jadwal

### 3. Perpindahan Jalur (Zofan)
- Tambah Jalur
- Tampilkan Semua Jalur
- Cari Jalur Perpindahan
- Hapus Jalur

### 4. Pencarian Rute (Fajri)
- Tambah Rute
- Tampilkan Semua Rute
- Cari Rute Tercepat
- Hapus Rute

### 5. Data Penumpang (Bayu)
- Tambah Penumpang
- Tampilkan Semua Penumpang
- Cari Penumpang
- Hapus Penumpang

---

## 🧱 Struktur Data yang Digunakan

| Struktur Data | Digunakan Pada | Alasan |
|---------------|----------------|--------|
| Linked List | Data Penumpang & Stasiun | Data bersifat dinamis, dapat bertambah dan berkurang tanpa batasan kapasitas |
| Queue | Manajemen Jadwal | Jadwal bersifat antrian (FIFO), jadwal pertama masuk pertama diproses |
| Stack | Pencarian Rute | Bersifat LIFO, rute terakhir masuk pertama keluar |
| Array | Perpindahan Jalur | Data bersifat sederhana dan mudah diakses |

---

## 🛠️ Teknologi
- Bahasa: C++
- Compiler: G++ / Dev-C++
- Tools: GitHub, Flowgorithm

---

## 🚀 Cara Menjalankan

### 💻 Via Laptop
1. Clone repository ini
```bash
git clone https://github.com/2503010123-BAYU-MUHAMAD-ARIB-IRFANI/PROJECT_UAS-KELOMPOK_4-Sistem_Manajemen_Transportasi_MRTatauKRL.git
```
2. Masuk ke folder project
```bash
cd PROJECT_UAS-KELOMPOK_4-Sistem_Manajemen_Transportasi_MRTatauKRL
```
3. Compile program
```bash
g++ main.cpp -o program
```
4. Jalankan program
```bash
./program
```

### 📱 Via HP
1. Download aplikasi **Replit** di Play Store / App Store
2. Login atau daftar akun Replit
3. Buat project baru pilih bahasa **C++**
4. Copy paste kode dari repository ke Replit
5. Klik tombol **Run** untuk menjalankan program

---

## 📤 Cara Upload ke GitHub

### 💻 Via Laptop
1. Clone repository
```bash
git clone https://github.com/2503010123-BAYU-MUHAMAD-ARIB-IRFANI/PROJECT_UAS-KELOMPOK_4-Sistem_Manajemen_Transportasi_MRTatauKRL.git
```
2. Masuk ke folder project
```bash
cd PROJECT_UAS-KELOMPOK_4-Sistem_Manajemen_Transportasi_MRTatauKRL
```
3. Pindah ke branch masing-masing
```bash
git checkout brach-[nama]
```
4. Tambahkan file yang sudah dibuat
```bash
git add .
```
5. Commit perubahan
```bash
git commit -m "Tambah fitur [nama fitur]"
```
6. Push ke branch masing-masing
```bash
git push origin brach-[nama]
```
7. Buat Pull Request di GitHub

### 📱 Via HP
1. Download aplikasi **GitHub** di Play Store / App Store
2. Login ke akun GitHub masing-masing
3. Cari repository ini
4. Pindah ke branch masing-masing
5. Klik tombol **+** untuk tambah file baru
6. Isi nama file dan kode program
7. Klik **Commit changes**
8. Buat Pull Request ke main

---

## 📊 Alur Kerja GitHub
1. Setiap anggota bekerja di branch masing-masing
2. Tidak ada yang langsung push ke branch main
3. Setiap anggota membuat Pull Request setelah selesai
4. Lead Developer (Ketua) melakukan review sebelum merge

---

## 📚 Sumber Belajar
- Materi Praktikum Algoritma dan Struktur Data
- cplusplus.com
- geeksforgeeks.org
