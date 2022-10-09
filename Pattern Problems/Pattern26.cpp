#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int a=1;
        int p;
        for(int j=1; j<=2*n-1; j++){
            if(n-i>=j){
                cout << "  ";
            }
            if(n-i<j && j<=n){
                cout << a << " ";
                a++;
            }
            if(j==n){
                p=a-2;
            }
            if(j>n && i>=2 && p>=1){
                cout << p << " ";
                p--;
            }
        }
        cout << endl;
    }
}