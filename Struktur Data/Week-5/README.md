# Tugas Struktur Data - Week 5 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-5)

Repositori ini berisi penjelasan dan implementasi program C++ yang mendemonstrasikan operasi dasar pada struktur data **Stack** serta penerapannya. Stack adalah struktur data linear dengan prinsip **LIFO (Last In, First Out)**, di mana elemen yang terakhir kali dimasukkan akan menjadi elemen pertama yang dikeluarkan. Proses penambahan (`push`) dan penghapusan (`pop`) elemen hanya dapat dilakukan melalui satu titik yang disebut puncak tumpukan (`top`). 

---

## 1. Implementasi Stack Menggunakan Array (Statis)

**Penjelasan Kode:**
Program ini mendemonstrasikan pembuatan Stack menggunakan Array dengan batas maksimal yang sudah ditentukan (`MAX 5`). Variabel `top` diinisialisasi dengan `-1` untuk menandakan bahwa stack dalam keadaan kosong. Pada fungsi `push`, program akan mengecek apakah stack sudah penuh (kondisi *Overflow*). Jika belum, indeks `top` ditambah dan elemen dimasukkan. Pada fungsi `pop`, program mengecek apakah stack kosong (kondisi *Underflow*). Jika tidak, nilai pada indeks `top` dikeluarkan dan indeks `top` dikurangi. Fungsi `peek` digunakan untuk melihat elemen paling atas tanpa menghapusnya.

```cpp
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; // stack kosong
    }

    // Push
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
            cout << x << " ditambahkan ke stack\n";
        }
    }

    // Pop
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top--] << " dihapus dari stack\n";
        }
    }

    // Peek
    void peek() {
        if (top == -1) {
            cout << "Stack kosong\n";
        } else {
            cout << "Elemen teratas: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}
```

**Output:**
```txt
10 ditambahkan ke stack
20 ditambahkan ke stack
30 ditambahkan ke stack
Elemen teratas: 30
30 dihapus dari stack
Elemen teratas: 20
```

---

## 2. Implementasi Stack Menggunakan Linked List (Dinamis)

**Penjelasan Kode:**
Program ini menyelesaikan masalah batasan kapasitas pada Array dengan merepresentasikan Stack sebagai **Linked List**. Setiap elemen disimpan di dalam struktur `Node` yang memiliki `data` dan sebuah *pointer* (`next`) yang menunjuk ke node berikutnya di bawahnya. 
Fungsi `push` bekerja dengan membuat node baru, mengarahkan pointernya ke `top` yang lama, lalu memperbarui `top` menjadi node yang baru tersebut. Fungsi `pop` bekerja dengan menggeser `top` ke node selanjutnya, lalu menghapus node yang berada di posisi `top` sebelumnya dari memori secara dinamis untuk mencegah *memory leak*. Keunggulan dari implementasi ini adalah ukuran stack dapat menyesuaikan secara otomatis selama memori komputer masih tersedia.

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push (tambah data)
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;

        cout << x << " ditambahkan ke stack\n";
    }

    // Pop (hapus data)
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " dihapus dari stack\n";
        top = top->next;
        delete temp;
    }

    // Peek (lihat data teratas)
    void peek() {
        if (top == NULL) {
            cout << "Stack kosong\n";
        } else {
            cout << "Elemen teratas: " << top->data << endl;
        }
    }

    // Cek kosong
    bool isEmpty() {
        return (top == NULL);
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}
```

**Output:**
```txt
10 ditambahkan ke stack
20 ditambahkan ke stack
30 ditambahkan ke stack
Elemen teratas: 30
30 dihapus dari stack
Elemen teratas: 20
```

---

## 3. Aplikasi Stack: Konversi Ekspresi Matematika

Salah satu penerapan utama dari struktur data Stack di dunia nyata adalah untuk **memanipulasi dan mengonversi ekspresi matematika** agar lebih mudah dievaluasi oleh komputer.

### Jenis Notasi Ekspresi
Dalam matematika dan ilmu komputer, terdapat 3 cara untuk menuliskan ekspresi:
1. **Infix:** Operator berada di tengah (di antara dua *operand*).
   * Contoh: `A + B`
2. **Prefix (*Polish Notation*):** Operator diletakkan di depan *operand*.
   * Contoh: `+ A B`
3. **Postfix (*Reverse Polish Notation*):** Operator diletakkan di belakang *operand*.
   * Contoh: `A B +`

### Mengapa Membutuhkan Konversi ke Postfix/Prefix?
Manusia terbiasa membaca notasi **Infix**. Namun, notasi ini rumit bagi komputer karena membutuhkan aturan prioritas operasi (KABATAKU: Kali, Bagi, Tambah, Kurang) dan penggunaan tanda kurung `()`. 
Dengan mengubahnya menjadi **Postfix** atau **Prefix**, komputer dapat memproses perhitungan dari kiri ke kanan secara linear tanpa perlu khawatir tentang tanda kurung atau ambiguitas urutan pengerjaan.

### Peran Stack dalam Konversi (Infix ke Postfix)
Saat mengonversi ekspresi dari Infix ke Postfix, Stack digunakan sebagai **tempat penyimpanan sementara khusus untuk operator** (`+`, `-`, `*`, `/`, dll). 

**Logika Algoritmanya:**
1. Program akan membaca ekspresi dari kiri ke kanan.
2. Jika yang dibaca adalah **Operand** (angka/huruf), langsung keluarkan menjadi *output*.
3. Jika yang dibaca adalah **Operator**, masukkan ke dalam Stack. Program akan membandingkan prioritas operator yang baru masuk dengan operator yang sudah ada di tumpukan atas (Top) Stack.
4. Operator dengan prioritas lebih tinggi akan dikeluarkan (*pop*) dari Stack menuju *output* terlebih dahulu.
5. **Contoh Hasil:** Ekspresi `A + B * C` jika dikonversi menggunakan Stack akan menjadi `A B C * +`.
