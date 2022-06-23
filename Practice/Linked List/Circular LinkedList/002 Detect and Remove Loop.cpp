/*
https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0
*/
/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* folydDetect(Node* head){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast) return slow;
    }
    return NULL;
}
Node* startingNode(Node* head){
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* intersection = folydDetect(head);
    if(intersection == NULL) return intersection;
    while(slow!= intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL) return NULL;
    Node* start = startingNode(head);
    if(start==NULL) return head;
    
    Node* temp = start;
    while(temp->next!=start){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
