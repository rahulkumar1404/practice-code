/*
https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0
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

bool isBST(BinaryTreeNode<int> *root , int mini ,int maxi){
    if(root == NULL) return true;
    
    if(root->data >= mini && root->data <= maxi){
        bool left = isBST(root->left,mini,root->data);
        bool right = isBST(root->right,root->data,maxi);
        return left && right;
    }
    return false;
} 
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,INT_MIN,INT_MAX);
}
