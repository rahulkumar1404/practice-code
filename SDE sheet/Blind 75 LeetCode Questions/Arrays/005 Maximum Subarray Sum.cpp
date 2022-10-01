/*
https://leetcode.com/problems/maximum-subarray/submissions/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(auto i : nums){
            currSum = max(currSum+i,i);
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};
