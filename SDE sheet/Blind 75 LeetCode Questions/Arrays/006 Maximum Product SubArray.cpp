/*
https://leetcode.com/problems/maximum-product-subarray/
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxPro = ans;
        int minPro = ans;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxPro,minPro);
            }
            maxPro = max(nums[i],maxPro*nums[i]);
            minPro = min(nums[i],minPro*nums[i]);
            ans = max(ans,maxPro);
        }
        return ans;
    }
};
