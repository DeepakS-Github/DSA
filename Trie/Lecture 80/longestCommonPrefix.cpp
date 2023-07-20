#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int countNode;

    TrieNode(char ch){
        this -> data = ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal = false;
        countNode = 0; 
    } 
};

class Trie{
    public:
    TrieNode* root = new TrieNode('\0');

    void insertUtil(TrieNode* root, string word, int index){
        if(index==word.size()){
            root -> isTerminal = true;
            return;
        }
        int chIndex = word[index]-'a';
        if(root->children[chIndex]==NULL){
            (root -> countNode)++;
            char ch = word[chIndex];
            TrieNode* node = new TrieNode(ch);
            root -> children[chIndex] = node;
        }
        insertUtil(root->children[chIndex], word, index+1);
    }

    void insert(string word){
        insertUtil(root, word, 0);
    }

    void longestPrefix(TrieNode* root, string word, int index){
        if(root->countNode!=1 || index==word.size()){
            return;
        }
        char ch = word[index];
        cout << ch;
        char chIndex = ch-'a';
        longestPrefix(root->children[chIndex], word, index+1);
    }

    void ans(string word){
        longestPrefix(root, word, 0);
    }
};

int main(){
    // Not work in this case
    // Although there is simple and better approach: using array, but to know trie concept we use this Data Structure
    Trie tr;
    string arr[2]={"coding","codingNinja"};
    for(int i=0; i<2; i++){
        tr.insert(arr[i]);
    }
    tr.ans(arr[0]);

}