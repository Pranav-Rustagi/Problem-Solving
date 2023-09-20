class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0, res = INT_MAX, n = nums.size();

        if(total == x) {
            return n;
        }
        
        bool f = false;

        unordered_map<int, int> m;
        m[0] = -1;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            int req = x - total + sum;

            if(m.count(req)) {
                res = min(res, m[req] + n - i);
                f = true;
            }
            
            m[sum] = i;
        }
        return f ? res : -1;
    }
};