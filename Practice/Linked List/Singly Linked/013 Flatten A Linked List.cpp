/*
https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTab=3
*/
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* down,Node* right){
    if(down==NULL) return right;
    if(right==NULL) return down;
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(down!=NULL && right!=NULL){
        if(down->data < right->data){
            temp->child = down;
            temp = down;
            down = down->child;
        }else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    if(down!=NULL){
        temp->child = down;
        temp = down;
        down = down->child;
    }
    if(right!=NULL){
        temp->child = right;
        temp = right;
        right = right->child;
    }
    ans = ans->child;
    return ans;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    //base case
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    down->next = NULL;
    Node* ans = merge(down,right);
    return ans;
}
