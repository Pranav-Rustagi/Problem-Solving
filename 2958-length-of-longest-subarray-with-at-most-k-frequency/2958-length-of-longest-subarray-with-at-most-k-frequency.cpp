class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, queue<int>> lo;
        
        int n = nums.size(), si = -1, res = 0;
        
        for(int i = 0 ; i < n ; i++) {
            lo[nums[i]].push(i);
            
            if(lo[nums[i]].size() > k) {
                si = max(si, lo[nums[i]].front());
                lo[nums[i]].pop();
            }
            
            res = max(res, i - si);
        }
        
        return res;
    }
};