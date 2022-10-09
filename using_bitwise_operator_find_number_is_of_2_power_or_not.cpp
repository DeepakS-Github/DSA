// If there is only one setbit(1) in it's binary form then it comes in power of 2

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int bit;
    int count = 0;
    while(n!=0){
        bit=n&1;
        if(bit==1){
            count++;
        }
        if(count>1){
            break;
        }
        n=n>>1;
    }
    if(count==1){
        cout << "Comes in power of 2" << endl;
    }
    else{
        cout << "Does not comes in power of 2" << endl;
    }
}