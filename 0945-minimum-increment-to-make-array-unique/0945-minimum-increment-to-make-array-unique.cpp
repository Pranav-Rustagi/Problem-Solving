class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ind = 0, res = 0;
        for(int num : nums) {
            ind = max(ind, num);
            res += ind++ - num;
        }
        
        return res;
    }
};