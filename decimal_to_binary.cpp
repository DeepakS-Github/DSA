#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int bit;
    if(n<0){
        int j=0;
        int ansneg[32] = {0};
        while(j<32){
            bit = n&1;
            ansneg[31-j] = bit;
            n = n>>1;
            j++;
        }
        for(int i=0; i<32; i++){
            cout << ansneg[i];
        }
    }
    else{
        int ans = 0;
        int i=0;
        while(n!=0){
            bit = n&1;
            ans = bit*pow(10,i)+ans;
            n = n >> 1;
            i++;
        }
        cout << ans << endl;
    }
}