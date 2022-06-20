#include <iostream>

using namespace std;
class Node{
  public:
  int data;
  Node* next;
  
  Node(int d){
      this->data = d;
      this->next = NULL;
  }
  ~Node(){
      int value  = this->data;
      if(this->next!=NULL){
          delete next;
          next = NULL;
      }
      std::cout << "memory is free for node with data " << value << std::endl;
  }
};
void print(Node* &tail){
    Node* temp = tail;
    if(tail==NULL){
        cout<<" List is Empty "<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail= tail->next;
    }while(temp != tail);
    cout<<endl;
}
void insertNode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        Node* curr = tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void Delete(Node* &tail,int value){
    if(tail==NULL){
        std::cout << "List is Empty" << std::endl;
        return;
    }else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        if(curr==prev){
            tail = NULL;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node* tail = NULL;
    insertNode(tail,4,3);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    insertNode(tail,4,5);
    print(tail);
    insertNode(tail,3,1);
    print(tail);
    Delete(tail,3);
    print(tail);
    return 0;
}
/*output
3 
3 4 
3 4 5 
3 1 4 5 
memory is free for node with data 3
5 1 4 
*/
