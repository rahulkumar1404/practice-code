/*
https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include<bits/stdc++.h>

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for(auto i : arr){
        count[i]++;
        maxFreq = max(maxFreq,count[i]);
    }
    for(auto i : arr){
        if(maxFreq == count[i])
        {    
            maxAns = i;
            break;
        }
    }
    return maxAns;
}
