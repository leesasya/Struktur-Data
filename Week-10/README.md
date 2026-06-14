# Tugas Struktur Data - Week 10 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045  

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-10/src)

---

## 1. Rangkuman Materi

**Tree (Pohon)** adalah struktur data non-linear berbentuk hierarki yang terdiri dari himpunan *node* (simpul) dan *edge* (sisi). Struktur ini dirancang untuk mengatasi keterbatasan struktur data linear (seperti Array atau Linked List) agar penyimpanan, pencarian, dan manipulasi data berskala besar menjadi jauh lebih efisien.

**Terminologi Anatomi Dasar Tree:**
* **Root:** Node paling atas atau akar dari tree.
* **Leaf:** Node yang tidak memiliki anak (node paling bawah).
* **Parent & Child:** Node yang memiliki cabang di bawahnya disebut *Parent*, dan cabang tersebut adalah *Child*.
* **Depth:** Tingkat kedalaman suatu node dari *root*.

**Contoh Implementasi di Dunia Nyata:**
Konsep Tree digunakan secara luas dalam teknologi sehari-hari, seperti sistem direktori/file pada OS, struktur HTML DOM pada *web development*, dan pengindeksan pada basis data.

**Mekanisme Traversal (Penelusuran):**
Proses mengunjungi setiap node secara sistematis terbagi menjadi dua kategori utama:
1.  **Depth First Search (DFS):** Menelusuri data secara mendalam terlebih dahulu ke bawah. Variasinya meliputi:
    * **Preorder:** (Root, Kiri, Kanan)
    * **Inorder:** (Kiri, Root, Kanan)
    * **Postorder:** (Kiri, Kanan, Root)
2.  **Breadth First Search (BFS):** Menelusuri data secara horizontal atau melebar per level (biasa disebut **Level Order Traversal**).

---

## 2. Implementasi Tree & Traversal

**Penjelasan Kode (`tree.cpp`):**
Program ini membangun sebuah *Binary Tree* (pohon biner) sederhana secara manual menggunakan *pointer* dengan struktur hierarki sebagai berikut:
* Node `A` sebagai *root*.
* Node `B` dan `C` sebagai anak dari `A`.
* Node `D` dan `E` sebagai anak dari `B`.
* Node `F` sebagai anak kanan dari `C`.

Setelah *tree* terbentuk, program memanggil empat fungsi *traversal* yang berbeda. Fungsi `preorder`, `inorder`, dan `postorder` dibangun menggunakan teknik rekursif. Sedangkan fungsi `levelOrder` memanfaatkan struktur data pendukung berupa `queue` (antrian) untuk memproses node lapis demi lapis dari atas ke bawah.

**Kode C++:**
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

int main() {
    // Membangun Tree
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    // Menjalankan Traversal
    cout << "Preorder  : "; preorder(root);
    cout << "\nInorder   : "; inorder(root);
    cout << "\nPostorder : "; postorder(root);
    cout << "\nLevelOrder: "; levelOrder(root);

    return 0;
}
```

**Output:**
```plaintext
Preorder  : A B D E C F 
Inorder   : D B E A C F 
Postorder : D E B F C A 
LevelOrder: A B C D E F
```
