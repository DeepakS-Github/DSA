#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int a=n;
    int p=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j>=a){
                cout << p << " ";
            }
            else{
                cout << "  ";
            }
        }
        a--;
        p++;
        cout << endl;
    }
}