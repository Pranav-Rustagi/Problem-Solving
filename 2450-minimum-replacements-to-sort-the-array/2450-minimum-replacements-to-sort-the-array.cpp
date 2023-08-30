class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(nums[i] > nums[i + 1]) {
                int temp = ceil(nums[i] / (nums[i + 1] + 0.0));
                count += temp - 1;
                nums[i] /= temp;
            }
        }
        return count;
    }
};