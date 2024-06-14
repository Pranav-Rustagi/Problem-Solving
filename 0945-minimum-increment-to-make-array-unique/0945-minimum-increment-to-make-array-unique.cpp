class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        bool hash[200001] = {false};
        sort(nums.begin(), nums.end());
        
        int ind = nums[0], res = 0;
        for(int num : nums) {
            ind = max(ind, num);
            while(hash[ind]) {
                ind++;
            }
            
            hash[ind] = true;
            res += ind++ - num;
        }
        
        return res;
    }
};