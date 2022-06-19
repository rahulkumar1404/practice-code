/*
creation
insert
traverse
delete
*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node*  next;
    //constructor
    Node(int data){
        this->data = data;
        this-> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"Memory is free for node with data" << value<<endl;
    }
};
// printing
void print (Node* &head){
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
        cnt++;
    }
    cout<<endl;
    cout << "total number of nodes " << cnt<<endl;
}
// inserting
void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail =  tail->next;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position==1){
        insertAthead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
//deletting of a node by using position
void Delete(Node* &head,int position){
    //deletting for first position
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    //deletting for middle or last position
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt <position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node*  node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    std::cout << "insertAthead " << std::endl;
    
    print(head);
    insertAthead(head,11);
    print(head);
    insertAthead(head,12);
    print(head);
    insertAthead(head,13);
    print(head);
    insertAthead(head,14);
    print(head);
    insertAthead(head,15);
    print(head);
    
    cout<<endl;
    cout<<endl;
    std::cout << "insertAtTail " << std::endl;
    
    print(head);
    insertAtTail(tail,11);
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,13);
    print(head);
    insertAtTail(tail,14);
    print(head);
    insertAtTail(tail,25);
    print(head);
    cout<<endl;
    cout<<endl;
    std::cout << "insertAtPosition " << std::endl;
    cout<<endl;
    print(head);
    insertAtPosition(tail,head,12,60);
    print(head);
    
    cout<<endl;
    cout<<endl;
    std::cout << "Head At Position " << head->data << std::endl;
    std::cout << "Tail At Position " << tail->data << std::endl;
    cout<<endl;
    
    cout<<endl;
    cout<<endl;
    std::cout << "deletting by Position " << std::endl;
    cout<<endl;
    Delete(head,11);
    print(head);
    return 0;
}

/*
output

insertAthead 
10 
total number of nodes 2
11 10 
total number of nodes 3
12 11 10 
total number of nodes 4
13 12 11 10 
total number of nodes 5
14 13 12 11 10 
total number of nodes 6
15 14 13 12 11 10 
total number of nodes 7


insertAtTail 
15 14 13 12 11 10 
total number of nodes 7
15 14 13 12 11 10 11 
total number of nodes 8
15 14 13 12 11 10 11 12 
total number of nodes 9
15 14 13 12 11 10 11 12 13 
total number of nodes 10
15 14 13 12 11 10 11 12 13 14 
total number of nodes 11
15 14 13 12 11 10 11 12 13 14 25 
total number of nodes 12


insertAtPosition 

15 14 13 12 11 10 11 12 13 14 25 
total number of nodes 12
15 14 13 12 11 10 11 12 13 14 25 60 
total number of nodes 13


Head At Position 15
Tail At Position 60



deletting by Position 

Memory is free for node with data25
15 14 13 12 11 10 11 12 13 14 60 
total number of nodes 12

*/
