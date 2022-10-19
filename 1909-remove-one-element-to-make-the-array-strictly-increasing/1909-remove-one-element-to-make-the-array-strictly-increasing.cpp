class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; ++i) {
            bool sorted = true;
            for(int j = 1 ; j < i ; ++j) {
                if(nums[j - 1] >= nums[j]) {
                    sorted = false;
                    break;
                }
            }
            
            if(sorted == false)
                continue;
            
            for(int j = i + 2 ; j < nums.size() ; ++j) {
                if(nums[j - 1] >= nums[j]) {
                    sorted = false;
                    break;
                }
            }
            
            if(sorted == false || (i - 1 >= 0 && i + 1 < nums.size() && nums[i - 1] >= nums[i + 1]))
                continue;
            return true;
        }
        
        return false;
    }
};