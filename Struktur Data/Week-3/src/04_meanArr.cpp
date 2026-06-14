#include<iostream>
using namespace std;

int main(){
    int nilai[5];
    int total=0;
    float mean;

    for(int i=0; i<5; i++){
        cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
        cin >> nilai[i];
        total += nilai[i];
    }
    mean = total / 5.0;

    cout << "\nTotal nilai : " << total << endl;
    cout << "Rata-rata : " << mean << endl;
    
    return 0;
}