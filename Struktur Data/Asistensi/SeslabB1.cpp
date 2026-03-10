#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, prio;
    string task, rules="seru-seruan";
    priority_queue<pair<int, string>> job;
    cin >> n;
    while(n--){
        cin >> prio;
        getline(cin, task);
        if(task.find(rules) == string::npos){
            job.push(make_pair(prio, task));
        }
    }
    while(!job.empty()){
        cout << job.top().second << endl;
        job.pop();
    }

    return 0;
}