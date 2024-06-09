class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int m[k];
        memset(m, 0, sizeof(m));
        m[0] = 1;
        
        int sum = 0, res = 0;
        
        for(int num : nums) {
            sum = (((sum + num) % k) + k) % k;
            res += m[sum]++;
        }
        
        return res; 
    }
};