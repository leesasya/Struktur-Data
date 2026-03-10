#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s = "thequickbrownfoxjumpsoverthelazydog";

    for (char c : s) {
        c = toupper(c);
        if(c == 'Z') c = 'A';
        else c = c+1;
        cout << c;
    }
    cout << endl;
}
