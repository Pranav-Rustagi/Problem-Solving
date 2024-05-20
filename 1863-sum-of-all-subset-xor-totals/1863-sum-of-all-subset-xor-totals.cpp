class Solution {
public:
    void solve(vector<int>& nums, int& sum, int ind = 0, int subsettotal = 0) {
        if(ind == nums.size()) {
            sum += subsettotal;
            return;
        }
        
        solve(nums, sum, ind + 1, subsettotal);
        solve(nums, sum, ind + 1, subsettotal ^ nums[ind]);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        solve(nums, sum);
        return sum;
    }
};