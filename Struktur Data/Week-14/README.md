# Tugas Struktur Data - Week 14 (2026)

**Nama:** Khalisya Zahra Putria Rahman  

**NRP:** 5025251045  

**Repository:** [Link Source Code]()

---

## 1. Apa itu Graf?

**Graf (Graph)** adalah struktur data non-linear yang digunakan untuk merepresentasikan hubungan keterkaitan antar objek secara bebas. Graf terdiri dari komponen-komponen utama sebagai berikut:

- **Vertex / Node (Simpul):** Titik-titik diskret yang mewakili entitas objek (contoh: kota, akun media sosial, atau router).
- **Edge / Sisi:** Garis/penghubung yang menghubungkan dua buah vertex, merepresentasikan relasi antar objek tersebut.
- **Weight / Bobot (Opsional):** Nilai numerik yang disematkan pada *edge*, biasanya merepresentasikan jarak, biaya, atau waktu tempuh.
- **Degree (Derajat):** Jumlah total *edge* yang terhubung langsung pada suatu vertex tertentu.

---

## 2. Representasi Graf dalam Kode

Terdapat dua cara utama yang paling sering digunakan untuk merepresentasikan graf ke dalam baris kode program komputer:

### A. Adjacency Matrix (Matriks Ketetanggaan)

Graf direpresentasikan sebagai matriks dua dimensi berukuran $V \times V$ (di mana $V$ adalah jumlah vertex). Nilai `1` menandakan adanya koneksi (*edge*), sedangkan nilai `0` menandakan tidak ada koneksi.

- **Kelebihan:** Akses pengecekan hubungan antar dua simpul sangat cepat, yakni berkecepatan $O(1)$.
- **Kekurangan:** Sangat boros memori ($O(V^2)$), terutama jika digunakan pada graf besar yang memiliki sedikit koneksi (*sparse graph*).

**Kode C++:**

```cpp
#include <iostream>
using namespace std;

class Graph {
private:
    int matrix[100][100];
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                matrix[i][j] = 0;
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Karena graf tidak berarah (undirected)
    }

    void display() {
        cout << "Adjacency Matrix:" << endl;
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.display();

    return 0;
}
```

**Output Terminal:**

```
Adjacency Matrix:
0 1 1 0 
1 0 0 1 
1 0 0 1 
0 1 1 0 
```

---

### B. Adjacency List (List Ketetanggaan)

Setiap vertex menyimpan daftar (list atau vector) berisi simpul-simpul lain yang terhubung langsung dengannya.

- **Kelebihan:** Hemat memori ($O(V + E)$), sangat ideal untuk graf berskala besar yang renggang (*sparse graph*).
- **Kekurangan:** Proses pengecekan koneksi antar dua simpul tertentu lebih lambat karena harus menelusuri list elemen ($O(\text{degree}(v))$).

**Kode C++:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Karena graf tidak berarah
    }

    void display() {
        cout << "Adjacency List:" << endl;
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for(int node : adj[i])
                cout << node << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.display();

    return 0;
}
```

**Output Terminal:**

```
Adjacency List:
0 -> 1 2 
1 -> 0 3 
2 -> 0 3 
3 -> 1 2 
```

---

## 3. Algoritma Traversal Graf

Traversal adalah proses terstruktur untuk mengunjungi semua simpul yang ada pada graf secara menyeluruh.

### A. DFS (Depth First Search)

DFS bekerja dengan menelusuri graf sedalam mungkin ke satu cabang anak sebelum melakukan proses mundur kembali (*backtracking*). Algoritma ini diimplementasikan menggunakan struktur data Stack atau melalui fungsi rekursi.

**Kompleksitas Waktu:** $O(V + E)$

**Kode C++:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";
        for(int u : adj[v]) {
            if(!visited[u])
                DFS(u);
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Hasil DFS (Mulai dari Node 0): ";
    g.DFS(0);
    cout << endl;

    return 0;
}
```

**Output Terminal:**

```
Hasil DFS (Mulai dari Node 0): 0 1 3 2 4 
```

---

### B. BFS (Breadth First Search)

BFS menelusuri graf secara melebar horizontal lapis demi lapis berdasarkan level kedekatan dari titik awal. Algoritma ini diimplementasikan menggunakan struktur data Queue.

**Kompleksitas Waktu:** $O(V + E)$

**Kode C++:**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for(int u : adj[v]) {
                if(!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Hasil BFS (Mulai dari Node 0): ";
    g.BFS(0);
    cout << endl;

    return 0;
}
```

**Output Terminal:**

```
Hasil BFS (Mulai dari Node 0): 0 1 2 3 4 
```

---

## 4. Shortest Path (Jalur Terpendek) & Minimum Spanning Tree

### A. Shortest Path - Algoritma Dijkstra

Digunakan untuk menghitung rute efisien dengan total bobot terkecil dari satu simpul asal ke simpul lainnya.

> **Variasi Algoritma Jalur Terpendek:** Dijkstra (bobot positif), Bellman-Ford (bisa menangani bobot negatif), dan Floyd-Warshall (menghitung seluruh pasangan simpul).

**Kode C++ (Dijkstra):**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000;
vector<pair<int,int>> graph[100]; // Pair: {tujuan, bobot}

void dijkstra(int start, int V) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Pair: {jarak, node}

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Jarak Terpendek dari Node " << start << ":" << endl;
    for(int i = 0; i < V; i++) {
        cout << "Ke Node " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 4;
    // Hubungkan node dengan bobotnya
    graph[0].push_back({1, 5});  graph[1].push_back({0, 5});
    graph[0].push_back({2, 10}); graph[2].push_back({0, 10});
    graph[1].push_back({3, 3});  graph[3].push_back({1, 3});
    graph[2].push_back({3, 1});  graph[3].push_back({2, 1});

    dijkstra(0, V);
    return 0;
}
```

**Output Terminal:**

```
Jarak Terpendek dari Node 0:
Ke Node 0 : 0
Ke Node 1 : 5
Ke Node 2 : 9
Ke Node 3 : 8
```

---

### B. Minimum Spanning Tree (MST)

MST bertujuan untuk menghubungkan seluruh vertex dalam graf dengan total nilai bobot se-minimum mungkin tanpa menghasilkan putaran tertutup (*cycle*). Operasi ini biasanya diselesaikan memakai **Algoritma Prim** atau **Algoritma Kruskal** pada perancangan infrastruktur fisik (seperti penarikan jalur kabel fiber optik atau listrik antar kota).

---

## 5. Komparasi Komprehensif: Tree vs Graf

| Aspek Karakteristik | Tree (Pohon) | Graph (Graf) |
|       ---           |     ---      |      ---     |
| Simpul Utama (Root) | Selalu memiliki 1 root asal | Tidak ada struktur root wajib |
| Siklus (Cycle) | Tidak diperbolehkan ada | Bisa ada lintasan tertutup (cyclic) |
| Pola Relasi | Bersifat hierarki (Parent-Child) | Bersifat bebas / interkoneksi |
| Metode Traversal | DFS / BFS (In, Pre, Post, Level Order) | DFS / BFS (Memerlukan penanda visited) |
| Aplikasi Nyata | File System Direktori, HTML DOM | Peta Digital, Routing Jaringan, Social Media |