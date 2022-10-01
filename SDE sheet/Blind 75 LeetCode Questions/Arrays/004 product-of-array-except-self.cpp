/*
https://leetcode.com/problems/product-of-array-except-self/submissions/
*/
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pro = 1;
        int req ;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }else 
                pro *=nums[i];
        }
        if(count>=2) return ans;
        for(int i = 0;i<nums.size();i++){
            if(count == 0 && nums[i] != 0){
                req = pro / nums[i];  
                ans[i] = req;
            }else if(count != 0 && nums[i]==0){
                req = pro;  
                ans[i] = req;
            }else ans[i] = 0;
        }
        return ans;
    }
};
