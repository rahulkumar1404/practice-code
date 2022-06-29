/*
https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/#
*/
// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>;

class Solution{
    /*Approach 1 
    step 1 middle node find
    step2 after middle next get the reverse node 
    step3 check every head element and middle next element is equal or not
    step 4step2
    step5 return 1 or 0
    */
  public:
    Node* getmid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            
            slow = slow->next;
        }
        return slow;
    }
    Node* rev(Node* head){
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next == NULL) return true;
        Node* mid = getmid(head);
        Node* temp = mid->next;
        mid->next = rev(temp);
        Node* h1 = head;
        Node* h2 = mid->next;
        while(h2!=NULL){
            if(h1->data != h2->data) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        temp = mid->next;
        mid->next = rev(temp);
        return true;
    }
};
/*Approach 2 
    step 1 create array 
    step2 copy linkedlist element in array 
    step3 use method array method for palindrome checking
    step4 return 1 or 0
    */
class Solution{
  private:
  bool solve(vector<int> arr){
      int n = arr.size();
      int s = 0;
      int e = n-1;
      while(s<=e){
          if(arr[s]!=arr[e]) return 0;
          s++;
          e--;
      }
      return 1;
  }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        vector<int> arr;
        Node* curr = head;
        while(curr!=NULL){
            arr.push_back(curr->data);
            curr = curr->next;
        }
        return solve(arr);
    }
};


// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
