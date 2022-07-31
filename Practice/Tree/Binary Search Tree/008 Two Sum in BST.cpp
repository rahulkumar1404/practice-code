/*
https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
*/
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void inorder(BinaryTreeNode<int>* root, vector<int> & in){
    if(root == NULL) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> in;
    inorder(root,in);
    int i = 0;
    int j = in.size() - 1;
    int sum;
    while(i<j){
        sum =in[i]+in[j];
        if(sum == target) return true;
        else if(sum < target) i++;
        else if(sum > target) j--;   
    }
    return false;
}
