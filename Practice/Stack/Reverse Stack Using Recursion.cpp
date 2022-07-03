/*
https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
*/
void insertAtBottom(stack<int> &s,int num){
    //base case
    if(s.empty()){
        s.push(num);
        return ;
    }
    int ele = s.top();
    s.pop();
    insertAtBottom(s , num);
    s.push(ele);
}
void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()) return;
    int num = stack.top();
    stack.pop();
    //recursive call;
    reverseStack(stack);
    insertAtBottom(stack,num);
}
