#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, s;
    string status;
    queue<int> idx;
    cin >> n;
    while(n--){
        cin >> a;
        idx.push(a);
    }
    
    cin >> s;
    while(s--){
        cin >> status;
        if(status == "BERHASIL"){
            if(!idx.empty()) idx.pop();
        } else if(status == "GAGAL"){
            if(!idx.empty()){
                idx.push(idx.front());
                idx.pop();
            }
        } 
    }
    if(idx.empty()){
        cout << "KOSONG";
    } else {
        while(!idx.empty()){
            cout << idx.front() << " ";
            idx.pop();
        }
    }
    return 0;
}