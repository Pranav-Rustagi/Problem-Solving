class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        m[0] = 1;
        
        int res = 0, sum = 0;
        for(int el : nums) {
            sum += el;
            res += m[sum - goal];
            m[sum]++;
        }
        
        return res;
    }
};