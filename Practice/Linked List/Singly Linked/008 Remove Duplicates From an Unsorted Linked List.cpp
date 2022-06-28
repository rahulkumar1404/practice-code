/*
https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan
*/
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
    // Write your code here
     if(head==NULL || head->next==NULL)return head;
    unordered_map<int,int> m;
    Node *curr=head;
    m[curr->data]=1;
    Node *prev=curr;
    curr=curr->next;
    while(curr != NULL)
    {
        if(m[curr->data]){
            prev -> next = curr -> next;
            free(curr);
        }
        else{
            m[curr->data]=1;
            prev=curr;
        }
        curr=prev->next;
    }
    return head;
}
