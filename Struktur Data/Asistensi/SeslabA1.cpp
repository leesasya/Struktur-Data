#include<bits/stdc++.h>
using namespace std;

int main(){
    string cmd;
    char temp;
    stack<char> chara, result;

    while(cmd != "PRINT"){
        cin >> cmd;
        if(cmd == "WRITE"){
            cin >> temp;
            chara.push(temp);
        } else if(cmd == "BACKSPACE"){
            chara.pop();
        } 
    }
    
    while(!chara.empty()){
        result.push(chara.top());
        chara.pop();
    }

    while(!result.empty()){
        cout << result.top();
        result.pop();
    }
    return 0;
}