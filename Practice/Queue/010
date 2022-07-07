#include <iostream>

using namespace std;
class kQueue{
    private:
        int n,k;
        int* arr;
        int* next;
        int* front;
        int* rear;
        int freespot;
    public:
        kQueue(int n,int k){
            this -> n = n;
            this -> k = k;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];
            for(int i = 0;i<k;i++){
                front[i] = rear[i] = -1;
            }
            for(int i = 0;i<n;i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
            freespot = 0;
        }
        void push(int data,int qn){
            if(freespot == -1){
                std::cout << "Queue is full / Queue overflow " << std::endl;
                return;
            }
            //find index where to insert
            int index = freespot;
            //update freespot
            freespot = next[index];
            //check whether the element will be stored in first position or not
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }else{
                //link to the next element
                next[rear[qn-1]] = index;
            }
            //update next
            next[index] = -1;
            //update rear
            rear[qn-1] = index;
            //push element 
            arr[index] = data;
        }
        void pop(int qn){
            //check array is empty or not
            if(front[qn-1] == -1){
                cout<<"Queue is empty / Queue is Underflow"<<endl;
                return ;
            }
            //find index
            int index = front[qn-1];
            //front ko aage badho
            front[qn-1] = next[index];
            //freespot ko mange karo
            next[index] = freespot;
            freespot = index;
            int ans = arr[index];
            arr[index] = -1;
            cout<<ans<<endl;
        }
};
int main()
{
    int n = 9;
    int k = 3;
    kQueue q(n,k);
    q.push(11,1);
    q.push(12,1);
    q.push(13,1);
    q.push(14,2);
    q.push(15,2);
    q.push(16,2);
    q.push(17,3);
    q.push(18,3);
    q.push(19,3);
    q.pop(1);
    q.pop(2);
    q.pop(3);
    q.pop(1);
    q.pop(2);
    q.pop(3);
    q.pop(1);
    q.pop(2);
    q.pop(3);
    q.pop(1);
    q.pop(2);
    q.pop(3);
    
    return 0;
}
/*
11
14
17
12
15
18
13
16
19
Queue is empty / Queue is Underflow
Queue is empty / Queue is Underflow
Queue is empty / Queue is Underflow
*/
