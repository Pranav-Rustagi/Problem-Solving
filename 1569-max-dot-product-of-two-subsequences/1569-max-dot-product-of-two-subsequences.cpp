class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int dp[500][500], int n1, int n2, int i1 = 0, int i2 = 0) {
        if(i1 == n1 || i2 == n2) {
            return INT_MIN;
        }

        if(dp[i1][i2] != -1) {
            return dp[i1][i2];
        }


        int curRes = nums1[i1] * nums2[i2] + max(0, solve(nums1, nums2, dp, n1, n2, i1 + 1, i2 + 1));
        int postRes1 = solve(nums1, nums2, dp, n1, n2, i1 + 1, i2);
        int postRes2 = solve(nums1, nums2, dp, n1, n2, i1, i2 + 1);
        return dp[i1][i2] = max(curRes, max(postRes1, postRes2));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int dp[500][500];
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, dp, n1, n2);
    }
};