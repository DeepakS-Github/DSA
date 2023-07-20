#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this -> data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root = new TrieNode('\0');

    // Insert
    void insertUtil(TrieNode* root, string word, int index){
        if(index==word.size()){
            root -> isTerminal = true;
            return;
        }
        int chIndex = word[index] - 'a';
        if(root->children[chIndex]==NULL){
            char ch = word[index];
            TrieNode* node = new TrieNode(ch);
            root -> children[chIndex] = node;
        }
        insertUtil(root->children[chIndex], word, index+1);
    }

    void insert(string word){
        insertUtil(root, word, 0);
    }

    // Search
    bool searchUtil(TrieNode* root, string word, int index){
        if(index==word.size()){
            return root->isTerminal;
        }
        int chIndex = word[index]-'a';
        if(root->children[chIndex]==NULL){
            return false;
        }
        return searchUtil(root->children[chIndex], word, index+1);
    }

    void search(string word){
        cout << searchUtil(root, word, 0) << endl;
    }

    // Delete
    void removeUtil(TrieNode* root, string word, int index){
        if(index==word.size()){
            root -> isTerminal = false;
            return;
        }
        int chIndex = word[index]-'a';
        removeUtil(root->children[chIndex], word, index+1);
    }

    void remove(string word){
        removeUtil(root, word, 0);
    }


};

int main(){
    Trie tr;

    // Note: here we are inserting "tom" but in trie it is "'\0'tom", size is 4, but word size is 3
    tr.insert("tom");
    tr.insert("tomato");
    tr.remove("tom");
    tr.search("tomato");
}