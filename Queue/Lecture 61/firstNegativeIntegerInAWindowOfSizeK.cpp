#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int size = 8;
    int arr[size] = {8,1,-2,2,-3,6,8,-1};

    int i=0,j=0;
    int k=3;
    queue<int> neg;
    vector<int> ans;

    for(int m=0; m<k; m++){
        if(arr[j]<0){
            neg.push(j);
        }
        j++;
    } 

    ans.push_back(arr[neg.front()]);

    for(int m=k; m<size; m++){
        if(neg.front()==i){
            neg.pop();
        }
        if(arr[j]<0){
            neg.push(j);
        }
        i++;
        j++;
        if(neg.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[neg.front()]);
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}