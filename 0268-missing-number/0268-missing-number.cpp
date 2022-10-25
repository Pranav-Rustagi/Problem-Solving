class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size(), x = 0;
        for(auto & el : nums)
            x ^= el;
        while(sz)
            x ^= sz--;
        return x;
    }
};