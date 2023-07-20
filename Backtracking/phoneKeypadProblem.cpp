#include <iostream>
#include <vector>
using namespace std;


void keypad(int *arr, string *map, vector<char> output, int size, int index){
    if(index==size){
        for(int i=0; i<size; i++){
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0; i<map[arr[index]].size(); i++){
        output.push_back(map[arr[index]][i]);
        keypad(arr, map, output, size, index+1);
        output.pop_back();
    }
}


int main(){
    string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int arr[2] = {2,3};
    vector<char> output;
    keypad(arr, map, output, 2, 0);
}