class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 0 ; i < nums.size() - 2 ; ++i) {
            int req = target - nums[i];
            for(int p1 = i + 1, p2 = nums.size() - 1 ; p1 < p2 ; ) {
                int temp = nums[i] + nums[p1] + nums[p2];
                if(res == INT_MAX || abs(res - target) > abs(temp - target))
                    res = temp;
                if(req <= nums[p1] + nums[p2])
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