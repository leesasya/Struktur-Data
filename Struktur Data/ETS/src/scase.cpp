#include<iostream>
#include<string>
using namespace std;

#define MAX 100
string queue[MAX];
int front = -1, rear = -1;

void enqueue(string nama){
    if(rear == MAX - 1) cout << "Antrian Penuh!" << endl;
    else{
        if(front == -1) front = 0; rear++;
        queue[rear] = nama;
        cout << nama << " masuk antrian." << endl;
    }
}

void dequeue(){
    if(front == -1 || front > rear) cout << "Antrian Kosong!" << endl;
    else cout << queue[front] << " sedang dilayani." << endl; front++;
}

void tampilkan(){
    if(front == -1 || front > rear) cout << "Antrian saat ini: Kosong" << endl;
    else{
        cout << "Antrian saat ini: ";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    enqueue("Mahasiswa A");
    enqueue("Mahasiswa B");
    enqueue("Mahasiswa C");
    dequeue();
    enqueue("Mahasiswa D");
    tampilkan();
    
    return 0;
}
