/*
https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0
*/

//code
/********************************
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

********************************/

//data replacement allowed
Node* sortList(Node *head)
{
    // Write your code here.
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0) zero_count++;
        else if(temp->data == 1) one_count++;
        else if(temp->data == 2) two_count++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(zero_count != 0){
            temp->data = 0;
            zero_count--;
        }else if(one_count != 0){
            temp->data = 1;
            one_count--;
        }else if(two_count != 0){
            temp->data = 2;
            two_count--;
        } 
        temp = temp->next;
    }
    return head;
}
//if data replacement is not allowed 
void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}
Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr!=NULL){
        int val = curr->data;
        if(val == 0){
            insertAtTail(zeroTail,curr);
        }else if(val == 1){
            insertAtTail(oneTail,curr);
        }else if(val == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    //merge 3 sublist
    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next= NULL;
    head = zeroHead->next;
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    return head;
}
