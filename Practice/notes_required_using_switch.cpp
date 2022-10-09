#include <iostream>
using namespace std;

int hnote=0, fnote=0, tnote=0, onote=0;

int main(){
    int n;
    cin >> n;
    switch(1){
        case 1:
            hnote = n/100;
            n = n%100;
        case 2:
            fnote = n/50;
            n = n%50;
        case 3:
            tnote = n/20;
            n = n%20;
        default:
            onote = n;
    }
    cout << hnote << " " << fnote << " " << tnote << " " << onote;
}