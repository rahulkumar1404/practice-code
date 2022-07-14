/*Binary Tree Creation and Traversal*/
#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* right;
        Node* left;
    public:
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* bulidTree(Node* root){
    std::cout << "enter the data" << std::endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;
    
    std::cout << "enter the data to be stored on left of the "<< data << std::endl;
    root->left = bulidTree(root->left);
    
    std::cout << "enter the data to be stored on right of the "<< data << std::endl;
    root->right = bulidTree(root->right);
    
    return root;
}
void inlineTravesal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    cout<<endl;
}
void treeTraversal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
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
/*
1 3 7 -1 -1 11 -1 -1 5  6 -1 -1 8 -1 -1 
*/
int main()
{
    Node* root = NULL;
    root = bulidTree(root);
    inlineTravesal(root);
    treeTraversal(root);
    
    cout<<"inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder Traversal"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}
/*
enter the data
1 3 7 -1 -1 11 -1 -1 5  6 -1 -1 8 -1 -1
enter the data to be stored on left of the 1
enter the data
enter the data to be stored on left of the 3
enter the data
enter the data to be stored on left of the 7
enter the data
enter the data to be stored on right of the 7
enter the data
enter the data to be stored on right of the 3
enter the data
enter the data to be stored on left of the 11
enter the data
enter the data to be stored on right of the 11
enter the data
enter the data to be stored on right of the 1
enter the data
enter the data to be stored on left of the 5
enter the data
enter the data to be stored on left of the 6
enter the data
enter the data to be stored on right of the 6
enter the data
enter the data to be stored on right of the 5
enter the data
enter the data to be stored on left of the 8
enter the data
enter the data to be stored on right of the 8
enter the data
1 3 5 7 11 6 8 
1 
3 5 
7 11 6 8 

inorder Traversal
7 3 11 1 6 5 8 
preorder Traversal
1 3 7 11 5 6 8 
postorder Traversal
7 11 3 6 8 5 1 

*/
