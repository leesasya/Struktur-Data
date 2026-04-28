#include<iostream>
#include<string>
using namespace std;

#define MAX 100
string queue[MAX];
int front = -1, rear = -1;

void enqueue(string nama){
    if(rear == MAX - 1) cout << "[!] Antrian Penuh!" << endl;
    else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = nama;
        cout << "[+] " << nama << " berhasil masuk ke antrian." << endl;
    }
}

void dequeue(){
    if(front == -1 || front > rear) cout << "[!] Antrian Kosong! Tidak ada mahasiswa yang bisa dipanggil." << endl;
    else cout << "[V] " << queue[front] << " dipanggil untuk dilayani." << endl; front++;
}

void tampilkan(){
    if(front == -1 || front > rear) cout << "Kondisi Antrian: Kosong" << endl;
    else{
        cout << "Kondisi Antrian saat ini: ";
        for(int i = front; i <= rear; i++){
            cout << queue[i];
            if(i<rear) cout << " -> ";
        }
        cout << endl;
    }
}

int main(){
    int pilihan;
    string nama_mhs;

    do{
        cout << "\n========== SISTEM ANTRIAN LAYANAN AKADEMIK ==========" << endl;
        cout << "1. Ambil Antrian (Enqueue)" << endl;
        cout << "2. Panggil Antrian (Dequeue)" << endl;
        cout << "3. Tampilkan Antrian Saat Ini" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, nama_mhs);
                enqueue(nama_mhs);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilkan();
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "[!] Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 4);

    return 0;
}