class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int r = 0;
        for(int i = 0 ; i < nums.size() ; ++i) {
            if(nums[i]) {
                int j = i;
                while(j < nums.size() && nums[j])
                    ++j;
                r = max(r, j - i);
                i = j;
            }
        }
        
        return r;
    }
};