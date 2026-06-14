#include<iostream>
using namespace std;

int main(){
    int myArray[] = {2,4,6,8};
    for(int i=0; i<=8; i++){
        cout << myArray[i] << endl;
        cout << "id: " << &myArray[i] << endl;
    }
    return 0;
}