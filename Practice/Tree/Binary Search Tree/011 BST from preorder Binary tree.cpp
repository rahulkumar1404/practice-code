/*
https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0
*/
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>* solve(vector<int>& pre,int mini,int maxi,int& i){
    if( i >= pre.size() )
        return NULL;
    if( mini > pre[i] || maxi < pre[i] )
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[i++]);
    root->left = solve(pre,mini,root->data,i);
    root->right = solve(pre,root->data,maxi,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder,mini,maxi,i);
}
