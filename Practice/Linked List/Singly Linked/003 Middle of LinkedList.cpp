/*
https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTab=1
*/
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
//approach1 iterative approach
/*int length(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int len = length(head);
    int ans = len/2;
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
}*/

//approach 2  t.c O(n/2) i.e O(n) & s.c O(1)

Node *findMiddle(Node *head) {
    // Write your code here
    if(head==NULL||head->next==NULL) return head;
    if(head->next->next==NULL) return head->next;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL) fast=fast->next;
        slow = slow->next;
    }
    return slow;
}
