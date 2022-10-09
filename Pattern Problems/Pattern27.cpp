#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=2*n; j++){
            if(j<=n){
                if(j<=a){
                    cout << j << " ";
                }
                else{
                    cout << "* ";
                }
            }
            if(j>n){
                if(j>=n+i){
                    cout << 2*n-(j-1) << " ";
                }
                else{
                    cout << "* ";
                }   
            }
        }
        a--;
        cout << endl;
    }
}