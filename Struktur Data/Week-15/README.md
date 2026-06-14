# Tugas Struktur Data - Week 15 (2026)

**Nama:** Khalisya Zahra Putria Rahman  

**NRP:** 5025251045  

**Repository:** [Link Source Code](https://github.com/leesasya/Struktur-Data/tree/main/Struktur%20Data/Week-15/src)

---

## 1. Rangkuman Materi: Algoritma Dijkstra

Berdasarkan materi pada blog, **Algoritma Dijkstra** adalah algoritma pencarian jalur terpendek (*shortest path*) yang ditemukan oleh Edsger W. Dijkstra pada tahun 1956 (dipublikasikan 1959). Algoritma ini menggunakan pendekatan **Greedy** untuk mencari jalur dengan total bobot minimum dari satu titik asal (*single source*) ke titik tujuan atau seluruh simpul lain dalam sebuah graf.

**Karakteristik Utama:**

- Bekerja sangat optimal pada graf berbobot (*weighted graph*).
- Hanya dapat menangani graf dengan **bobot bernilai positif** (tidak cocok untuk graf dengan bobot negatif).
- Banyak diimplementasikan pada pemecahan masalah dunia nyata seperti sistem navigasi rute, pemetaan jaringan, dan logistik.

---

## 2. Laporan Implementasi: Studi Kasus Food Delivery

Berikut adalah laporan implementasi Algoritma Dijkstra untuk menyelesaikan studi kasus pengiriman makanan berdasarkan representasi graf jaringan jalan.

### A. Judul

Implementasi Algoritma Dijkstra untuk Menentukan Rute Pengiriman Makanan Tercepat pada Sistem Food Delivery Menggunakan Bahasa C++.

---

### B. Latar Belakang & Rumusan Masalah

Layanan *Food Delivery* membutuhkan sistem yang mampu menentukan rute tercepat dari restoran menuju pelanggan. Pemilihan rute yang tidak optimal dapat menyebabkan keterlambatan, meningkatnya biaya operasional, dan menurunnya kepuasan pelanggan.

**Masalah:** Bagaimana menentukan rute tercepat dari Restoran (R) menuju Pelanggan (P) berdasarkan waktu tempuh minimum menggunakan Algoritma Dijkstra?

---

### C. Data Lokasi dan Bobot Waktu Tempuh

Graf direpresentasikan dengan 7 titik lokasi (Vertex) dan 11 jalur (Edge):

- **Lokasi (Vertex):** `R` (Restoran), `A`, `B`, `C`, `D`, `E` (Perempatan), dan `P` (Pelanggan).
- **Bobot Waktu Tempuh (Menit):**
  - R → A (4) | R → B (2) | R → C (7)
  - A → B (3) | A → E (6)
  - B → C (3) | B → D (2) | B → E (3)
  - C → D (4)
  - D → P (3)
  - E → P (4)

---

### D. Implementasi Program C++

Program ini diimplementasikan menggunakan struktur data `priority_queue` agar proses antrean pencarian bobot minimum berjalan lebih optimal.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int main() {
    // 1. Inisialisasi Lokasi
    vector<string> lokasi = {
        "Restoran", "A", "B", "C", "D", "E", "Pelanggan"
    };
    int n = 7;
    vector<pair<int,int>> graph[7];

    // 2. Fungsi lambda untuk menambah edge (Graf Tak Berarah)
    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v,w}); 
        graph[v].push_back({u,w}); 
    };

    // 3. Memasukkan data bobot
    addEdge(0,1,4); addEdge(0,2,2); addEdge(0,3,7); 
    addEdge(1,2,3); addEdge(1,5,6); addEdge(2,3,3); 
    addEdge(2,4,2); addEdge(2,5,3); addEdge(3,4,4); 
    addEdge(4,6,3); addEdge(5,6,4);

    // 4. Setup Dijkstra
    vector<int> dist(n, INF); 
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 0; // Restoran
    int goal = 6;  // Pelanggan
    
    dist[start] = 0;
    pq.push({0, start});

    // 5. Proses Pencarian Jalur
    while(!pq.empty()) {
        int d = pq.top().first; 
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; 
                parent[v] = u;
                pq.push({dist[v], v}); 
            } 
        } 
    }

    // 6. Menyusun Rute Balik
    vector<int> path;
    for(int v = goal; v != -1; v = parent[v]) {
        path.push_back(v); 
    }
    reverse(path.begin(), path.end());

    // 7. Output Hasil
    cout << "===== FOOD DELIVERY =====\n";
    cout << "Rute Tercepat :\n";
    for(int i = 0; i < path.size(); i++) {
        cout << lokasi[path[i]];
        if(i < path.size() - 1) cout << " -> "; 
    }
    cout << "\n\n";
    cout << "Total Waktu Tempuh : " << dist[goal] << " menit\n";

    return 0; 
}
```

---

### E. Hasil Eksekusi dan Analisis

**Output Program:**

```
===== FOOD DELIVERY =====
Rute Tercepat :
Restoran -> B -> D -> Pelanggan

Total Waktu Tempuh : 7 menit
```

**Analisis Hasil:**

Algoritma Dijkstra berhasil menemukan jalur paling optimal dengan rincian waktu:

| Segmen Rute | Waktu Tempuh |
|---|---|
| Restoran → B | 2 menit |
| B → D | 2 menit |
| D → Pelanggan | 3 menit |
| **Total** | **7 menit** |

Jalur ini terbukti lebih cepat dibandingkan rute alternatif lainnya, seperti jalur R → A → E → P (14 menit), R → C → D → P (14 menit), atau R → B → E → P (9 menit). Maka jalur melalui B dan D merupakan jalur paling optimal.

---

### F. Kompleksitas Algoritma

Dengan menggunakan struktur data Priority Queue, kompleksitas waktu algoritma ini adalah $O((V + E) \log V)$.

- $V$ = Jumlah Vertex (7)
- $E$ = Jumlah Edge (11)

---

### G. Kesimpulan

- Algoritma Dijkstra sangat akurat dan dapat digunakan untuk menentukan rute tercepat pada sistem operasional Food Delivery.
- Penggunaan graf berbobot berhasil merepresentasikan jaringan jalan dan besaran waktu tempuh.
- Implementasi pencarian menggunakan `priority_queue` dalam bahasa C++ memberikan kinerja eksekusi program yang efisien.
- Rute pengiriman paling cepat yang direkomendasikan sistem adalah **Restoran → B → D → Pelanggan** dengan menghabiskan total waktu tempuh minimum **7 menit**.