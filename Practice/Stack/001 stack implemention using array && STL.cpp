#include <iostream>
#include<stack>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *arr;
        
        
    public:
        Stack(int s){
            this->size = s;
            top = -1;
            arr = new int[s];
        }
        void push(int ele){
            if(size - top > 1){
                top++;
                arr[top] = ele;
                cout<< arr[top]<<endl;
            }else{
                cout<<"Stack overflow"<<endl;
            }
        }
        void pop(){
            if(top>=0){
                cout<<"popped element  "<<arr[top]<<endl;
                top--;
                
            }else{
                cout<< "stack underflow"<<endl;
            }
        }
        bool empty(){
            if(top == -1){
                return true;
            }else {
                return false;
            }
        }
        void peek(){
            if(top>=0){
                cout<< arr[top]<<endl;
            }else{
                cout<<"stack is empty"<<endl;
            }
        }
    
};

int main()
{
    Stack stk(5);
    
    for(int i = 1;i<=5;i++){
        stk.push(i);
    }
    stk.pop();
    
    stk.peek();
    
    cout<<"stack creation using STL"<<endl;
    
    stack<int> s;
    //push operation
    s.push(2);
    s.push(3);
    //pop
    s.pop();
    cout << "Printing top element " << s.top() << endl;
    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }
    cout << "size of stack is " << s.size() << endl;

    
    return 0;
}
