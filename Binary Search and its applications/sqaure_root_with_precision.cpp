#include <iostream>
using namespace std;

int IntegerPart(int x) {
    int start = 0;
    int end = x;
    int ans;
    while(start<=end){
        long long int mid = start + (end-start)/2;
        long long int square = mid*mid;
        if(square<=x){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

double withPrecision(int x, int precision, int tempSol){
    double factor=1;
    double ans = tempSol;
    for(int i=1; i<=precision; i++){
        factor = factor/10;
        for(double j=ans; j*j<x; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int num=37;
    int precision = 5;
    int tempSoln = IntegerPart(num);
    cout << withPrecision(num, precision, tempSoln);
}