# Tugas Struktur Data - Week 12 (2026)

**Nama:** Khalisya Zahra Putria Rahman  

**NRP:** 5025251045  

**Repository:** [Link Source Code]()

---

## 1. Binary Search Tree (BST)

**Binary Search Tree (BST)** adalah struktur data *binary tree* (pohon biner di mana maksimal memiliki 2 *child*) yang memiliki aturan khusus pada penempatan nilainya:
* Nilai pada *subtree* kiri **lebih kecil** dari nilai *root* (induk).
* Nilai pada *subtree* kanan **lebih besar** dari nilai *root*.

**Kelebihan & Kekurangan BST:**
* ✅ Pencarian (*Searching*) sangat cepat.
* ✅ Proses *Insert* mudah dan data otomatis terurut.
* ❌ Bisa menjadi tidak seimbang (*unbalanced*) jika data yang dimasukkan sudah berurutan.
* ❌ Pada *worst case* (pohon condong ke satu sisi), kompleksitas waktunya menjadi `O(n)`.

### Implementasi BST (C++)

Program berikut mendemonstrasikan proses *insert* data ke dalam BST, penelusuran (*inorder*, *preorder*, *postorder*), dan pencarian (*search*) sebuah nilai.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    
    if(key < root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;

    // Insert data
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversal
    cout << "Inorder   : "; inorder(root);
    cout << "\nPreorder  : "; preorder(root);
    cout << "\nPostorder : "; postorder(root);

    // Search
    cout << "\n\nSearch 60 : ";
    if(search(root, 60)){
        cout << "Ditemukan\n";
    }else{
        cout << "Tidak ditemukan\n";
    }

    return 0;
}
```

**Output:**
```txt
Inorder   : 20 30 40 50 60 70 80 
Preorder  : 50 30 20 40 70 60 80 
Postorder : 20 40 30 60 80 70 50 

Search 60 : Ditemukan
```

## 2. B-Tree

**B-Tree** adalah struktur data *self-balancing multiway search tree* yang dirancang khusus untuk menyimpan data dalam jumlah besar secara efisien. B-Tree memiliki anak (*child*) lebih dari dua, dan sering digunakan dalam sistem yang memanipulasi bongkahan data besar.

**Aturan Utama B-Tree (Misal order = m):**
* Maksimal *child* per node = `m`
* Maksimal *key* per node = `m - 1`
* Semua *leaf* (daun) berada pada level yang sama (selalu seimbang).
* *Key* di dalam setiap node selalu terurut.
* Jika suatu node penuh saat di-*insert*, node tersebut akan mengalami proses **Split** (pecah), dan nilai tengahnya akan naik ke *parent*.

**Penggunaan & Kelebihan B-Tree:**
* Digunakan pada: Database (seperti *MySQL Index*, *PostgreSQL*), *File System*, dan *Search Engine*.
* Tinggi *tree* rendah sehingga akses memori/disk (*disk access*) sangat minim.
* Pencarian sangat cepat dengan kompleksitas `O(log n)`.

### Implementasi B-Tree (C++)

Program ini mendemonstrasikan B-Tree dengan nilai minimum degree `t = 3` (sehingga setiap node dapat menampung maksimal 5 *key*).

```cpp
#include <bits/stdc++.h>
using namespace std;

class BTreeNode{
public:
    int* keys;
    int t;
    BTreeNode** child;
    int n;
    bool leaf;

    BTreeNode(int _t, bool _leaf){
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        child = new BTreeNode*[2 * t];
        n = 0;
    }

    void traverse(){
        int i;
        for(i = 0; i < n; i++){
            if(leaf == false){
                child[i]->traverse();
            }
            cout << keys[i] << " ";
        }
        if(leaf == false){
            child[i]->traverse();
        }
    }

    BTreeNode* search(int k){
        int i = 0;
        while(i < n && k > keys[i]){
            i++;
        }
        if(keys[i] == k) return this;
        if(leaf == true) return NULL;
        return child[i]->search(k);
    }

    void insertNonFull(int k){
        int i = n - 1;
        if(leaf == true){
            while(i >= 0 && keys[i] > k){
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n = n + 1;
        }else{
            while(i >= 0 && keys[i] > k){
                i--;
            }
            if(child[i + 1]->n == 2 * t - 1){
                splitChild(i + 1, child[i + 1]);
                if(keys[i + 1] < k){
                    i++;
                }
            }
            child[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* y){
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;
        for(int j = 0; j < t - 1; j++){
            z->keys[j] = y->keys[j + t];
        }
        if(y->leaf == false){
            for(int j = 0; j < t; j++){
                z->child[j] = y->child[j + t];
            }
        }
        y->n = t - 1;
        for(int j = n; j >= i + 1; j--){
            child[j + 1] = child[j];
        }
        child[i + 1] = z;
        for(int j = n - 1; j >= i; j--){
            keys[j + 1] = keys[j];
        }
        keys[i] = y->keys[t - 1];
        n = n + 1;
    }
};

class BTree{
public:
    BTreeNode* root;
    int t;

    BTree(int _t){
        root = NULL;
        t = _t;
    }

    void traverse(){
        if(root != NULL){
            root->traverse();
        }
    }

    BTreeNode* search(int k){
        if(root == NULL) return NULL;
        else return root->search(k);
    }

    void insert(int k){
        if(root == NULL){
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }else{
            if(root->n == 2 * t - 1){
                BTreeNode* s = new BTreeNode(t, false);
                s->child[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if(s->keys[0] < k){
                    i++;
                }
                s->child[i]->insertNonFull(k);
                root = s;
            }else{
                root->insertNonFull(k);
            }
        }
    }
};

int main(){
    BTree t(3); // Minimum degree t = 3

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal B-Tree : ";
    t.traverse();
    cout << "\n\n";

    int x = 12;
    if(t.search(x) != NULL){
        cout << x << " ditemukan\n";
    }else{
        cout << x << " tidak ditemukan\n";
    }

    return 0;
}
```

**Output:**
```txt
Traversal B-Tree : 5 6 7 10 12 17 20 30 

12 ditemukan
```