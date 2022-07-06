/*
https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0
*/
class CircularQueue{
    int *arr;
    int size;
    int front,rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool enqueue(int value){
        //to check queue is full or not
        if((front == 0)&&(rear == size-1) || (rear == (front-1)%(size-1))) {
            return false;
        }
        else if(front == -1){//first element to push
            front = rear = 0;
        }else if(rear == size - 1 && front !=0){
            //to maintain cyclic nature
            rear = 0;
        }else{//normal flow
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue(){
        //check queue is empty or not
        if(front == -1) return -1;
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){// single element is present
            front = rear = -1;
        }else if(front == size - 1){//to maintain cyclic nature
            front = 0;
        }
        else front++;//normal flow
        return ans;
    }
};
