/*
https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems
*/
#include<stack>
class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    private:
    stack<int> s;
    int mini;
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }else if(data < mini){
            int val = 2*data - mini;
            s.push(val);
            mini = data;
        }else s.push(data);
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()) return -1;
        int curr = s.top();
        s.pop();
        if(curr > mini) return curr;
        int prevMini = mini;
        int val = 2*mini - curr;
        mini = val;
        return prevMini;
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) return -1;
        int curr = s.top();
        if(curr<mini) return mini;
        else return curr;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
         if(s.empty()) return true;
        return false;
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) return -1;
        return mini;
    }  
};
