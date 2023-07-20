#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(n^2logk)
// SC: O(k)

int main(){
    int size = 6;
    int arr[6]={5,2,6,1,9,7};
    priority_queue<int> maxHeap; 

    int sum = 0;
    int k=4;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            sum = sum + arr[j];
            if(k!=0){
                maxHeap.push(sum);
                k--;
            }
            else{
                if(maxHeap.top()>sum){
                    maxHeap.pop();
                    maxHeap.push(sum);
                }
            }
        }
        sum = 0;
    }

    cout << maxHeap.top() << endl;
}



