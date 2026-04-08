# Tugas Struktur Data - Week 3 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-3)

Repositori ini berisi kumpulan implementasi program C++ yang mendemonstrasikan berbagai operasi dasar hingga lanjutan pada struktur data **Array**. Cakupan materi meliputi inisialisasi array, manipulasi data dan alamat memori, operasi aritmetika (total, rata-rata, pencarian nilai maksimum), seleksi kondisi, hingga penggunaan tipe data bentukan (*Array of Struct*) untuk menyimpan informasi yang lebih kompleks.

---

## 1. Inisialisasi dan Pencetakan Array Statis

**Penjelasan Kode:**
Program ini bertujuan untuk mendemonstrasikan pembuatan array statis secara langsung. Di dalam fungsi `main`, sebuah array integer diinisialisasi dengan 4 nilai. Perulangan `for` digunakan untuk melakukan iterasi dan mencetak setiap elemen array berdasarkan indeksnya (dari 0 hingga 3).

```cpp
#include<iostream>
using namespace std;

int main(){
    int myArray[] = {2,4,6,8};
    for(int i=0; i<4; i++){
        cout << myArray[i] << endl;
    }
    return 0;
}

```

**Output:**
```txt
2
4
6
8
```
---
## 2. Akses Batas Memori (Out of Bounds) dan Alamat Memori

**Penjelasan Kode:**
Program ini menunjukkan cara mengakses alamat memori fisik dari elemen array menggunakan operator address-of (`&`). Di dalam fungsi `main`, perulangan sengaja diatur melebihi ukuran array (`i<=8` pada array berukuran 4). Hal ini mendemonstrasikan perilaku C++ saat membaca memori yang berada di luar batas alokasi array (out of bounds).

```cpp
#include<iostream>
using namespace std;

int main(){
    int myArray[] = {2,4,6,8};
    for(int i=0; i<=8; i++){
        cout << myArray[i] << endl;
        cout << "id: " << &myArray[i] << endl;
    }
    return 0;
}

```

**Output:**
```txt
2
id: 0x61fdf0
4
id: 0x61fdf4
6
id: 0x61fdf8
8
id: 0x61fdfc
1983354384 
id: 0x61fe00
32765
id: 0x61fe04
0
id: 0x61fe08
0
id: 0x61fe0c
4200112
id: 0x61fe10
```
---

## 3. Input dan Output Elemen Array Dinamis
   
**Penjelasan Kode:**
Program ini meminta interaksi pengguna untuk mengisi elemen array. Fungsi `main` mendeklarasikan array berukuran 5. Perulangan `for` pertama digunakan untuk menerima input dari pengguna dan menyimpannya ke dalam array menggunakan `cin`. Perulangan kedua digunakan untuk mencetak kembali data yang telah berhasil disimpan.

```cpp
#include<iostream>
using namespace std;

int main(){
    int nilai[5];

    for(int i=0; i<5; i++){
        cout << "Masukkan nilai ke-" << i << " : ";
        cin >> nilai[i];
    }
    cout << "\nData yang dimasukkan:" << endl;

    for(int i=0; i<5; i++){
        cout << nilai[i] << endl;
    }
    return 0;
}

```
**Input:**
```txt
Masukkan nilai ke-0 : 10
Masukkan nilai ke-1 : 20
Masukkan nilai ke-2 : 30
Masukkan nilai ke-3 : 40
Masukkan nilai ke-4 : 50
```
**Output:**
```txt
Data yang dimasukkan:
10
20
30
40
50
```
---

## 4. Perhitungan Total dan Rata-Rata Data Array

**Penjelasan Kode:**
Program ini menerapkan operasi aritmetika pada elemen array. Pada fungsi `main`, variabel `total` digunakan sebagai akumulator. Seiring perulangan meminta input dari pengguna, nilai tersebut langsung ditambahkan ke `total`. Setelah perulangan selesai, rata-rata (`mean`) dihitung dengan membagi `total` menggunakan tipe data `float` (5.0) agar hasil pembagian desimal tetap akurat.

```cpp
#include<iostream>
using namespace std;

int main(){
    int nilai[5];
    int total=0;
    float mean;

    for(int i=0; i<5; i++){
        cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
        cin >> nilai[i];
        total += nilai[i];
    }
    mean = total / 5.0;

    cout << "\nTotal nilai : " << total << endl;
    cout << "Rata-rata : " << mean << endl;
    
    return 0;
}
```

**Input:**
```txt
Masukkan nilai mahasiswa ke-1 : 80
Masukkan nilai mahasiswa ke-2 : 85
Masukkan nilai mahasiswa ke-3 : 90
Masukkan nilai mahasiswa ke-4 : 75
Masukkan nilai mahasiswa ke-5 : 70
```

**Output:**
```txt
Total nilai : 400
Rata-rata : 80
```
---

## 5. Pencarian Nilai Maksimum pada Array

**Penjelasan Kode:**
Program ini mengimplementasikan algoritma pencarian sederhana. Setelah menerima input 5 nilai pada fungsi `main`, program menginisialisasi variabel `max` dengan elemen pertama array (`nilai[0]`). Perulangan selanjutnya akan membandingkan nilai `max` dengan elemen array lainnya. Jika ditemukan elemen yang lebih besar, nilai `max` akan diperbarui.

```cpp
#include<iostream>
using namespace std;

int main(){
    int nilai[5];
    int max;

    for(int i=0; i<5; i++){
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai[i];
    }

    max = nilai[0];
    for(int i=1; i<5; i++){
        if(nilai[i] > max) max = nilai[i];
    }

    cout << "Nilai tertinggi adalah : " << max << endl;
    return 0;
}
```
**Input:**
```txt
Masukkan nilai ke-1 : 60
Masukkan nilai ke-2 : 85
Masukkan nilai ke-3 : 95
Masukkan nilai ke-4 : 70
Masukkan nilai ke-5 : 80
```
**Output:**
```txt
Nilai tertinggi adalah : 95
```
---

## 6. Implementasi Logika Kondisional (Status Kelulusan)

**Penjelasan Kode:**
Program ini menggabungkan array dengan struktur kontrol logika `if-else`. Setelah fungsi `main` menerima dan menyimpan daftar nilai mahasiswa, perulangan kedua akan mengevaluasi setiap nilai. Jika elemen bernilai $\geq 75$, program mencetak status "Lulus", sedangkan untuk nilai di bawah itu mencetak "Tidak Lulus".

```cpp
#include<iostream>
using namespace std;

int main(){
    int nilai[5];
    
    for(int i=0; i<5; i++){
        cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
        cin >> nilai[i];
    }

    cout << "\nStatus Kelulusan\n";
    for(int i=0; i<5; i++){
        if(nilai[i] >= 75) cout << "Mahasiswa " << i+1 << " : Lulus" << endl;
        else cout << "Mahasiswa " << i+1 << " : Tidak Lulus" << endl;
    }
    return 0;
}
```
**Input:**
```txt
Masukkan nilai mahasiswa ke-1 : 70
Masukkan nilai mahasiswa ke-2 : 80
Masukkan nilai mahasiswa ke-3 : 75
Masukkan nilai mahasiswa ke-4 : 60
Masukkan nilai mahasiswa ke-5 : 90
```
**Output:**
```txt
Status Kelulusan
Mahasiswa 1 : Tidak Lulus
Mahasiswa 2 : Lulus
Mahasiswa 3 : Lulus
Mahasiswa 4 : Tidak Lulus
Mahasiswa 5 : Lulus
```
---

## 7. Penggunaan Array of Struct untuk Data Terstruktur

**Penjelasan Kode:**

`struct Mahasiswa`: `struct` (struktur) digunakan untuk mengelompokkan berbagai variabel dengan tipe data berbeda (seperti `string` untuk nama, `int` untuk umur, dan array `string` untuk daftar hobi) ke dalam satu entitas yang sama. Ini mempermudah pengelolaan data yang kompleks.

`main()`: Mendeklarasikan array `mhs[3]` yang bertipe `Mahasiswa`, artinya program menyiapkan ruang untuk menyimpan data lengkap dari 3 mahasiswa berbeda. Perulangan pertama berfungsi untuk meminta pengisian atribut data (NPM, Nama, Jurusan, dll), sedangkan perulangan kedua berfungsi untuk menampilkan struktur data tersebut secara rapi.

```cpp
#include<iostream>
#include<string>
using namespace std;

struct Mahasiswa{
    string npm, nama, jurusan;
    int umur;
    string hobi[3];
};

int main(){
    Mahasiswa mhs[3];
    
    for(int i=0; i<3; i++){
        cout << "Data Mahasiswa ke-" << i+1 << endl;

        cout << "NPM    : ";
        cin >> mhs[i].npm;

        cout << "Nama   : ";
        cin >> mhs[i].nama;

        cout << "Jurusan: ";
        cin >> mhs[i].jurusan;

        cout << "Umur   : ";
        cin >> mhs[i].umur;

        cout << "Masukkan 3 Hobi:" << endl;
        for(int j=0; j<3; j++){
            cout << "Hobi ke-" << j+1 << " : ";
            cin >> mhs[i].hobi[i]; 
        }
        cout << endl;
    }
    
    cout << "\n==== DATA MAHASISWA ====\n";
    for(int i=0; i<3; i++){
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "NPM    : " << mhs[i].npm << endl;
        cout << "Nama   : " << mhs[i].nama << endl;
        cout << "Jurusan: " << mhs[i].jurusan << endl;
        cout << "Umur   : " << mhs[i].umur << endl;
        cout << "Hobi   : ";
        for(int j=0; j<3; j++){
            cout << mhs[i].hobi[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

```
**Input:**
```txt
Data Mahasiswa ke-1
NPM    : 5025251045
Nama   : Khalisya
Jurusan: Informatika
Umur   : 18
Masukkan 3 Hobi:
Hobi ke-1 : Membaca
Hobi ke-2 : Menulis
Hobi ke-3 : Nyanyi

Data Mahasiswa ke-2
NPM    : 5025101001
Nama   : Seby
Jurusan: Informatika
Umur   : 19
Masukkan 3 Hobi:
Hobi ke-1 : Masak
Hobi ke-2 : Tidur
Hobi ke-3 : Ngoding

Data Mahasiswa ke-3
NPM    : 5025261092
Nama   : Elsa
Jurusan: Kimia
Umur   : 17
Masukkan 3 Hobi:
Hobi ke-1 : Main_Game
Hobi ke-2 : Makan
Hobi ke-3 : Nonton
```
**Output:**
```txt
==== DATA MAHASISWA ====

Mahasiswa ke-1
NPM    : 5025251045
Nama   : Khalisya
Jurusan: Informatika
Umur   : 18
Hobi   : Membaca Menulis Nyanyi

Mahasiswa ke-2
NPM    : 5025101001
Nama   : Seby
Jurusan: Informatika
Umur   : 19
Hobi   : Masak Tidur Ngoding 

Mahasiswa ke-3
NPM    : 5025261092
Nama   : Elsa
Jurusan: Kimia
Umur   : 17
Hobi   : Main_Game Makan Nonton 
```
