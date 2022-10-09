#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s = "abcd";
    reverse(s.begin(),s.end());
    cout << s << endl;
}