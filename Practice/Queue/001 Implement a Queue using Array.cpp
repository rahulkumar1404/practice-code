/*
https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0
*/
class Queue {
private:
    int size,qfront,rear;
    int* arr;
public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == rear) return -1;
        int ans = arr[qfront];
        qfront++;
        if(qfront == rear){
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        // Implement the front() function
        if(qfront == rear) return -1;
        return arr[qfront]; 
    }
};
