#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char d){
            data = d;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode('1');
        }
        void insertUtil(TrieNode* root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            int index = word[0] - 'A';
            TrieNode* child;
            //present 
            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
            //recursion
            insertUtil(child,word.substr(1));
        }
        void insert(string word){
            insertUtil(root,word);
        }
        
        bool searchUtil(TrieNode*& root,string word){
            if(word.length() == 0){
                return root->isTerminal;
            }
            int index = word[0] - 'A';
            TrieNode* child;
            
            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                return false;
            }
            return searchUtil(child,word.substr(1));
        }
        bool search(string word){
            return searchUtil(root,word);
        }
        
};
int main()
{
    Trie* t = new Trie();
    
    t->insert("Adacdf");
    t->insert("dcf");
    t->insert("ad");
    t->insert("DEFEWF");
    
    cout << "present or not " << t->search("Adacdf");
    cout<<endl;
    cout << "present or not " << t->search("dcf");
    cout<<endl;
    cout << "present or not " << t->search("ad");
    cout<<endl;
    cout << "present or not " << t->search("DEFEWF");
    cout<<endl;
    
    return 0;
}
