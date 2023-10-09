class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ind = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(ind == nums.size() || nums[ind] != target) {
            return { -1, -1 };
        }

        return {
            ind,
            int(upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1
        };
    }
};