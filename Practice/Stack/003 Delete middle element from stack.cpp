/*
https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
*/
void solve(stack<int>&inputStack,int count, int size){
    //base case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    int ele = inputStack.top();
    inputStack.pop();
    //recursive call
    solve(inputStack,count+1,size);
    //pushing ele
    inputStack.push(ele);
    return;
}
void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack,count,N);
}
