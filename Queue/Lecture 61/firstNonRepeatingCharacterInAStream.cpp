#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    string str = "aabcbc";

    map <char, int> count;
    queue <char> ch;
    string ans = "";

    for(int i=0; i<str.size(); i++){
        count[str[i]]++;
        ch.push(str[i]);

        while(!ch.empty()){
            if(count[ch.front()]>1){
                ch.pop();
            }
            else{
                ans.push_back(ch.front());
                break;
            }
        }

        if(ch.empty()){
            ans.push_back('#');
        }
        
    }

    cout << ans << endl;
}