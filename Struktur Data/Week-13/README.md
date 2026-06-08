# Tugas Struktur Data - Week 13 (Binary Search Tree)

**Nama:** Khalisya Zahra Putria Rahman  
**NRP:** 5025251045  
**Repository:** [Link Source Code]()

---

## 1. Mengapa Kita Membutuhkan Tree?

Struktur data linear seperti Array atau Linked List memiliki keterbatasan besar dalam pencarian data berskala besar, di mana operasi pencarian harus dilakukan satu per satu dari awal hingga akhir dengan kompleksitas waktu **O(n)**. 

**Tree** hadir sebagai solusi non-linear hierarkis untuk memecahkan batasan tersebut. Di dunia nyata, Tree diimplementasikan secara luas pada:
* **Computer Folder System:** Struktur direktori penyimpanan berkas sistem operasi.
* **Database Indexing:** Mempercepat eksekusi query pencarian data.
* **AI Decision Tree:** Pemodelan pengambilan keputusan berbasis kondisi.
* **Search Engine Indexing:** Penyimpanan kata kunci mesin pencari secara efisien.

### Anatomi dan Evolusi Tree
* **Root:** Node pertama paling atas (pondasi tree).
* **Parent & Child:** Hubungan relasional antar-node di mana node atas (*parent*) menunjuk ke cabang di bawahnya (*child*).
* **Leaf:** Node paling ujung/bawah yang tidak memiliki anak lagi.
* **Height:** Jumlah tingkat/level maksimum dari *root* hingga *leaf* terbawah.

**Binary Tree** menyempurnakan konsep ini dengan membatasi jumlah anak maksimum bagi setiap node parent sebanyak **dua anak saja** (*left child* dan *right child*). Sementara **Binary Search Tree (BST)** menambahkan aturan emas pengurutan nilai yang ketat di atas struktur biner tersebut.

---

## 2. Aturan Emas dan Kompleksitas Waktu BST

Sebuah Binary Tree dinyatakan sebagai **Binary Search Tree (BST)** jika dan hanya jika mematuhi hukum absolut berikut secara rekursif di setiap tingkat node:

> **Semua nilai di Subtree Kiri < Nilai Node Saat Ini < Semua nilai di Subtree Kanan**

### Tabel Kompleksitas Waktu BST
| Operasi | Rata-rata (Tree Seimbang) | Terburuk (Tree Tidak Seimbang) |
| :--- | :---: | :---: |
| **Search** | O(log n) | O(n) |
| **Insert** | O(log n) | O(n) |
| **Delete** | O(log n) | O(n) |

> ⚠️ **Kutukan Degradasi Linear:** Jika data dimasukkan secara berurutan (misal: 10, 20, 30, 40), struktur BST akan mengalami *degradasi* memanjang menjadi Linked List biasa (*Skewed Tree*). Akibatnya, efisiensi waktu performa optimal runtuh dari **O(log n)** menjadi **O(n)**.

---

## 3. Tiga Pilar Operasi Utama BST

### A. Insert (Penyisipan Data)
Operasi penyisipan secara rekursif membandingkan nilai baru dengan node saat ini. Jika nilai lebih kecil, gerbang algoritma belok ke kiri. Jika lebih besar, belok ke kanan hingga menemukan posisi kosong (*leaf*) untuk membentuk node baru.

* **Alur Simulasi Input Acak:** `65, 25, 85, 5, 35, 75, 95`
```text
      65
   /       \
  25       85
 /  \     /  \
5   35   75  95
```

### B. Search (Pencarian Data)
Navigasi pencarian bekerja satu arah dengan mengeliminasi setengah sisa kemungkinan data di setiap langkah penurunan level (*binary elimination*).

* *Contoh mencari nilai 75*: Mulai di 65 (75 > 65 → Kanan) → Tiba di 85 (75 < 85 → Kiri) → Tiba di 75 (75 == 75 → Ditemukan dalam 3 langkah).

### C. Delete (Penghapusan Data)
Operasi penghapusan terbagi menjadi 3 skenario reorganisasi struktur:
* **Node adalah Leaf (0 anak)**: Hapus node secara langsung.
* **Node memiliki 1 anak**: Cabut node target, sambungkan anaknya langsung ke induk atas (*grandparent*).
* **Node memiliki 2 anak**: Ganti node dengan *Inorder Successor* (nilai terkecil di subtree kanan) atau *Inorder Predecessor* (nilai terbesar di subtree kiri), kemudian lakukan pertukaran (*swap*) nilai sebelum dihapus.

## 4. Implementasi Dasar BST di C++

Program ini mengimplementasikan struktur dasar BST menggunakan struct Node. Kode ini mencakup fungsi pembuatan node baru (`createNode`), fungsi penyisipan rekursif (`insert`), fungsi pencarian (`search`), serta penelusuran terurut (`inorder`).

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi insert (rekursif)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Fungsi pencarian data (rekursif)
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Fungsi inorder traversal (Kiri -> Root -> Kanan)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 60;
    if (search(root, key)) {
        cout << "Data " << key << " ditemukan" << endl;
    } else {
        cout << "Data " << key << " tidak ditemukan" << endl;
    }

    return 0;
}
```

**Output**:
```txt
Inorder Traversal: 20 30 40 50 60 70 80 
Data 60 ditemukan
```

*Mekanisme Output Hasil Traversal Tree di Atas:*
- Inorder (Kiri → Root → Kanan): `20 30 40 50 60 70 80` (*Menghasilkan data urut menaik/ascending*)
- Preorder (Root → Kiri → Kanan): `50 30 20 40 70 60 80` (*Berguna untuk kloning/copy struktur tree*)
- Postorder (Kiri → Kanan → Root): `20 40 30 60 80 70 50` (*Berguna untuk operasi pembersihan/delete memori tree*)


## 5. Studi Kasus: Sistem Ranking Game Online

Studi kasus ini mensimulasikan sistem papan peringkat (*leaderboard*) game online yang menyimpan skor pemain menggunakan BST. Untuk menampilkan peringkat dari nilai tertinggi ke terendah, mekanisme traversal dimodifikasi menjadi urutan terbalik (*descending*) dengan pola urutan kunjungan: **Kanan → Root → Kiri**.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int score;
    Node* left;
    Node* right;
};

Node* createNode(int score) {
    Node* newNode = new Node();
    newNode->score = score;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int score) {
    if (root == NULL) return createNode(score);
    if (score < root->score)
        root->left = insert(root->left, score);
    else if (score > root->score)
        root->right = insert(root->right, score);
    return root;
}

// Traversal descending: Kanan → Root → Kiri
void descending(Node* root) {
    if (root != NULL) {
        descending(root->right);
        cout << root->score << endl;
        descending(root->left);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 500);
    root = insert(root, 300);
    root = insert(root, 700);
    root = insert(root, 200);
    root = insert(root, 400);
    root = insert(root, 600);
    root = insert(root, 800);

    cout << "Ranking Player:" << endl;
    descending(root);

    return 0;
}
```

**Output:**
```txt
Ranking Player:
800
700
600
500
400
300
200
```

### 6. Solusi Evolusi: Self-Balancing BST

Untuk mencegah terjadinya kutukan degradasi linear (*Skewed Tree*), dikembangkan arsitektur pohon modern yang mampu menyeimbangkan dirinya secara otomatis (*Self-Balancing BST*) melalui operasi rotasi internal, di antaranya:

1. **AVL Tree:** Menggunakan faktor penyeimbang berbasis perbedaan tinggi maksimum node (`height`) secara ketat untuk mempertahankan keseimbangan absolut.

2. **Red-Black Tree:** Menggunakan sistem pewarnaan node (merah/hitam) untuk toleransi penyeimbangan yang lebih fleksibel. Struktur ini menjadi basis optimasi internal pada Library Standar C++ STL seperti `std::map` dan `std::set`.