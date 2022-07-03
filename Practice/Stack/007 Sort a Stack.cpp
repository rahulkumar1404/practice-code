/*
https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
*/
void sortedInsert(stack<int> &stack,int num){
    if(stack.empty() || (!stack.empty() && stack.top()< num)){
        stack.push(num);
        return;
    }
    int ele = stack.top();
    stack.pop();
    sortedInsert(stack,num);
    stack.push(ele);
    return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack,num);
}
