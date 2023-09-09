class Solution {
public:
    int solve(vector<int>& nums, int target, int dp[], int sum = 0) {
        if(sum == target)   return 1;
        if(sum > target)    return 0;
        if(dp[sum] != -1)   return dp[sum];
        int ways = 0;
        for(int el : nums) {
            ways += solve(nums, target, dp, sum + el);
        }
        return dp[sum] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, dp);
    }
};