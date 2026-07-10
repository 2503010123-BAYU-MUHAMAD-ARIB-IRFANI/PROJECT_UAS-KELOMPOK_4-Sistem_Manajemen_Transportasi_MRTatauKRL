# Sistem Manajemen Transportasi MRT/KRL

Aplikasi berbasis **C++** untuk mengelola sistem transportasi MRT/KRL, mencakup manajemen stasiun, jadwal perjalanan, pencarian rute, perpindahan jalur, dan data penumpang. Proyek ini dikembangkan sebagai tugas UAS Praktikum Algoritma dan Struktur Data.

---

## Daftar Isi

1. [Anggota Kelompok](#anggota-kelompok)
2. [Fitur Aplikasi](#fitur-aplikasi)
3. [Struktur Data](#struktur-data)
4. [Relasi Data](#relasi-data)
5. [Cara Menjalankan](#cara-menjalankan)
6. [Panduan Penggunaan](#panduan-penggunaan)

---

## Anggota Kelompok

| No | Nama | NIM | Fitur | Struktur Data |
|----|------|-----|-------|---------------|
| 1 | Bayu Muhamad Arib Irfani | 2503010123 | Data Penumpang | Linked List |
| 2 | Ade Sodik | 2503010113 | Manajemen Stasiun | Linked List |
| 3 | Bimo Alviana Sofian | 2403010071 | Manajemen Jadwal | Queue |
| 4 | Fajri Presetya Permana | 2503010140 | Pencarian Rute | Stack |
| 5 | Zofan Aryaguna | 2503010109 | Perpindahan Jalur | Array |

---

## Fitur Aplikasi

### Menu Utama

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
```

### 1. Manajemen Stasiun (Ade)
| Submenu | Fungsi |
|---------|--------|
| 1. Tambah Stasiun | Menambahkan stasiun baru (nama + wilayah) |
| 2. Tampilkan Semua Stasiun | Menampilkan daftar seluruh stasiun |
| 3. Cari Stasiun | Mencari stasiun berdasarkan nama |
| 4. Hapus Stasiun | Menghapus stasiun + seluruh data terkait (cascade delete) |

### 2. Manajemen Jadwal Perjalanan (Bimo)
| Submenu | Fungsi |
|---------|--------|
| 1. Tambah Jadwal | Menambahkan jadwal baru (asal, tujuan, waktu) |
| 2. Tampilkan Semua Jadwal | Menampilkan seluruh jadwal yang tersimpan |
| 3. Cari Jadwal | Mencari jadwal berdasarkan stasiun tujuan |
| 4. Hapus Jadwal | Menghapus jadwal terdepan (FIFO) |
| 5. Ubah Status Jadwal | Mengubah status jadwal (Scheduled/In-Progress/Completed/Delayed) |

### 3. Perpindahan Jalur (Zofan)
| Submenu | Fungsi |
|---------|--------|
| 1. Tambah Jalur | Menambahkan data perpindahan jalur |
| 2. Tampilkan Semua Jalur | Menampilkan seluruh data perpindahan |
| 3. Cari Jalur Perpindahan | Mencari data berdasarkan ID kereta |
| 4. Hapus Jalur | Menghapus data perpindahan jalur |

### 4. Pencarian Rute (Fajri)
| Submenu | Fungsi |
|---------|--------|
| 1. Cari Rute Tercepat | Mencari rute dari stasiun tertentu |
| 2. Tampilkan Semua Rute | Menampilkan seluruh rute dengan label wilayah |
| 3. Tambah Rute | Menambahkan rute secara manual |
| 4. Hapus Rute | Menghapus rute terakhir (LIFO) |
| 5. Tampilkan Rute Dalam Wilayah | Filter rute dalam satu wilayah |
| 6. Tampilkan Rute Luar Wilayah | Filter rute antar wilayah |

### 5. Data Penumpang (Bayu)
| Submenu | Fungsi |
|---------|--------|
| 1. Tambah Penumpang | Mendaftarkan penumpang baru (nomor otomatis) |
| 2. Tampilkan Semua Penumpang | Menampilkan seluruh data penumpang |
| 3. Cari Penumpang | Mencari penumpang berdasarkan nama |
| 4. Hapus Penumpang | Menghapus data penumpang |

---

## Struktur Data

| Struktur Data | Digunakan Pada | Alasan |
|---------------|----------------|--------|
| **Singly Linked List** | Stasiun & Penumpang | Data dinamis tanpa batasan kapasitas |
| **Queue (Array)** | Jadwal Perjalanan | Prinsip FIFO, jadwal pertama masuk pertama diproses |
| **Stack (Linked List)** | Pencarian Rute | Prinsip LIFO untuk navigasi rute |
| **Array** | Perpindahan Jalur | Data sederhana dengan akses acak cepat |

### Arsitektur File

```
main.cpp              ← Entry point & menu utama
  ├── stasiun.cpp     ← Manajemen stasiun (Linked List)
  ├── rute.cpp        ← Pencarian rute (Stack)
  ├── Penumpang.cpp   ← Data penumpang (Linked List)
  ├── manajementJadwalPerjalanan.cpp  ← Jadwal (Queue)
  └── perpindahan_jalur.cpp           ← Perpindahan jalur (Array)
```

### Persistensi Data

| File | Format | Modul |
|------|--------|-------|
| `data_stasiun.txt` | `nama\|wilayah` | Stasiun |
| `data_rute.txt` | `asal\|tujuan\|wilayah` | Rute |
| `data_penumpang.txt` | `nomor\|nama\|asal\|tujuan` | Penumpang |
| `data_jadwal.txt` | `asal\|tujuan\|waktu\|status` | Jadwal |
| `data_jalur.txt` | `idKereta\|transit\|asal\|tujuan\|waktu` | Perpindahan Jalur |

---

## Relasi Data

Data antar modul saling terhubung secara **pointer-based** (bukan hanya string):

```
                     ┌─────────────────┐
                     │   STASIUN       │ ← Semua modul bergantung pada stasiun
                     │ (Linked List)   │
                     └────────┬────────┘
                              │
            ┌─────────────────┼──────────────────┐
            ▼                 ▼                    ▼
   ┌────────────────┐  ┌──────────────┐  ┌────────────────┐
   │   PENUMPANG    │  │    RUTE      │  │ JADWAL & JALUR │
   │ Node* asal     │  │ Node* asal   │  │ (string ref)   │
   │ Node* tujuan   │  │ Node* tujuan │  │                │
   └────────────────┘  └──────────────┘  └────────────────┘
```

**Aturan Relasi:**
- **Penumpang & Rute** menyimpan **pointer langsung** ke node stasiun (bukan string)
- Jika stasiun dihapus, **cascade delete** otomatis menghapus:
  - Semua penumpang yang menggunakan stasiun tersebut
  - Semua rute yang menggunakan stasiun tersebut
  - Semua jadwal terkait
  - Semua data perpindahan jalur terkait
- Saat menambah penumpang atau jadwal, **rute otomatis dibuat** dengan deteksi wilayah
- Semua data dimuat dari file saat program dijalankan

---

## Cara Menjalankan

### Windows (PowerShell)

```powershell
g++ main.cpp -o program
.\program.exe
```

### Dev-C++ / CodeBlocks
1. Buka project, pastikan semua file `.cpp` sudah ditambahkan
2. Tekan **F9** (Compile & Run)

---

## Panduan Penggunaan

### Urutan Penggunaan yang Disarankan

```
1. Tambah Stasiun (Menu 1)
       ↓
2. Tambah Penumpang / Jadwal / Jalur (Menu 2, 3, 5)
       ↓
3. Lihat Rute (Menu 4) — rute dibuat otomatis
```

### Contoh Alur Lengkap

**Step 1 — Tambah Stasiun**
```
Pilih Menu 1 → 1 (Tambah Stasiun)
Nama Stasiun : Jakarta Pusat
Wilayah      : Jakarta
→ Stasiun berhasil ditambahkan!
```
Tambahkan minimal 2 stasiun dengan wilayah berbeda untuk melihat fitur rute luar wilayah.

**Step 2 — Tambah Penumpang**
```
Pilih Menu 5 → 1 (Tambah Penumpang)
Nama          : Budi Santoso
Stasiun Asal  : Jakarta Pusat
Stasiun Tujuan: Bandung Station
→ Penumpang berhasil ditambahkan!
```
Rute otomatis terbuat: `Jakarta Pusat -> Bandung Station [Luar Wilayah]`

**Step 3 — Lihat Rute**
```
Pilih Menu 4 → 2 (Tampilkan Semua Rute)
→ Melihat daftar rute yang sudah ada
```

### Catatan Penting
- Stasiun harus didaftarkan **sebelum** digunakan di menu lain
- Gunakan nama stasiun yang **sama persis** (case-sensitive)
- Jangan hapus stasiun yang masih memiliki data terkait — sistem akan otomatis menghapus data terkait (cascade delete)

---

## Troubleshooting

| Masalah | Solusi |
|---------|--------|
| "Stasiun belum terdaftar" | Tambahkan stasiun di Menu 1 terlebih dahulu |
| "g++ tidak ditemukan" | Install MinGW atau gunakan Dev-C++ |
| Program tidak berjalan | Compile ulang: `g++ main.cpp -o program` |
| Data tidak muncul setelah restart | Pastikan file `.txt` tidak dihapus atau rusak |

---

Dibuat oleh **Kelompok 4** — Praktikum Algoritma dan Struktur Data — 2026
