#include<bits/stdc++.h>
using namespace std;

// === STRUKTUR DATA ===
// 1. Queue biasa untuk antrian normal
queue<string> antrianNormal;

// 2. Priority Queue untuk antrian prioritas (Disabilitas/Darurat)
// Pair: <Tingkat Prioritas (int), Nama (string)>. Prioritas makin tinggi, makin didahulukan.
priority_queue<pair<int, string>> antrianPrioritas;

// 3. Stack untuk riwayat pembatalan (Undo)
stack<string> riwayatAktivitas;

// 4. Graph (Adjacency List) untuk Rute Kampus
unordered_map<string, vector<string>> petaKampus;

// === FUNGSI INIT GRAPH KAMPUS ===
void inisialisasiPeta() {
    // Membangun jalur antar gedung
    petaKampus["Gerbang Depan"].push_back("Gedung Rektorat");
    petaKampus["Gerbang Depan"].push_back("Fakultas Teknik");
    petaKampus["Gedung Rektorat"].push_back("Gerbang Depan");
    petaKampus["Gedung Rektorat"].push_back("Perpustakaan");
    petaKampus["Fakultas Teknik"].push_back("Gerbang Depan");
    petaKampus["Fakultas Teknik"].push_back("Kantin Pusat");
    petaKampus["Perpustakaan"].push_back("Gedung Rektorat");
    petaKampus["Perpustakaan"].push_back("Kantin Pusat");
    petaKampus["Kantin Pusat"].push_back("Fakultas Teknik");
    petaKampus["Kantin Pusat"].push_back("Perpustakaan");
}

// === FUNGSI NAVIGASI (GRAPH BFS) ===
// Menggunakan BFS untuk mencari rute terpendek (tanpa bobot jarak)
void cariRute(string asal, string tujuan) {
    if (petaKampus.find(asal) == petaKampus.end() || petaKampus.find(tujuan) == petaKampus.end()) {
        cout << "[!] Lokasi asal atau tujuan tidak ditemukan di peta." << endl;
        return;
    }

    queue<vector<string>> jalurQueue;
    vector<string> jalurAwal = {asal};
    jalurQueue.push(jalurAwal);
    
    map<string, bool> dikunjungi;
    dikunjungi[asal] = true;

    while (!jalurQueue.empty()) {
        vector<string> jalurSaatIni = jalurQueue.front();
        jalurQueue.pop();
        
        string nodeTerakhir = jalurSaatIni.back();

        if (nodeTerakhir == tujuan) {
            cout << "\n[V] Rute Terpendek Ditemukan: \n";
            for (int i = 0; i < jalurSaatIni.size(); i++) {
                cout << jalurSaatIni[i];
                if (i < jalurSaatIni.size() - 1) cout << " -> ";
            }
            cout << endl;
            
            // Catat riwayat untuk bisa di-undo
            riwayatAktivitas.push("Mencari rute: " + asal + " ke " + tujuan);
            return;
        }

        for (string tetangga : petaKampus[nodeTerakhir]) {
            if (!dikunjungi[tetangga]) {
                dikunjungi[tetangga] = true;
                vector<string> jalurBaru = jalurSaatIni;
                jalurBaru.push_back(tetangga);
                jalurQueue.push(jalurBaru);
            }
        }
    }
    cout << "[!] Tidak ada jalur yang menghubungkan kedua lokasi." << endl;
}

// === FUNGSI ANTRIAN KONSULTASI ===
void ambilAntrian(string nama, bool prioritas) {
    if (prioritas) {
        // Asumsi prioritas bernilai 10
        antrianPrioritas.push({10, nama});
        cout << "[+] Mahasiswa PRIORITAS atas nama " << nama << " masuk antrian." << endl;
        riwayatAktivitas.push("Daftar Antrian Prioritas: " + nama);
    } else {
        antrianNormal.push(nama);
        cout << "[+] Mahasiswa atas nama " << nama << " masuk antrian normal." << endl;
        riwayatAktivitas.push("Daftar Antrian Normal: " + nama);
    }
}

void panggilAntrian() {
    // Selalu cek priority queue terlebih dahulu
    if (!antrianPrioritas.empty()) {
        cout << "[>>>] PANGGILAN PRIORITAS: Melayani mahasiswa " << antrianPrioritas.top().second << endl;
        riwayatAktivitas.push("Melayani Antrian Prioritas: " + antrianPrioritas.top().second);
        antrianPrioritas.pop();
    } 
    else if (!antrianNormal.empty()) {
        cout << "[>] PANGGILAN NORMAL: Melayani mahasiswa " << antrianNormal.front() << endl;
        riwayatAktivitas.push("Melayani Antrian Normal: " + antrianNormal.front());
        antrianNormal.pop();
    } 
    else {
        cout << "[!] Semua antrian saat ini kosong." << endl;
    }
}

// === FUNGSI UNDO (STACK) ===
void batalkanAktivitasTerakhir() {
    if (riwayatAktivitas.empty()) {
        cout << "[!] Tidak ada aktivitas yang bisa dibatalkan." << endl;
    } else {
        cout << "[UNDO] Membatalkan riwayat terakhir: " << riwayatAktivitas.top() << endl;
        riwayatAktivitas.pop();
        // Catatan: Di implementasi nyata, membatalkan berarti menghapus data dari queue juga,
        // namun untuk simulasi sederhana kita hanya menghapus log riwayatnya.
    }
}

// === PROGRAM UTAMA ===
int main() {
    inisialisasiPeta();
    int pilihan;

    do {
        cout << "\n=============================================" << endl;
        cout << "       SMART CAMPUS NAVIGATION SYSTEM        " << endl;
        cout << "=============================================" << endl;
        cout << "1. Cari Rute Terpendek (Graph)" << endl;
        cout << "2. Ambil Antrian Konsultasi Normal (Queue)" << endl;
        cout << "3. Ambil Antrian Prioritas (Priority Queue)" << endl;
        cout << "4. Panggil Antrian Selanjutnya" << endl;
        cout << "5. Undo Aktivitas Terakhir (Stack)" << endl;
        cout << "6. Keluar" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string asal, tujuan;
                cout << "Tersedia: Gerbang Depan, Gedung Rektorat, Fakultas Teknik, Perpustakaan, Kantin Pusat\n";
                cout << "Masukkan Lokasi Asal: ";
                cin.ignore(); getline(cin, asal);
                cout << "Masukkan Lokasi Tujuan: ";
                getline(cin, tujuan);
                cariRute(asal, tujuan);
                break;
            }
            case 2: {
                string nama;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); getline(cin, nama);
                ambilAntrian(nama, false);
                break;
            }
            case 3: {
                string nama;
                cout << "Masukkan Nama Mahasiswa Prioritas: ";
                cin.ignore(); getline(cin, nama);
                ambilAntrian(nama, true);
                break;
            }
            case 4:
                panggilAntrian();
                break;
            case 5:
                batalkanAktivitasTerakhir();
                break;
            case 6:
                cout << "Terima kasih telah menggunakan Smart Campus System!" << endl;
                break;
            default:
                cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (pilihan != 6);

    return 0;
}