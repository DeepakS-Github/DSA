#include <iostream>
#include <vector>
using namespace std;


void allSubsets(int index, int *arr, int size, vector<int> output){
    if(index==size){
        cout << "{ ";
        for(int i=0; i<output.size(); i++){
            cout << output[i] << " ";
        }
        cout << "}";
        cout << endl;
        return;
    }
    allSubsets(index+1, arr, size,  output);
    output.push_back(arr[index]);
    allSubsets(index+1, arr, size,  output);
    output.pop_back();
}


int main(){
    int arr[3]={1,2,3};
    vector <int> output;
    allSubsets(0, arr, 3,  output);

}