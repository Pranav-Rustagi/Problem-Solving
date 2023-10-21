class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MIN;
        priority_queue<pair<int, int>> pq;

        for(int i = n - 1 ; i >= 0 ; i--) {
            while(!pq.empty() && pq.top().second - i > k) {
                pq.pop();
            }

            int cur = nums[i] + max(0, pq.empty() ? 0 : pq.top().first);
            res = max(res, cur);
            pq.push({ cur, i });
        }

        return res;
    }
};