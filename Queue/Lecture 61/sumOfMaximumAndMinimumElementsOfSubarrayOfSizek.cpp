#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    int size = 7;
    int arr[7]={2,5,-1,7,-3,-1,-2};
    int k = 3;

    queue <int> maxi;
    queue <int> mini;

    int maxi_i = 0;
    int mini_i = 0;


    
    int min;
    int max;
    int sum;

    for(int i=0; i<k; i++){
        if(maxi.empty()){
            maxi.push(i);
            max = arr[maxi.front()];
        }
        else if(arr[i]>arr[maxi.front()]){
            maxi.pop();
            maxi.push(i);
            max = arr[maxi.front()];
        }
        if(mini.empty()){
            mini.push(i);
            min = arr[mini.front()];
        }
        else if(arr[i]<arr[mini.front()]){
            mini.pop();
            mini.push(i);
            min = arr[mini.front()];
        }
    }

    sum = max + min;

    cout << max << " " << min << endl;


    for(int i=k; i<size; i++){
        if(mini_i == mini.front()){
            mini.pop();
        }
        mini_i++;
        if(mini.empty()){
            mini.push(i);
            min = arr[mini.front()];
        }
        else if(arr[i]<arr[mini.front()]){
            mini.pop();
            mini.push(i);
            min = arr[mini.front()];
        }


        if(maxi_i == maxi.front()){
            maxi.pop();
        }
        maxi_i++;
        if(maxi.empty()){
            maxi.push(i);
            max = arr[maxi.front()];
        }
        else if(arr[i]>arr[maxi.front()]){
            maxi.pop();
            maxi.push(i);
            max = arr[maxi.front()];
        }

        print(maxi);
        print(mini);
        cout << max << " " << min << endl;
        sum = sum + max + min;

    }

    cout << sum << endl;
}