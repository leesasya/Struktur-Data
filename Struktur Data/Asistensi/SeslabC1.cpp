#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    char a;
    stack<char> main, snd, temp, temp2;

    cin >> n;
    while(n--){
        cin >> a;
        main.push(a);
    }

    cin >> t;
    while(t--){
        string cmd;
        cin >> cmd;

        if(cmd == "PULL"){
            int x;
            cin >> x;
            if(x > main.size()){
                cout << "Macaron Furina tidak sebanyak itu pls!" << endl;
                continue;
            }

            for(int i=1; i<x; i++){
                temp.push(main.top());
                main.pop();
            }
            snd.push(main.top());
            main.pop();

            while(!temp.empty()){
                temp2.push(temp.top());
                temp.pop();
            }

            while(!temp2.empty()){
                main.push(temp2.top());
                temp2.pop();
            }
        }
        else if(cmd == "PUT"){
            while(!snd.empty()){
                main.push(snd.top());
                snd.pop();
            }
        }
        else{
            cout << "Apa itu? Furina tidak paham!" << endl;
        }
    }

    vector<char> vmain;
    while(!main.empty()){
        vmain.push_back(main.top());
        main.pop();
    }
    reverse(vmain.begin(), vmain.end());

    for(int i=0; i<vmain.size(); i++){
        cout << vmain[i] << " ";
    }
    cout << endl;

    vector<char> vsnd;
    while(!snd.empty()){
        vsnd.push_back(snd.top());
        snd.pop();
    }
    reverse(vsnd.begin(), vsnd.end());

    for(int i=0; i<vsnd.size(); i++){
        cout << vsnd[i] << " ";
    }
    cout << endl;
}