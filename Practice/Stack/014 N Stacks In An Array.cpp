/*
https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
*/
class NStack
{
private: 
    int *arr;
    int s;
    int n;
    int *top;
    int *next;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        for(int i = 0;i<n;i++) {
            top[i] = -1;
        }
        for(int i = 0;i<s;i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
        freespot = 0;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1){
            return false;
        }
        //find index
        int index = freespot;
        //freespotupdate
        freespot = next[index];
        //insert element
        arr[index] = x;
        //next update
        next[index] = top[m-1];
        //top update
        top[m-1] = index;
        
        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        //check element is present or not
        if(top[m-1] == -1) {
            return -1;
        }
        //reverse push operation or procees push operation from bottom to top in reverse manner
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
