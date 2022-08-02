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
void convertIntoSortedDoublyLinkedList(TreeNode<int>* &root,TreeNode<int>*& head){
    if(root == NULL)
        return ;
    convertIntoSortedDoublyLinkedList(root->right,head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;
    convertIntoSortedDoublyLinkedList(root->left,head);
}
TreeNode<int>* mergeTwoLinkedList(TreeNode<int>* &head1,TreeNode<int>*& head2){
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
                
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
                
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int countNodes(TreeNode<int>* &head){
    int cnt = 0;
    TreeNode<int>* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
TreeNode<int>* linkedListToBST(TreeNode<int>* &head,int n){
    if(n <= 0 || head == NULL)
        return NULL;
    TreeNode<int>* left = linkedListToBST(head,n/2);
    
    TreeNode<int>* root = head;
    root->left = left;
    head = head->right;
    root->right = linkedListToBST(head,n - n/2 -1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    TreeNode<int>* head1 = NULL;
    convertIntoSortedDoublyLinkedList(root1,head1);
    head1->left = NULL;
    TreeNode<int>* head2 = NULL;
    convertIntoSortedDoublyLinkedList(root2,head2);
    head2->left = NULL;
    
    TreeNode<int>* head = mergeTwoLinkedList(head1,head2);
    
    return linkedListToBST(head,countNodes(head));
}
