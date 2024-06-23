class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minq, maxq;
        int n = nums.size(), res = 0;
        
        for(int i = 0, j = 0 ; j < n ; j++) {
            while(!minq.empty() && minq.back() > nums[j]) {
                minq.pop_back();
            }
            minq.push_back(nums[j]);
            
            while(!maxq.empty() && maxq.back() < nums[j]) {
                maxq.pop_back();
            }
            maxq.push_back(nums[j]);
            
            while(maxq.front() - minq.front() > limit) {
                if(minq.front() == nums[i]) {
                    minq.pop_front();
                }
                
                if(maxq.front() == nums[i]) {
                    maxq.pop_front();
                }
                
                i++;
            }
            
            res = max(res, j - i + 1);
        }
        
        return res;
    }
};