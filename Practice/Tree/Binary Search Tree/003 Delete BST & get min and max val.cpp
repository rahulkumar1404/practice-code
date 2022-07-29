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

Node* minVal(Node* root){
    if(root == NULL) return root;
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    if(root == NULL) return root;
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNodeInBst(Node* root,int value){
    //if root is NULL
    if(root == NULL) return root;
    if(root->data == value){
        
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        //1 child 
        //left child exists
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child exists
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        //2 child
        //left child exists
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNodeInBst(root->right,mini);
            return root;
        }
        
    }
    if(root->data > value){
        root->left = deleteNodeInBst(root->left,value);
        return root;
    }
    root->right = deleteNodeInBst(root->right,value);
    return root;
    
}
int main()
{
    Node* root = NULL;
    cout<<"takeInput "<<endl;
    
    takeInput(root);
    cout<<endl<<"printing levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"printing inorder"<<endl;
    inorder(root);
    cout<<endl<<"printing preorder"<<endl;
    preorder(root);
    cout<<endl<<"printing postorder"<<endl;
    postorder(root);
    
    cout<<endl<<"printing min value  "<<minVal(root) -> data<<endl;

    cout<<endl<<"printing max value  "<< maxVal(root) -> data <<endl;

    cout<<endl<<"deletion has been started "<<endl<<  "root = deleteNodeInBst(root,18);"<<endl;
    root = deleteNodeInBst(root,18);
    cout<<endl<<"changes after deletion" <<endl<<  "root = deleteNodeInBst(root,18);"<<endl;
    cout<<endl<<"printing levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"printing inorder"<<endl;
    inorder(root);
    cout<<endl<<"printing preorder"<<endl;
    preorder(root);
    cout<<endl<<"printing postorder"<<endl;
    postorder(root);
    
    cout<<endl<<"deletion has been started"<<endl<<" root = deleteNodeInBst(root,17);"<<endl;
    root = deleteNodeInBst(root,17);
    cout<<endl<<"changes after deletion"<<endl<<  "root = deleteNodeInBst(root,17);"<<endl;
    cout<<endl<<"printing levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"printing inorder"<<endl;
    inorder(root);
    cout<<endl<<"printing preorder"<<endl;
    preorder(root);
    cout<<endl<<"printing postorder"<<endl;
    postorder(root);
    
    cout<<endl<<"deletion has been started "<< endl<<"root = deleteNodeInBst(root,13);"<<endl;
    root = deleteNodeInBst(root,13);
    cout<<endl<<"changes after deletion"<<endl<<  "root = deleteNodeInBst(root,13);"<<endl;
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
10 11 8 9 7 13 12 14 6 8  17 20 16 7 8 15 18 -1

printing levelOrderTraversal 
10 
8 11 
7 9 13 
6 8 12 14 
7 8 17 
16 20 
15 18 


printing inorder
6 7 7 8 8 8 9 10 11 12 13 14 15 16 17 18 20 
printing preorder
10 8 7 6 7 8 8 9 11 13 12 14 17 16 15 20 18 
printing postorder
7 6 8 8 7 9 8 12 15 16 18 20 17 14 13 11 10 
printing min value  6

printing max value  20

deletion has been started 
root = deleteNodeInBst(root,18);

changes after deletion
root = deleteNodeInBst(root,18);

printing levelOrderTraversal 
10 
8 11 
7 9 13 
6 8 12 14 
7 8 17 
16 20 
15 


printing inorder
6 7 7 8 8 8 9 10 11 12 13 14 15 16 17 20 
printing preorder
10 8 7 6 7 8 8 9 11 13 12 14 17 16 15 20 
printing postorder
7 6 8 8 7 9 8 12 15 16 20 17 14 13 11 10 
deletion has been started
 root = deleteNodeInBst(root,17);

changes after deletion
root = deleteNodeInBst(root,17);

printing levelOrderTraversal 
10 
8 11 
7 9 13 
6 8 12 14 
7 8 20 
16 
15 


printing inorder
6 7 7 8 8 8 9 10 11 12 13 14 15 16 20 
printing preorder
10 8 7 6 7 8 8 9 11 13 12 14 20 16 15 
printing postorder
7 6 8 8 7 9 8 12 15 16 20 14 13 11 10 
deletion has been started 
root = deleteNodeInBst(root,13);

changes after deletion
root = deleteNodeInBst(root,13);

printing levelOrderTraversal 
10 
8 11 
7 9 14 
6 8 12 20 
7 8 16 
15 


printing inorder
6 7 7 8 8 8 9 10 11 12 14 15 16 20 
printing preorder
10 8 7 6 7 8 8 9 11 14 12 20 16 15 
printing postorder
7 6 8 8 7 9 8 12 15 16 20 14 11 10 
*/
