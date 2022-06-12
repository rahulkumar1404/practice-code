// problem link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1;i<n;i++){
            if(nums[i-1]>nums[i]) count++;
        }
        if(nums[0]<nums[n-1]) count++;
        return count<=1;
    }
};
