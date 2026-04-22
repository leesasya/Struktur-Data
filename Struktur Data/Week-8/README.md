# Tugas Struktur Data - Week 8 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-8)

Repositori ini berisi penjelasan teori mengenai **Node Linked List** beserta implementasi program C++ dari operasi-operasi dasarnya, mulai dari inisialisasi, penyisipan (*insertion*), penghapusan (*deletion*), pencarian (*searching*), hingga pembaruan data (*updating*).

---

## Konsep Dasar Node Linked List

Berbeda dengan Array yang menyimpan data secara berurutan dalam satu blok memori (*contiguous*), **Linked List** menyimpan datanya secara tersebar di berbagai lokasi memori. Setiap elemen dalam Linked List disebut sebagai **Node**.

Agar tidak terpencar dan hilang, setiap Node memiliki 2 bagian utama:
1. **Data:** Tempat untuk menyimpan nilai/informasi (misalnya angka, huruf, dll).
2. **Pointer (`next`):** Sebuah variabel penunjuk yang menyimpan *alamat memori* dari Node selanjutnya. 

Pointer inilah yang merangkai Node-Node yang tersebar menjadi sebuah rantai. Node pertama disebut **Head**, dan pointer pada Node terakhir akan selalu menunjuk ke **`NULL`** sebagai tanda bahwa rantai/list telah berakhir.

---

## 1. Operasi Pembuatan Node & Traversal

**Penjelasan Kode 1:**
Program ini mendemonstrasikan cara membuat 3 buah Node secara dinamis. Masing-masing Node diisi dengan data (10, 20, 30), lalu pointer `next` dari node pertama diarahkan ke node kedua, dan seterusnya hingga node terakhir menunjuk ke `NULL`. Setelah rantai terbentuk, program melakukan *traversal* (penelusuran) menggunakan perulangan `while` dari *Head* hingga ke ujung `NULL` untuk mencetak seluruh nilainya.

**Kode C++:**
```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

int main() {
    // 1. Membuat 3 node secara dinamis
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // 2. Mengisi data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // 3. Menghubungkan pointer membentuk rantai
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traversal: Mencetak isi Linked List
    Node* current = head;
    cout << "Isi Linked List: ";
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";

    return 0;
}
```

**Output:**
```plaintext
Isi Linked List: 10 -> 20 -> 30 -> NULL
```

## 2. Operasi Insertion (Menyisipkan Node di Awal)
**Penjelasan Kode 2:**
Pada operasi ini, kita ingin menambahkan data baru (`5`) tepat di paling depan (sebelum _Head_ lama). Program akan membuat sebuah Node baru, mengisi datanya, lalu mengarahkan pointer `next` dari Node baru tersebut ke _Head_ yang lama. Setelah saling terkait, status _Head_ resmi dipindahkan ke Node yang baru tersebut.

**Kode C++:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Setup list awal: 20 -> 30 -> NULL
    Node* head = new Node();
    head->data = 20;
    head->next = new Node();
    head->next->data = 30;
    head->next->next = NULL;

    // --- Short Code: Insertion di Awal ---
    Node* newNode = new Node();
    newNode->data = 5;
    newNode->next = head;
    head = newNode; // Pindah status head ke node baru

    // Traversal untuk melihat hasil
    Node* current = head;
    cout << "Setelah Insertion: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
```

**Output:**
```plaintext
Setelah Insertion: 5 20 30
```

## 3. Operasi Deletion (Menghapus Node di Awal)
**Penjelasan Kode 3:**
Operasi ini bertugas untuk menghapus Node pertama (_Head_). Kita tidak boleh langsung menghapusnya, karena alamat node kedua akan ikut hilang. Triknya adalah menyimpan alamat _Head_ ke dalam pointer sementara bernama `temp`. Kemudian, geser posisi _Head_ ke node selanjutnya (`head = head->next`). Setelah rantai aman, barulah memori pada `temp` dihapus menggunakan perintah `delete`.

**Kode C++:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Setup list awal: 10 -> 20 -> 30 -> NULL
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // --- Short Code: Deletion di Awal ---
    Node* temp = head;
    head = head->next; // Geser head ke node kedua
    delete temp;       // Hapus node pertama dari memori

    // Traversal untuk melihat hasil
    Node* current = head;
    cout << "Setelah Deletion: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
```

**Output:**

```plaintext
Setelah Deletion: 20 30
```

## 4. Operasi Searching (Pencarian Data)
**Penjelasan Kode 4:**
Program ini digunakan untuk mencari apakah suatu nilai kunci (_key_) ada di dalam Linked List. Konsepnya sama seperti traversal, program akan merayap dari satu Node ke Node lain. Di setiap pemberhentian, program menggunakan fungsi `if` untuk mengecek apakah `data` di dalam Node sama dengan `key` (dalam kasus ini `20`). Jika cocok, pencarian dihentikan.

**Kode C++:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Setup list awal: 10 -> 20 -> 30 -> NULL
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = NULL;

    int key = 20;
    bool found = false;

    // --- Short Code: Searching ---
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Pencarian: Data " << key << " ditemukan!\n";
            found = true;
            break; 
        }
        current = current->next;
    }

    if (!found) cout << "Pencarian: Data tidak ditemukan.\n";

    return 0;
}
```

**Output:**

```plaintext
Pencarian: Data 20 ditemukan!
```

## 5. Operasi Updating (Pembaruan Data)
**Penjelasan Kode 5:**
Mirip dengan proses pencarian, program ini menelusuri Linked List untuk mencari nilai tertentu yang sudah usang (misalnya angka `10`). Ketika Node dengan nilai tersebut ditemukan, nilai datanya akan langsung ditimpa (di-_update_) dengan nilai yang baru (misalnya `100`). Setelah diubah, program akan melanjutkan atau menyelesaikan perulangan.

**Kode C++:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Setup list awal: 10 -> 20 -> 30 -> NULL
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // --- Short Code: Updating ---
    Node* current = head;
    while (current != NULL) {
        if (current->data == 10) { 
            current->data = 100; // Timpa nilai 10 menjadi 100
        }
        current = current->next;
    }

    // Traversal untuk melihat hasil
    current = head;
    cout << "Setelah Updating: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
```

**Output:**
```plaintext
Setelah Updating: 100 20 30
```