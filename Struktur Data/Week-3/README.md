# Tugas Mata Kuliah Struktur Data - Week 3 (2026)

**Nama:** Khalisya Zahra Putria Rahman  
**Materi:** Array of C++  
**Link Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-3) 

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

