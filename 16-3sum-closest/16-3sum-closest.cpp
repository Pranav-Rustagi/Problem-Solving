class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, minDiff = INT_MAX;
        
        for(int i = 0 ; i < nums.size() - 2 ; ++i) {
            for(int p1 = i + 1, p2 = nums.size() - 1 ; p1 < p2 ; ) {
                int sum = nums[i] + nums[p1] + nums[p2];
                int diff = abs(sum - target);
                
                if(diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                
                if(sum > target)
                    --p2;
                else
                    ++p1;
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        
        return res;
    }
};