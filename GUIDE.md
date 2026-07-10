# PANDUAN PENGGUNAAN
## Sistem Manajemen Transportasi MRT/KRL

---

## DAFTAR ISI

1. [Tentang Program](#tentang-program)
2. [Cara Menjalankan](#cara-menjalankan)
3. [Struktur Menu](#struktur-menu)
4. [Panduan Setiap Menu](#panduan-setiap-menu)
5. [Contoh Penggunaan Lengkap](#contoh-penggunaan-lengkap)
6. [Tips & Trik](#tips--trik)
7. [Troubleshooting](#troubleshooting)

---

## Tentang Program

**Sistem Manajemen Transportasi MRT/KRL** adalah aplikasi berbasis C++ untuk mengelola:

- **Stasiun** — Data lokasi dan wilayah
- **Rute** — Jalur perjalanan antar stasiun
- **Jadwal** — Waktu keberangkatan dan kedatangan
- **Penumpang** — Data pengguna transportasi
- **Perpindahan Jalur** — Informasi transfer antar jalur

**Fitur Utama:**
- Validasi otomatis untuk stasiun yang terdaftar
- Pembuatan rute otomatis saat penumpang/jadwal ditambahkan
- Pendeteksian wilayah (dalam/luar wilayah)
- Cascade delete (hapus stasiun, data terkait ikut terhapus)
- Semua data tersimpan di file teks (persisten)

---

## Cara Menjalankan

### Windows (PowerShell)

Buka terminal di folder project, lalu:

```powershell
g++ main.cpp -o program.exe
.\program.exe
```

### Dev-C++ / CodeBlocks

1. Buka file `main.cpp` di Dev-C++ / CodeBlocks
2. Pastikan semua file `.cpp` sudah masuk ke project
3. Tekan **F9** atau klik **Compile & Run**

---

## Struktur Menu

```
======================================
  SISTEM MANAJEMEN TRANSPORTASI MRT/KRL
======================================
1. Manajemen Stasiun
2. Manajemen Jadwal Perjalanan
3. Perpindahan Jalur
4. Pencarian Rute
5. Data Penumpang
0. Keluar
--------------------------------------
Pilihan:
```

---

## Panduan Setiap Menu

### Menu 1: Manajemen Stasiun

Kelola data stasiun di sistem.

| Submenu | Fungsi |
|---------|--------|
| 1 | Tambah Stasiun — Masukkan nama stasiun dan wilayah |
| 2 | Tampilkan Semua Stasiun — Lihat daftar lengkap stasiun |
| 3 | Cari Stasiun — Cari stasiun berdasarkan nama (data ditampilkan dulu) |
| 4 | Hapus Stasiun — Hapus stasiun + cascade delete data terkait (data ditampilkan dulu) |
| 0 | Kembali ke Menu Utama |

**Contoh Input:**
```
Masukkan Nama Stasiun : Jakarta Pusat
Masukkan Wilayah (contoh: Jakarta/Bandung/Tasikmalaya) : Jakarta
Stasiun berhasil ditambahkan!
```

---

### Menu 2: Manajemen Jadwal Perjalanan

Atur jadwal keberangkatan dan kedatangan kereta/MRT. Menggunakan struktur **Queue (FIFO)**.

| Submenu | Fungsi |
|---------|--------|
| 1 | Tambah Jadwal — Buat jadwal baru (asal, tujuan, waktu) |
| 2 | Tampilkan Semua Jadwal |
| 3 | Cari Jadwal — Cari berdasarkan stasiun tujuan (data ditampilkan dulu) |
| 4 | Hapus Jadwal — Hapus jadwal terdepan / paling lama (data ditampilkan dulu) |
| 5 | Ubah Status Jadwal — Scheduled / In-Progress / Completed / Delayed |
| 0 | Kembali ke Menu Utama |

**Catatan:** Stasiun asal dan tujuan harus sudah terdaftar di Menu 1.

**Contoh Input:**
```
Asal   : Jakarta Pusat
Tujuan : Bandung Station
Waktu  : 08:30
Jadwal berhasil ditambahkan ke queue. (Status: Scheduled)
```

---

### Menu 3: Perpindahan Jalur

Kelola informasi transfer / pindah jalur kereta. Menggunakan struktur **Array**.

| Submenu | Fungsi |
|---------|--------|
| 1 | Tambah Jalur — Buat data perpindahan jalur baru |
| 2 | Tampilkan Semua Jalur |
| 3 | Cari Jalur Perpindahan — Cari berdasarkan ID kereta (data ditampilkan dulu) |
| 4 | Hapus Jalur — Hapus data perpindahan (data ditampilkan dulu) |
| 0 | Kembali ke Menu Utama |

**Contoh Input:**
```
ID / Kode Kereta     : KRL001
Nama Stasiun Transit : Manggarai
Dari Jalur (Asal)    : Jakarta Pusat
Ke Jalur (Tujuan)    : Bogor
Waktu Pindah (HH:MM) : 10:15
[Sukses] Data perpindahan jalur berhasil ditambahkan!
```

---

### Menu 4: Pencarian Rute

Lihat dan kelola rute perjalanan. Menggunakan struktur **Stack (LIFO)**.

| Submenu | Fungsi |
|---------|--------|
| 1 | Cari Rute Tercepat — Cari rute dari stasiun tertentu (data ditampilkan dulu) |
| 2 | Tampilkan Semua Rute — Lihat daftar semua rute dengan label wilayah |
| 3 | Tambah Rute — Buat rute manual |
| 4 | Hapus Rute — Hapus rute terakhir / paling baru (data ditampilkan dulu) |
| 5 | Tampilkan Rute Dalam Wilayah — Filter rute satu wilayah |
| 6 | Tampilkan Rute Luar Wilayah — Filter rute antar wilayah |
| 0 | Kembali ke Menu Utama |

**Rute Otomatis:**
Saat menambah penumpang, jadwal, atau perpindahan jalur, rute akan dibuat otomatis. Sistem mendeteksi apakah rute tersebut **"Dalam Wilayah"** atau **"Luar Wilayah"**.

**Contoh Output:**
```
===== DAFTAR RUTE =====
1. Jakarta Pusat -> Bandung Station [Luar Wilayah (Jakarta -> Bandung)]
2. Bogor -> Manggarai [Luar Wilayah (Bogor -> Jakarta)]
3. Lebak Bulus -> Bundaran HI [Dalam Wilayah Jakarta]
```

---

### Menu 5: Data Penumpang

Kelola data penumpang. Menggunakan struktur **Linked List**.

| Submenu | Fungsi |
|---------|--------|
| 1 | Tambah Penumpang — Daftarkan penumpang baru (nomor urut otomatis) |
| 2 | Tampilkan Semua Penumpang |
| 3 | Cari Penumpang — Cari berdasarkan nama (data ditampilkan dulu) |
| 4 | Hapus Penumpang — Hapus data penumpang (data ditampilkan dulu) |
| 0 | Kembali ke Menu Utama |

**Catatan:**
- Setiap penumpang mendapat nomor urut otomatis
- Stasiun asal dan tujuan harus terdaftar di Menu 1
- Rute akan dibuat otomatis saat penumpang ditambahkan

**Contoh Input:**
```
Nama Penumpang : Budi Santoso
Stasiun Asal   : Jakarta Pusat
Stasiun Tujuan : Bandung Station
Penumpang berhasil ditambahkan! (Nomor: 1)
```

**Contoh Output (Tampilkan):**
```
=== DAFTAR PENUMPANG ===
------------------------------------------------------------
No  Nama          Asal            Tujuan
------------------------------------------------------------
1   Budi Santoso  Jakarta Pusat   Bandung Station
2   Siti Nurhaliza Bogor         Jakarta Pusat
------------------------------------------------------------
```

---

## Contoh Penggunaan Lengkap

### Skenario: Membuat Data Lengkap Perjalanan

#### Step 1: Tambah Stasiun (Menu 1)

```
Pilih: 1  ->  Masuk ke Manajemen Stasiun
Pilih: 1  ->  Tambah Stasiun

Masukkan Nama Stasiun : Jakarta Pusat
Masukkan Wilayah      : Jakarta
-> Stasiun berhasil ditambahkan!

Pilih: 1  ->  Tambah lagi
Masukkan Nama Stasiun : Bandung Station
Masukkan Wilayah      : Bandung
-> Stasiun berhasil ditambahkan!

Pilih: 1  ->  Tambah lagi
Masukkan Nama Stasiun : Bogor
Masukkan Wilayah      : Bogor
-> Stasiun berhasil ditambahkan!

Pilih: 0  ->  Kembali ke Menu Utama
```

#### Step 2: Tambah Penumpang (Menu 5)

```
Pilih: 5  ->  Masuk ke Data Penumpang
Pilih: 1  ->  Tambah Penumpang

Nama Penumpang   : Budi Santoso
Stasiun Asal     : Jakarta Pusat
Stasiun Tujuan   : Bandung Station
-> Penumpang berhasil ditambahkan! (Nomor: 1)

Pilih: 2  ->  Lihat semua penumpang
Output:
No  Nama          Asal            Tujuan
1   Budi Santoso  Jakarta Pusat   Bandung Station

Pilih: 0  ->  Kembali ke Menu Utama
```

#### Step 3: Lihat Rute (Menu 4)

```
Pilih: 4  ->  Masuk ke Pencarian Rute
Pilih: 2  ->  Tampilkan Semua Rute

Output:
===== DAFTAR RUTE =====
1. Jakarta Pusat -> Bandung Station [Luar Wilayah (Jakarta -> Bandung)]

Pilih: 5  ->  Tampilkan Rute Dalam Wilayah
Pilih: 6  ->  Tampilkan Rute Luar Wilayah

Pilih: 0  ->  Kembali ke Menu Utama
```

#### Step 4: Keluar

```
Pilih: 0
Output: Terima kasih! Sampai jumpa!
```

---

## Tips & Trik

### Yang Harus Dilakukan

| No | Tips | Keterangan |
|----|------|------------|
| 1 | **Tambah Stasiun Dulu** | Sebelum membuat jadwal/penumpang, pastikan stasiun sudah terdaftar |
| 2 | **Gunakan Nama Konsisten** | Ketik nama stasiun persis sama (case-sensitive) |
| 3 | **Cek Data Sebelum Hapus** | Sistem otomatis menampilkan data sebelum cari/hapus |
| 4 | **Perhatikan Wilayah** | Pilih wilayah yang sesuai saat menambah stasiun |

### Yang Jangan Dilakukan

| No | Larangan | Alasan |
|----|----------|--------|
| 1 | Hapus stasiun yang masih dipakai | Data terkait akan ikut terhapus (cascade delete) |
| 2 | Ubah nama stasiun | Hapus dan buat ulang dengan nama baru |
| 3 | Ketik nama stasiun berbeda | "Jakarta" != "jakarta" (huruf besar/kecil berbeda) |

### Fitur Otomatis

- **Nomor Penumpang Otomatis** — Setiap penumpang baru mendapat nomor urut
- **Rute Otomatis** — Saat tambah penumpang/jadwal/jalur, rute dibuat otomatis
- **Deteksi Wilayah** — Sistem otomatis menentukan rute dalam/luar wilayah
- **Cascade Delete** — Hapus stasiun, semua data terkait ikut terhapus

---

## Troubleshooting

| Masalah | Penyebab | Solusi |
|---------|----------|--------|
| "Stasiun belum terdaftar" | Stasiun belum ada di database | Tambahkan stasiun di Menu 1 terlebih dahulu |
| "g++ tidak ditemukan" | Compiler C++ belum terinstall | Install MinGW atau Dev-C++ |
| Program tidak berjalan | Mungkin ada error kompilasi | Compile ulang: `g++ main.cpp -o program.exe` |
| Data tidak muncul setelah restart | File .txt terhapus/rusak | Jangan hapus file .txt, atau buat ulang data dari menu |

---

## Struktur Data

| Modul | Struktur Data | Sifat |
|-------|---------------|-------|
| Stasiun | Linked List | Dinamis, tanpa batas kapasitas |
| Penumpang | Linked List | Dinamis, tanpa batas kapasitas |
| Jadwal | Queue (Array, max 100) | FIFO — pertama masuk, pertama keluar |
| Rute | Stack (Linked List) | LIFO — terakhir masuk, pertama keluar |
| Perpindahan Jalur | Array (max 100) | Akses acak cepat |

### Relasi Data

Setiap **Penumpang** dan **Rute** menyimpan **pointer langsung** ke node **Stasiun** (bukan string). Jika stasiun dihapus, cascade delete otomatis membersihkan semua data yang merujuk ke stasiun tersebut.

---

*Dibuat oleh Kelompok 4 — Praktikum Algoritma dan Struktur Data — 2026*
