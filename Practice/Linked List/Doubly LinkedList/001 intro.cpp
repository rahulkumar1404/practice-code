/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
//LinkedList class
class Node{
  public:
  int data;
  Node* prev;
  Node* next;
  
  //constructor
  Node(int d){
      this->data = d;
      this->prev = NULL;
      this->next = NULL;
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
void print(Node* &head,Node* &tail){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    cout<<"length of LinkedList "<< len<<endl;
    cout<<endl;
    std::cout << "Head At Position " << head->data << std::endl;
    std::cout << "Tail At Position " << tail->data << std::endl;
    cout<<endl;

}
void insertAtHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        
    }
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position==1){
        insertAtHead(tail,head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,head,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next =temp->next;
    temp->next->prev = nodeToInsert;
    temp->next =  nodeToInsert;
    nodeToInsert = temp;
}
//deleting
//deletting of a node by using position
void Delete(Node* &head,int position){
    //deletting for first position
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    
    Node* head = NULL;
    Node* tail = NULL;
    cout<<"insertAtHead "<<endl;
    insertAtHead(tail,head,11);

    print(head,tail);
    cout<<"insertAtTail "<<endl;
    insertAtTail(tail,head,9);

    print(head,tail);
    cout<<"insertAtPosition "<<endl;
    insertAtPosition(tail,head,2,10);
    print(head,tail);
    
    cout<<"deletting shuru hogaya boss"<<endl;
    Delete(head,2);
    print(head,tail);
    return 0;
}

/*output
insertAtHead 
11 
length of LinkedList 1

Head At Position 11
Tail At Position 11

insertAtTail 
11 9 
length of LinkedList 2

Head At Position 11
Tail At Position 9

insertAtPosition 
11 10 9 
length of LinkedList 3

Head At Position 11
Tail At Position 9

deletting shuru hogaya boss
Memory is free for node with data10
11 9 
length of LinkedList 2

Head At Position 11
Tail At Position 9

*/
