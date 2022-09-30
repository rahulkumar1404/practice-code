/*
https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int count = 0;
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        for(int i = 0;i<nums.size();i++){
            int b = target - nums[i];
            if(m[b] && i!=m[b]){
                ans.push_back(i);
                ans.push_back(m[b]);
                break;
            }
        }
        return ans;
    }
};
