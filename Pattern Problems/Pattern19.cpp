#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char a = 'A'+(n-1);
    char p;
    for(int i=1; i<=n; i++){
        p = a;
        for(int j=1; j<=i; j++){
            cout << p << " ";
            p++;
        }
        cout << endl;
        a--;
    }
}