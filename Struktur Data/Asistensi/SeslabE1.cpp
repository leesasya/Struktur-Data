#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, inp;
    vector<int> list;
    cin >> t;

    while(t--){
        cin >> a;
        switch(a){
            case 1: 
            cin >> inp;
            list.push_back(inp);
            break;

            case 2:
            cin >> inp;
            if(!list.empty()){
                for(int i=0; i<list.size(); i++){
                    list[i] += inp;
                }
            } 
            break;

            case 3:
            if(!list.empty()){
                list.pop_back();
            } else cout << "kosong woe" << endl;
            break;

            case 4:
            if(!list.empty()){
            for(int i=0; i<list.size(); i++){
                    cout << list[i] << " ";
                }
            } else cout << "gaada isinya :(" << endl;
            break;

            case 5:
                int idx, val;
                cin >> idx >> val;
                if(idx >= 0 && idx <= list.size()){
                    list.insert(list.begin() + idx, val);
                }
                break;
        }
    }
    return 0;
}