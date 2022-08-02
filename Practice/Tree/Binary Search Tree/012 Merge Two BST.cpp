/*Approach 1
step 1 : create a vector of stored inorder of both BST
step 2 : merge two sorted arrays 
step 3 : sorted array / inorder to BST
T.c O(m+n) & S.C O(m+n)
*/
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void storeIntoInorder(TreeNode<int> *root,vector<int>& in){
    if(root == NULL)
        return ;
    storeIntoInorder(root->left,in);
    in.push_back(root->data);
    
    storeIntoInorder(root->right,in);
}
vector<int> merge(vector<int>& a,vector<int>& b){
    vector<int> sortedOutput(a.size() + b.size());
    int i = 0,j =0,k = 0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            sortedOutput[k++] = a[i];
            i++;
        }else{
            sortedOutput[k++] = b[j];
            j++;
        }
    }
    while( i<a.size() ){
        sortedOutput[k++] = a[i];
        i++;
    }
    while( j<b.size() ){
        sortedOutput[k++] = b[j];
        j++;
    }
    return sortedOutput;
}
TreeNode<int> *inorderToBST(int s,int e, vector<int>& in){
    if(s>e) 
        return NULL;
    int mid = (s+e)/2;
    TreeNode<int> * root = new TreeNode<int> (in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> bst1,bst2;
    storeIntoInorder(root1,bst1);
    storeIntoInorder(root2,bst2);
    
    vector<int> mergeTwoInorderArray = merge(bst1,bst2);
    int s = 0;
    int e = mergeTwoInorderArray.size() - 1;
    return inorderToBST(s,e,mergeTwoInorderArray);
}

/*Approach 2
step 1 : convert of both BST into sorted LinkedList
step 2 : merge two sorted LinkedList 
step 3 : sorted linkedlist to BST
T.c O(m+n) & S.C O(h1+h2)
*/
