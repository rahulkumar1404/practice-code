/*
https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0
*/
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>* root,int& i, int k){
    if(root == NULL) return -1;
    
    //inorder LNR
    
    //L
    int L = solve(root->left,i,k);
    if(L != -1){
        return L;
    }
    
    //N
    i++;
    if(i == k) return root->data;
    
    //R
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root,i,k);
}
