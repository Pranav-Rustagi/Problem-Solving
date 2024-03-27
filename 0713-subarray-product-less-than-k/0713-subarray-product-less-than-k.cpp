class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) {
            return 0;
        }
        
        int i = 0, j = 0, prod = 1, n = nums.size(), res = 0;
        while(j < n) {
            prod *= nums[j++];
            while(prod >= k) {
                prod /= nums[i++];
            }
            res += j - i;
        }
        
        return res;
    }
};