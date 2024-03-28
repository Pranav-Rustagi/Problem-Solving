class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> freq;
        int n = nums.size(), i = 0, j = 0, res = 0;
        
        while(j < n) {
            freq[nums[j]]++;
            while(freq[nums[j]] > k) {
                freq[nums[i++]]--;
            }
            
            res = max(res, j - i + 1);
            j++;
        }
        
        return res;
    }
};