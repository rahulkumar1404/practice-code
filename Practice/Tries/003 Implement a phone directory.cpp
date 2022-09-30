/*
https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
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
            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
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
        void printsuggestions(TrieNode* curr,vector<string>& temp,string pre){
            if(curr->isTerminal){
                temp.push_back(pre);
            }
            for(char ch = 'a';ch<='z';ch++){
                TrieNode* next = curr->children[ch-'a'];
                if(next!=NULL){
                    pre.push_back(ch);
                    printsuggestions(next,temp,pre);
                    pre.pop_back();
                }
            }
        }
        vector<vector<string>> getsuggestions(string str){
            TrieNode* prev = root;
            vector<vector<string>> ans;
            string pre = "";
            for(int i = 0;i<str.length();i++){
                char ch = str[i];
                pre.push_back(ch);
                TrieNode* curr = prev->children[ch-'a'];
                if(curr == NULL){
                    break;
                }
                vector<string> temp;
                printsuggestions(curr,temp,pre);
                ans.push_back(temp);
                temp.clear();
                prev = curr;
            }
            return ans;
        }
        
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t = new Trie();
    for(auto i : contactList){
        t->insert(i);
    }
    return t->getsuggestions(queryStr);
}
