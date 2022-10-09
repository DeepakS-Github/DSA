#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int,string> m;

    m[1] = "deepak";
    m[13] = "info";
    m[2] = "tech";

    m.insert({5,"IT"});

    cout << "Before erase:" << endl;
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }cout << endl;
    
    cout << "Finding -13:" << m.count(-13) << endl;

    m.erase(13);

    cout << "After erase:" << endl;
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }cout << endl;

    auto it = m.find(5);

    for(auto i=it; i!=m.end(); i++){
        cout << (*i).first << " " << (*i).second << endl;
    }

}