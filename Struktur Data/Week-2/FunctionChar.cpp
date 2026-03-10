#include<iostream>
using namespace std;

void vowelOrConsonant(char x){
    if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o' ||
    x == 'A' || x == 'I' || x == 'U' || x == 'E' || x == 'O')
    cout << "Vowel" << endl;
    else cout << "Consonant" << endl;
}

int main(){
    vowelOrConsonant('c');
    vowelOrConsonant('E');
    return 0;
}