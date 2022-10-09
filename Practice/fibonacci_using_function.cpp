#include <iostream>
using namespace std;

void fib(int n){
    int ans = 0;
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for(int i=1; i<=n-2; i++){
        ans = a+b;
        if(i%2!=0){
            a = ans;
        }
        else{
            b = ans;
        }
        cout << ans << " ";
    }
}

int main(){
    int len;
    cin >> len;
    fib(len);
}