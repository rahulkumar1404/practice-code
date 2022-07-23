/*
https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1 
*/
//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createMapping(int in[],int n,map<int,int> &nodeToIndex)
{
    int i = 0;
    while(n--){
        nodeToIndex[in[i]] = i;
        i++;
    }
}

Node* solve(int in[],int post[],int &postOrderIndex,int inOrderStartIndex,int inOrderEndIndex, int n,map<int,int> &nodeToIndex){
    if(postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex){
        return NULL;
    }
    int ele = post[postOrderIndex--];
    Node* root = new Node(ele);
    // int pos = findPos(in,ele,n); //if want to find every index by for loop  but it will increases time complexity
    int pos = nodeToIndex[ele];
    
    root->right= solve(in,post,postOrderIndex,pos+1,inOrderEndIndex,n,nodeToIndex);
    root->left = solve(in,post,postOrderIndex,inOrderStartIndex,pos-1,n,nodeToIndex);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n-1;
    int inOrderStartIndex = 0;
    int inOrderEndIndex = n-1;
    //mapping
    map<int,int> nodeToIndex;
    createMapping(in,n,nodeToIndex);
    Node* ans = solve(in,post,postOrderIndex,inOrderStartIndex,inOrderEndIndex,n,nodeToIndex);
    return ans;
}
