#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a=1;
    int p;
    for(int i=1; i<=n; i++){
        p = a;
        for(int j=1; j<=i; j++){
            cout << p << " ";
            p++;
        }
        cout << endl;
        a++;
    }
}