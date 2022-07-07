#include <iostream>
#include<stack>
#include<queue>
using namespace std;
void queuedisplay(queue<int> q){
    cout<<"all elements in queue  "<<endl;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        cout<<" "<<val<<" ";
    }
    cout<<endl;
}
void stackdisplay(stack<int> s){
    if(s.empty()){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<"all elements in stack  "<<endl;
    while(!s.empty()){
        int val = s.top();
        s.pop();
        cout<<" "<<val<<" ";
    }
    cout<<endl;
}
void convertQueueToStack(std::queue<int> &q,std::stack<int> &s){
    
    int n = q.size() / 2;
    while(n--){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
}
void convertStackToQueue(std::queue<int> &q,std::stack<int> &s){
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
}

void queueInterchange(std::queue<int> &q){
    int n = q.size() / 2;
    while(n--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
}
void interleaveFirstHalfQueueWithSecondHalf(std::queue<int> &q,std::stack<int> &s){
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main()
{
    std::queue<int> q;
    std::stack<int> s;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    queuedisplay(q);
    convertQueueToStack(q,s);
    queuedisplay(q);
    stackdisplay(s);
    
    convertStackToQueue(q,s);
    queuedisplay(q);
    stackdisplay(s);
    
    queueInterchange(q);
    queuedisplay(q);
    stackdisplay(s);
    convertQueueToStack(q,s);
    queuedisplay(q);
    stackdisplay(s);
    
    interleaveFirstHalfQueueWithSecondHalf(q,s);
    queuedisplay(q);
    stackdisplay(s);
    
    return 0;
}
/*output
all elements in queue  
 11  12  13  14  15  16  17  18 
all elements in queue  
 15  16  17  18 
all elements in stack  
 14  13  12  11 
all elements in queue  
 15  16  17  18  14  13  12  11 
stack is empty
all elements in queue  
 14  13  12  11  15  16  17  18 
stack is empty
all elements in queue  
 15  16  17  18 
all elements in stack  
 11  12  13  14 
all elements in queue  
 11  15  12  16  13  17  14  18 
stack is empty
*/
