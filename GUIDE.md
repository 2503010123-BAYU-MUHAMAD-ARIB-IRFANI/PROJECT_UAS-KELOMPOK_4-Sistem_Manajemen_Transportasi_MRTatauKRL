# 📋 PANDUAN PENGGUNAAN
## Sistem Manajemen Transportasi MRT/KRL

---

## 📌 DAFTAR ISI
1. [Tentang Program](#tentang-program)
2. [Cara Menjalankan](#cara-menjalankan)
3. [Menu Utama](#menu-utama)
4. [Panduan Setiap Menu](#panduan-setiap-menu)
5. [Contoh Penggunaan Lengkap](#contoh-penggunaan-lengkap)
6. [Tips & Trik](#tips--trik)

---

## 🎯 Tentang Program

**Sistem Manajemen Transportasi MRT/KRL** adalah aplikasi berbasis C++ yang dirancang untuk mengelola:
- 📍 **Stasiun** - Data lokasi dan wilayah
- 🛣️ **Rute** - Jalur perjalanan antar stasiun
- 📅 **Jadwal** - Waktu keberangkatan dan kedatangan
- 👥 **Penumpang** - Data pengguna transportasi
- 🔄 **Perpindahan Jalur** - Informasi transfer antar jalur

**Fitur Utama:**
- ✅ Validasi otomatis untuk stasiun yang terdaftar
- ✅ Pembuatan rute otomatis saat penumpang ditambahkan
- ✅ Pendeteksian wilayah (dalam/luar wilayah)
- ✅ Pencarian data berbagai kategori

---

## 🚀 Cara Menjalankan

### **Windows (Terminal PowerShell)**

1. **Buka PowerShell** di folder project
2. **Kompilasi program:**
   ```powershell
   g++ *.cpp -o program.exe
   ```
3. **Jalankan program:**
   ```powershell
   .\program.exe
   ```

### **Dev-C++ / Code Blocks**
1. Buka project file
2. Pastikan semua file `.cpp` sudah ditambahkan di project settings
3. Tekan **F9** atau klik **Compile & Run**

---

## 📊 Menu Utama

Saat program dijalankan, Anda akan melihat menu dengan 5 pilihan:

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

## 📖 Panduan Setiap Menu

### **MENU 1: Manajemen Stasiun** 🏢

Kelola data stasiun di sistem.

**Submenu:**
- **1. Tambah Stasiun** - Masukkan nama stasiun dan wilayahnya
- **2. Tampilkan Semua Stasiun** - Lihat daftar lengkap stasiun
- **3. Cari Stasiun** - Cari stasiun berdasarkan nama
- **4. Hapus Stasiun** - Hapus stasiun dari database
- **0. Kembali** - Kembali ke menu utama

**Contoh Input:**
```
Masukkan Nama Stasiun : Jakarta Pusat
Masukkan Wilayah (contoh: Jakarta/Bandung/Tasikmalaya) : Jakarta
→ Stasiun berhasil ditambahkan!
```

---

### **MENU 2: Manajemen Jadwal Perjalanan** 📅

Atur jadwal keberangkatan dan kedatangan kereta/MRT.

**Submenu:**
- **1. Tambah Jadwal** - Buat jadwal baru (asal → tujuan → waktu)
- **2. Tampilkan Semua Jadwal** - Lihat semua jadwal yang ada
- **3. Cari Jadwal** - Cari berdasarkan stasiun tujuan
- **4. Hapus Jadwal** - Hapus jadwal (FIFO - yang pertama dihapus dulu)
- **0. Kembali** - Kembali ke menu utama

**Catatan:** 
- Stasiun asal dan tujuan harus sudah terdaftar di Menu 1
- Sistem menggunakan struktur Queue (antrian)

**Contoh Input:**
```
Asal   : Jakarta Pusat
Tujuan : Bandung Station
Waktu  : 08:30
→ Jadwal berhasil ditambahkan ke queue.
```

---

### **MENU 3: Perpindahan Jalur** 🔄

Kelola informasi transfer/pindah jalur kereta.

**Submenu:**
- **1. Tambah Jalur** - Buat data perpindahan jalur baru
- **2. Tampilkan Semua Jalur** - Lihat semua data perpindahan
- **3. Cari Jalur Perpindahan** - Cari berdasarkan ID kereta
- **4. Hapus Jalur** - Hapus data perpindahan
- **0. Kembali** - Kembali ke menu utama

**Contoh Input:**
```
ID / Kode Kereta     : KRL001
Nama Stasiun Transit : Manggarai
Dari Jalur (Asal)    : Jakarta Pusat
Ke Jalur (Tujuan)    : Bogor
Waktu Pindah (JAM:MENIT) : 10:15
→ [Sukses] Data perpindahan jalur berhasil ditambahkan!
```

---

### **MENU 4: Pencarian Rute** 🛣️

Lihat dan kelola rute perjalanan yang tersedia.

**Submenu:**
- **1. Cari Rute Tercepat** - Cari rute dari stasiun tertentu
- **2. Tampilkan Semua Rute** - Lihat daftar semua rute dengan label wilayah
- **3. Tambah Rute** - Buat rute manual
- **4. Hapus Rute** - Hapus rute (LIFO - yang terakhir dihapus dulu)
- **5. Tampilkan Rute Dalam Wilayah** - Filter rute yang masih dalam satu wilayah
- **6. Tampilkan Rute Luar Wilayah** - Filter rute antar wilayah
- **0. Kembali** - Kembali ke menu utama

**Rute Otomatis:**
- Saat Anda menambah penumpang atau jadwal, rute akan dibuat otomatis
- Sistem mendeteksi apakah rute itu "Dalam Wilayah" atau "Luar Wilayah"

**Contoh Output:**
```
===== DAFTAR RUTE =====
1. Jakarta Pusat -> Bandung Station [Luar Wilayah (Jakarta -> Bandung)]
2. Bogor -> Manggarai [Luar Wilayah (Bogor -> Jakarta)]
3. Lebak Bulus -> Bundaran HI [Dalam Wilayah Jakarta]
```

---

### **MENU 5: Data Penumpang** 👥

Kelola data penumpang dan perjalanan mereka.

**Submenu:**
- **1. Tambah Penumpang** - Daftarkan penumpang baru (auto-numbered)
- **2. Tampilkan Semua Penumpang** - Lihat daftar semua penumpang
- **3. Cari Penumpang** - Cari penumpang berdasarkan nama
- **4. Hapus Penumpang** - Hapus data penumpang
- **0. Kembali** - Kembali ke menu utama

**Catatan:**
- Setiap penumpang mendapat nomor urut otomatis
- Stasiun asal dan tujuan harus terdaftar di Menu 1
- Rute akan dibuat otomatis saat penumpang ditambahkan

**Contoh Input:**
```
=== TAMBAH PENUMPANG ===
Nama Penumpang : Budi Santoso
Stasiun Asal   : Jakarta Pusat
Stasiun Tujuan : Bandung Station
→ ✓ Penumpang berhasil ditambahkan! (Nomor: 1)
```

**Contoh Output (Tampilkan):**
```
=== DAFTAR PENUMPANG ===
--------------------------------------------
No	Nama		Asal		Tujuan
--------------------------------------------
1	Budi Santoso	Jakarta Pusat	Bandung Station
2	Siti Nurhaliza	Bogor		Jakarta Pusat
--------------------------------------------
```

---

## 💡 Contoh Penggunaan Lengkap

### **Skenario: Membuat Data Lengkap untuk Perjalanan**

#### **Step 1: Tambah Stasiun (Menu 1)**
```
Input: 1
→ Menu Manajemen Stasiun

Input: 1
→ Pilih "Tambah Stasiun"

Input: Jakarta Pusat
Input: Jakarta
→ Stasiun berhasil ditambahkan!

Input: 1 (Tambah lagi)
Input: Bandung Station
Input: Bandung
→ Stasiun berhasil ditambahkan!

Input: 1 (Tambah lagi)
Input: Bogor
Input: Bogor
→ Stasiun berhasil ditambahkan!

Input: 0
→ Kembali ke menu utama
```

#### **Step 2: Tambah Penumpang (Menu 5)**
```
Input: 5
→ Menu Data Penumpang

Input: 1
→ Pilih "Tambah Penumpang"

Input: Budi Santoso
Input: Jakarta Pusat
Input: Bandung Station
→ ✓ Penumpang berhasil ditambahkan! (Nomor: 1)

Input: 2
→ Lihat semua penumpang

Output:
No	Nama		Asal		Tujuan
1	Budi Santoso	Jakarta Pusat	Bandung Station

Input: 0
→ Kembali ke menu utama
```

#### **Step 3: Lihat Rute (Menu 4)**
```
Input: 4
→ Menu Pencarian Rute

Input: 2
→ Tampilkan Semua Rute

Output:
===== DAFTAR RUTE =====
1. Jakarta Pusat -> Bandung Station [Luar Wilayah (Jakarta -> Bandung)]
2. Lebak Bulus -> Bundaran HI [Dalam Wilayah Jakarta]
...dst

Input: 6
→ Tampilkan Rute Luar Wilayah

Output:
===== RUTE LUAR WILAYAH =====
Jakarta Pusat -> Bandung Station [Luar Wilayah (Jakarta -> Bandung)]
...

Input: 0
→ Kembali ke menu utama
```

#### **Step 4: Keluar**
```
Input: 0
→ Keluar dari program

Output:
Terima kasih! Sampai jumpa!
```

---

## 🎓 Tips & Trik

### **✅ Yang Harus Dilakukan:**

1. **Tambah Stasiun Dulu**
   - Sebelum membuat jadwal atau penumpang, pastikan stasiun sudah terdaftar di Menu 1

2. **Gunakan Nama Konsisten**
   - Saat menambah jadwal/penumpang, ketik nama stasiun persis sama dengan yang terdaftar

3. **Periksa Data Sebelum Menghapus**
   - Gunakan submenu "Tampilkan" untuk cek data sebelum menghapus

4. **Perhatikan Wilayah**
   - Saat membuat stasiun, pilih wilayah yang sesuai (Jakarta, Bandung, Bogor, dll)

---

### **❌ Yang Jangan Dilakukan:**

1. **Jangan Hapus Stasiun yang Masih Dipakai**
   - Bisa membuat rute menjadi tidak valid

2. **Jangan Ubah Nama Stasiun**
   - Hapus dan buat ulang dengan nama baru

3. **Jangan Ketik Nama Stasiun Berbeda**
   - "Jakarta" ≠ "jakarta" (huruf besar/kecil berbeda)

---

### **💡 Fitur Otomatis yang Perlu Diketahui:**

- **Nomor Penumpang Otomatis**: Setiap penumpang baru mendapat nomor urut
- **Rute Otomatis**: Saat tambah penumpang/jadwal, rute dibuat otomatis
- **Deteksi Wilayah**: Sistem otomatis tahu apakah rute itu dalam/luar wilayah

---

## 📞 Troubleshooting

### **Error: Stasiun belum terdaftar**
**Penyebab:** Stasiun yang dimasukkan belum ada di database  
**Solusi:** Tambahkan stasiun dulu di Menu 1

### **Error: g++ tidak ditemukan**
**Penyebab:** Compiler C++ belum terinstall  
**Solusi:** Install MinGW atau DevC++

### **Program crash saat dijalankan**
**Penyebab:** Mungkin ada error di kode  
**Solusi:** Cek di Dev-C++ atau compile ulang dengan `g++ *.cpp -o program.exe`

---

## 📝 Struktur Data

Program menggunakan beberapa struktur data:

```
Stasiun      → Linked List
Rute         → Linked List Stack
Penumpang    → Linked List
Jadwal       → Array Queue
Perpindahan  → Array
```

---

## 🎉 Selamat Menggunakan!

Semoga program ini memudahkan Anda dalam mengelola sistem transportasi MRT/KRL.  
Jika ada pertanyaan atau kendala, silakan hubungi developer.

**Dibuat oleh:** Kelompok 4  
**Tahun:** 2024
