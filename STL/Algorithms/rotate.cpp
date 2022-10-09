#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    rotate(v.begin(),v.begin()+2,v.end());
    for(int i:v){
        cout << i << " ";
    }
    
}