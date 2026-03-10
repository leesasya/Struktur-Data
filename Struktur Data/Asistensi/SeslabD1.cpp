#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    priority_queue<long long> food;

    cin >> n;
    while(n--){
        cin >> x;
        food.push(x);
    }

    while(food.size() > 1){
        long long a = food.top(); food.pop();
        long long b = food.top(); food.pop();

        food.push(a-b);
    }

    if(food.empty()) cout << 0 << endl;
    else cout << food.top() << endl;
}