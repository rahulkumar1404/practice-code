/*
https://practice.geeksforgeeks.org/problems/construct-tree-1/1
*/
//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createMapping(int in[],int n,map<int,int> &nodeToIndex){
        int i = 0;
        while(n--){
            nodeToIndex[in[i]] = i;
            i++;
        }
    }
    int findPos(int in[],int ele,int n){
        int i = 0;
        while(n--){
            if(in[i] == ele) {
                return i;
            }
            i++;
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &preOrderIndex,int inOrderStartIndex,int inOrderEndIndex, int n,map<int,int> &nodeToIndex){
        if(preOrderIndex >= n || inOrderStartIndex > inOrderEndIndex){
            return NULL;
        }
        int ele = pre[preOrderIndex++];
        Node* root = new Node(ele);
       // int pos = findPos(in,ele,n); //if want to find every index by for loop  but it will increases time complexity
       int pos = nodeToIndex[ele];
        root->left = solve(in,pre,preOrderIndex,inOrderStartIndex,pos-1,n,nodeToIndex);
        root->right= solve(in,pre,preOrderIndex,pos+1,inOrderEndIndex,n,nodeToIndex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        int inOrderStartIndex = 0;
        int inOrderEndIndex = n-1;
        //mapping
        map<int,int> nodeToIndex;
        createMapping(in,n,nodeToIndex);
        Node* ans = solve(in,pre,preOrderIndex,inOrderStartIndex,inOrderEndIndex,n,nodeToIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
