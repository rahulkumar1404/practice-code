/*
https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
*/
void solve(stack<int>& s,int x){
    //base case
    if(s.empty()){
        s.push(x);
        return ;
    }
    int ele = s.top();
    s.pop();
    solve(s,x);
    s.push(ele);
    return;
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}
