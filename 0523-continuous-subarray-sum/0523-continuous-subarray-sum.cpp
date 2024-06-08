class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> m;
        
        m[0] = -1;
        
        for(int i = 0 ; i < n ; i++) {
            sum = (sum + nums[i]) % k;
            if(m.count(sum) == 0) {
                m[sum] = i;
            } else if (i - m[sum] >= 2) {
                return true;
            }
        }
        
        return false;
    }
};