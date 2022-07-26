#include <iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* insertIntoBST(Node* &root,int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        root->right = insertIntoBST(root->right,d);
    }else{
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    std::cin >> data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode == NULL){
            cout <<endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout<<frontNode->data<<" ";
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
    cout<<endl;
}

void inorder(Node* root){//LNR formula
    //basecase
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    cout<< root -> data<<" ";
    inorder(root->right);
}
void preorder(Node* root){//NLR formula
    //basecase
    if(root == NULL){
        return;
    }
    
    cout<< root -> data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){//LRN formula
    //basecase
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<< root -> data<<" ";
}
int main()
{
    Node* root = NULL;
    cout<<endl<<"takeInput "<<endl;
    
    takeInput(root);
    cout<<endl<<"printing levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"printing inorder"<<endl;
    inorder(root);
    cout<<endl<<"printing preorder"<<endl;
    preorder(root);
    cout<<endl<<"printing postorder"<<endl;
    postorder(root);
    
    
    return 0;
}
/* 

takeInput
10 11 8 9 7 13 12 14 6 8  17 20 16 0 0 15 18 -1

printing levelOrderTraversal 
10 
8 11 
7 9 13 
6 8 12 14 
0 17 
0 16 20 
15 18 


printing inorder
0 0 6 7 8 8 9 10 11 12 13 14 15 16 17 18 20 
printing preorder
10 8 7 6 0 0 8 9 11 13 12 14 17 16 15 20 18 
printing postorder
0 0 6 8 7 9 8 12 15 16 18 20 17 14 13 11 10 
*/
