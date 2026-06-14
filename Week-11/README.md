# Tugas Struktur Data - Week 11 (2026)

**Nama:** Khalisya Zahra Putria Rahman  

**NRP:** 5025251045  

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-11/src)

---

## 1. Apa itu General Tree?

**General Tree** adalah struktur data pohon di mana setiap *node* (simpul) dapat memiliki jumlah *child* (anak) yang tidak terbatas. Berbeda dengan *Binary Tree* yang dibatasi maksimal 2 anak, General Tree jauh lebih fleksibel.

Dalam konteks sistem komputer, setiap folder dapat memiliki banyak subfolder di dalamnya, dan subfolder tersebut dapat memiliki subfolder lagi. Karakteristik inilah yang membuat General Tree sangat cocok digunakan untuk membangun struktur *file system*.

### Struktur Data Node
Setiap entitas folder direpresentasikan menggunakan sebuah `class Node` yang berisi:
* `name`: Menyimpan nama folder (tipe `string`).
* `parent`: *Pointer* yang menunjuk ke folder induk (di atasnya).
* `children`: Sebuah `vector` yang menyimpan daftar *pointer* ke semua folder anak di bawahnya.

---

## 2. Fitur-Fitur Utama Program

Program ini dilengkapi dengan berbagai operasi untuk memanipulasi dan membaca struktur pohon hierarki folder. Berikut adalah ringkasan fungsinya:

| Fungsi | Penjelasan Output & Kegunaan |
|  ---   |              ---             |
| `addFolder` | Menambahkan folder baru ke dalam suatu folder *parent* dan menampilkan pesan konfirmasi. |
| `printTree` | Menampilkan struktur hierarki folder secara visual menggunakan indentasi dan garis penghubung. |
| `preorder` | Menelusuri dan mencetak nama folder dengan urutan: *Root* -> *Child* (dari atas ke bawah). |
| `postorder` | Menelusuri dan mencetak nama folder dengan urutan: *Child* -> *Root* (dari bawah ke atas). |
| `search` | Mencari folder menggunakan algoritma *Depth-First Search* (DFS). Mengembalikan *pointer* folder jika ditemukan, atau `NULL` jika tidak ada. |
| `showPath` | Menampilkan *path* lengkap direktori dari *Root* sampai ke folder yang dicari (contoh: `Root/Documents/Tugas`). |
| `countFolder`| Menghitung dan menampilkan jumlah total folder yang ada di dalam struktur *tree*. |
| `deleteFolder`| Menghapus sebuah folder beserta **seluruh subfolder di dalamnya** secara dinamis, lalu memperbarui hubungan dengan *parent*-nya. |

---

## 3. Implementasi Kode Lengkap (C++)

Berikut adalah penggabungan seluruh operasi di atas menjadi sebuah program utuh yang mensimulasikan pembuatan, penelusuran, pencarian, hingga penghapusan direktori folder.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur Node Folder
class Node {
public:
    string name;
    Node* parent;
    vector<Node*> children;
    
    Node(string folderName, Node* p = NULL) {
        name = folderName;
        parent = p;
    }
};

// Class untuk mengelola General Tree
class FileSystemTree {
private:
    Node* root;

    // Fungsi helper untuk menghapus subtree dari memori
    void deleteSubtree(Node* node) {
        if (node == NULL) return;
        for (Node* child : node->children) {
            deleteSubtree(child);
        }
        delete node;
    }

public:
    FileSystemTree(string rootName) {
        root = new Node(rootName);
    }

    Node* getRoot() { return root; }

    // 1. Menambah Folder
    void addFolder(Node* parent, string folderName) {
        if (parent == NULL) return;
        Node* newFolder = new Node(folderName, parent);
        parent->children.push_back(newFolder);
        cout << "Folder '" << folderName << "' berhasil ditambahkan ke '" << parent->name << "'\n";
    }

    // 2. Menampilkan Struktur Folder
    void printTree(Node* node, int level = 0) {
        if (node == NULL) return;
        for (int i = 0; i < level; i++) cout << "│  ";
        if (level > 0) cout << "├── ";
        cout << node->name << endl;
        for (Node* child : node->children) {
            printTree(child, level + 1);
        }
    }

    // 3. Pencarian Folder (DFS)
    Node* search(Node* node, string target) {
        if (node == NULL) return NULL;
        if (node->name == target) return node;
        for (Node* child : node->children) {
            Node* result = search(child, target);
            if (result != NULL) return result;
        }
        return NULL;
    }

    // 4. Preorder Traversal
    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->name << endl;
        for (Node* child : node->children) {
            preorder(child);
        }
    }

    // 5. Postorder Traversal
    void postorder(Node* node) {
        if (node == NULL) return;
        for (Node* child : node->children) {
            postorder(child);
        }
        cout << node->name << endl;
    }

    // 6. Menampilkan Path
    void showPath(Node* node) {
        if (node == NULL) return;
        vector<string> path;
        Node* current = node;
        while (current != NULL) {
            path.push_back(current->name);
            current = current->parent;
        }
        cout << "Path : ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << "/";
        }
        cout << endl;
    }

    // 7. Menghitung Jumlah Folder
    int countFolder(Node* node) {
        if (node == NULL) return 0;
        int total = 1;
        for (Node* child : node->children) {
            total += countFolder(child);
        }
        return total;
    }

    // 8. Menghapus Folder
    void deleteFolder(string folderName) {
        Node* target = search(root, folderName);
        if (target == NULL) {
            cout << "Folder tidak ditemukan!\n";
            return;
        }
        if (target == root) {
            cout << "Root tidak dapat dihapus!\n";
            return;
        }
        
        Node* parent = target->parent;
        for (auto it = parent->children.begin(); it != parent->children.end(); it++) {
            if (*it == target) {
                parent->children.erase(it);
                break;
            }
        }
        deleteSubtree(target);
        cout << "Folder berhasil dihapus!\n";
    }
};

int main() {
    FileSystemTree tree("Root");
    Node* root = tree.getRoot();

    // Setup Awal
    tree.addFolder(root, "Documents");
    tree.addFolder(root, "Pictures");
    tree.addFolder(root, "Music");

    Node* documents = tree.search(root, "Documents");
    tree.addFolder(documents, "Kuliah");
    tree.addFolder(documents, "Tugas");

    cout << "\n===== STRUKTUR FOLDER =====\n";
    tree.printTree(root);

    cout << "\n===== PREORDER TRAVERSAL =====\n";
    tree.preorder(root);

    cout << "\n===== POSTORDER TRAVERSAL =====\n";
    tree.postorder(root);

    cout << "\n===== SEARCH FOLDER =====\n";
    Node* result = tree.search(root, "Tugas");
    if(result) {
        cout << "Folder ditemukan : " << result->name << endl;
        tree.showPath(result);
    }

    cout << "\n===== JUMLAH FOLDER =====\n";
    cout << "Total Folder : " << tree.countFolder(root) << endl;

    cout << "\n===== HAPUS FOLDER =====\n";
    tree.deleteFolder("Pictures");

    cout << "\n===== STRUKTUR SETELAH DELETE =====\n";
    tree.printTree(root);

    return 0;
}
```

**Output:**
```txt
Folder 'Documents' berhasil ditambahkan ke 'Root'
Folder 'Pictures' berhasil ditambahkan ke 'Root'
Folder 'Music' berhasil ditambahkan ke 'Root'
Folder 'Kuliah' berhasil ditambahkan ke 'Documents'
Folder 'Tugas' berhasil ditambahkan ke 'Documents'

===== STRUKTUR FOLDER =====
Root
├── Documents
│  ├── Kuliah
│  ├── Tugas
├── Pictures
├── Music

===== PREORDER TRAVERSAL =====
Root
Documents
Kuliah
Tugas
Pictures
Music

===== POSTORDER TRAVERSAL =====
Kuliah
Tugas
Documents
Pictures
Music
Root

===== SEARCH FOLDER =====
Folder ditemukan : Tugas
Path : Root/Documents/Tugas

===== JUMLAH FOLDER =====
Total Folder : 6

===== HAPUS FOLDER =====
Folder berhasil dihapus!

===== STRUKTUR SETELAH DELETE =====
Root
├── Documents
│  ├── Kuliah
│  ├── Tugas
├── Music
```
