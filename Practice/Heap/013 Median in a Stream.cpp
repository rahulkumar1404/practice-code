/*
https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include<bits/stdc++.h>
int signum(int a,int b){
    if(a==b)
        return 0;
    if(a>b)
        return 1;
    else
        return -1;
}
void callMedian(int ele,priority_queue< int>& maxi,priority_queue< int , vector<int> ,greater<int> >& mini,int& median ){
    switch(signum(maxi.size() , mini.size()))
    {
        case 0 : 
            if(ele > median){
                mini.push(ele);
                median = mini.top();
            }else{
                maxi.push(ele);
                median = maxi.top();
            }
            break;
        case 1 :
            if(ele > median){
                mini.push(ele);
                median = ( mini.top() + maxi.top() ) / 2;
            }else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(ele);
                median = ( mini.top() + maxi.top() ) / 2;
            }
            break;
        case -1 :
            
            if(ele > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(ele);
                median = ( mini.top() + maxi.top() ) / 2;
            }else{
                maxi.push(ele);
                median = ( mini.top() + maxi.top() ) / 2;
            }
            break;
            
    }
}
vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue< int , vector<int> ,greater<int> > minHeap;
    priority_queue< int> maxHeap;
    int median  = 0;
    for(int i = 0;i<n;i++){
        callMedian( arr[i] , maxHeap , minHeap , median );
        ans.push_back(median);
    }
    return ans;
    
    
}
