/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums[0] < nums.back()) return nums[0];
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        int mini = INT_MAX;
        while(s<=e){
            if(nums[mid]>= nums[0]){
                s = mid +1;
            }else {
                mini = min(mini,nums[mid]);
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return mini;
    }
};
