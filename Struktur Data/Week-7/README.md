# Tugas Struktur Data - Week 7 (2026)

**Nama:** Khalisya Zahra Putria Rahman

**NRP:** 5025251045

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-7)

Queue adalah struktur data abstrak (ADT) linear yang beroperasi dengan prinsip **FIFO (First-In, First-Out)** atau *masuk pertama, keluar pertama*. Berbeda dengan Stack yang hanya memiliki satu ujung akses, Queue memiliki dua ujung:
1. **Rear (Belakang):** Titik di mana elemen baru dimasukkan.
2. **Front (Depan):** Titik di mana elemen lama dihapus/dikeluarkan.

Konsep ini sangat relevan dengan kehidupan sehari-hari dan sistem komputer, seperti:
* Antrian pengunjung bioskop atau nasabah bank.
* Kendaraan di jalan satu arah dengan satu jalur.
* *Printer queue* (antrian dokumen yang akan dicetak).
* *Task scheduling* pada Sistem Operasi.

---

## 1. Operasi Utama dan Algoritma

Queue memiliki dua operasi fundamental, yaitu **Enqueue** (menambahkan data) dan **Dequeue** (menghapus data).

### A. Enqueue (Tambah Data)
Proses menambahkan elemen baru pada posisi *rear*. Jika menggunakan array dengan batasan tetap, kita harus mengecek apakah antrian sudah penuh (*Overflow*).

**Algoritma:**
```text
ALGORITHM Enqueue(Q, item)
INPUT    : Q (queue), item (elemen yang akan dimasukkan)
OUTPUT   : Queue Q yang telah ditambahkan elemen baru

BEGIN
    IF rear = MAX - 1 THEN
        OUTPUT "Queue Overflow"
        RETURN
    ENDIF

    IF front = -1 THEN
        front ← 0
        rear  ← 0
    ELSE
        rear ← rear + 1
    ENDIF

    Q[rear] ← item
END
```

### B. Dequeue (Hapus Data)
Proses mengeluarkan elemen dari posisi front. Sebelum menghapus, sistem harus memastikan bahwa antrian tidak dalam keadaan kosong (Underflow).

**Algoritma:**
```text
ALGORITHM Dequeue(Q)
INPUT    : Q (queue)
OUTPUT   : Elemen yang dihapus dari queue

BEGIN
    IF front = -1 THEN
        OUTPUT "Queue Underflow"
        RETURN
    ENDIF

    item ← Q[front]

    IF front = rear THEN
        front ← -1
        rear  ← -1
    ELSE
        front ← front + 1
    ENDIF

    RETURN item
END
```

## 2. Implementasi Queue Menggunakan Array (Statis)

**Penjelasan Kode:**

Implementasi ini menggunakan array dengan batas maksimum yang sudah ditetapkan (MAX 5). Indikator front dan rear diinisialisasi dengan -1 untuk menandakan antrian kosong. Kekurangan dari pendekatan statis ini adalah memori yang dialokasikan tidak bisa berubah-ubah, dan ruang array di bagian depan tidak dapat digunakan kembali setelah elemen di-dequeue (kecuali diubah menjadi Circular Queue).

```cpp
#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    // Menambah data
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = x;
        cout << "Elemen " << x << " masuk ke queue\n";
    }

    // Menghapus data
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Elemen " << arr[front] << " keluar dari queue\n";
        if (front == rear) {
            front = rear = -1; // Reset jika antrian kembali kosong
        } else {
            front++;
        }
    }

    // Menampilkan isi antrian
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }
        cout << "Isi Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
```

**Output:**
```plaintext
Elemen 10 masuk ke queue
Elemen 20 masuk ke queue
Elemen 30 masuk ke queue
Isi Queue: 10 20 30
Elemen 10 keluar dari queue
Isi Queue: 20 30
```

## 3. Implementasi Queue Menggunakan Linked List (Dinamis)

**Penjelasan Kode:**

Untuk mengatasi keterbatasan kapasitas array, Queue dapat diimplementasikan menggunakan Linked List. Setiap elemen disimpan sebagai Node yang saling terhubung. Pointer front menunjuk ke simpul pertama yang akan keluar, dan pointer rear menunjuk ke simpul terakhir yang baru masuk. Keunggulan dari metode ini adalah ukuran antrian dapat bertambah atau berkurang secara dinamis sesuai memori yang tersedia tanpa batasan kapasitas maksimal.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // Menambah data di posisi rear
    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Elemen " << x << " masuk ke queue\n";
    }

    // Menghapus data di posisi front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Elemen " << temp->data << " keluar dari queue\n";

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp; // Membebaskan memori
    }

    // Menampilkan isi antrian
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Isi Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
```

**Output:**
```plaintext
Elemen 5 masuk ke queue
Elemen 15 masuk ke queue
Elemen 25 masuk ke queue
Isi Queue: 5 15 25
Elemen 5 keluar dari queue
Isi Queue: 15 25
