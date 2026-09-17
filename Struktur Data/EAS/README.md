# **UAS STRUKTUR DATA (D)** - *Study Case*

|    **NRP**     |             **Nama**              |
|   :--------:   |          :------------:           |
| **5025251045** | **Khalisya Zahra Putria Rahman**  |

---

## 1. Deskripsi Aplikasi
Aplikasi **Smart Campus Navigation System** adalah solusi digital untuk membantu mahasiswa menemukan lokasi di dalam kampus, mengelola jadwal layanan konsultasi akademik secara adil, dan memberikan prioritas kepada pihak yang membutuhkan (seperti mahasiswa disabilitas atau darurat akademik). Aplikasi ini memanfaatkan berbagai macam struktur data untuk menjalankan setiap fiturnya secara efisien.

## 2. Pemetaan Struktur Data ke Fitur Sistem

Berikut adalah analisis dan pemilihan struktur data untuk memecahkan berbagai masalah di kampus:

1.  **Sistem Navigasi Rute Kampus -> Struktur Data: `Graph`**
    * **Alasan:** Gedung-gedung kampus dapat direpresentasikan sebagai titik simpul (*Vertex/Node*), sedangkan jalanan penghubungnya direpresentasikan sebagai garis (*Edge*). Dengan menggunakan algoritma Graph Traversal (seperti Breadth-First Search / BFS), sistem dapat menghitung jalur terpendek dari satu gedung ke gedung lainnya.
2.  **Antrian Layanan Akademik (Normal) -> Struktur Data: `Queue`**
    * **Alasan:** Menggunakan prinsip *First In First Out* (FIFO). Mahasiswa yang menekan tombol ambil nomor antrian lebih dulu, dipastikan akan dipanggil dan dilayani lebih awal.
3.  **Layanan Prioritas (Disabilitas/Darurat) -> Struktur Data: `Priority Queue (Heap)`**
    * **Alasan:** Meskipun antrian sudah penuh oleh mahasiswa normal, mahasiswa prioritas berhak diselipkan di urutan paling depan. *Priority Queue* otomatis mengurutkan antrian berdasarkan nilai tingkat prioritas tertinggi, bukan berdasarkan waktu kedatangan.
4.  **Riwayat & Pembatalan (Undo) -> Struktur Data: `Stack`**
    * **Alasan:** Menggunakan prinsip *Last In First Out* (LIFO). Jika mahasiswa melakukan kesalahan sistem (seperti salah memesan antrian), aktivitas yang *paling terakhir* dilakukan harus dibatalkan/dihapus pertama kali saat tombol *Undo* ditekan.

## 3. Implementasi Program C++
*(Source code terlampir pada file `code.cpp` di repositori ini, yang berisi menu terpadu untuk mendemonstrasikan ke-empat struktur data di atas).*

## 4. Simulasi & Screenshot Eksekusi

Berikut adalah log simulasi skenario yang dijalankan menggunakan program ini:

**Skenario:**
1. Mahasiswa "Andi" mendaftar antrian Normal.
2. Mahasiswa "Budi" mendaftar antrian Normal.
3. Tiba-tiba Mahasiswa "Siti" mendaftar antrian Prioritas.
4. Sistem memanggil mahasiswa. (Otomatis Siti dipanggil lebih dulu karena algoritma *Priority Queue*).
5. Pengguna mencari rute terpendek dari "Gerbang Depan" menuju "Kantin Pusat".
6. Pengguna menekan Undo untuk membatalkan riwayat pencarian tersebut.

**Screenshot Output Terminal:**
*(Silakan lampirkan gambar screenshot terminal di sini)*

> Catatan: 
> Ganti teks ini dengan `![Screenshot Aplikasi](path/ke/gambar.png)` setelah *commit* ke GitHub.