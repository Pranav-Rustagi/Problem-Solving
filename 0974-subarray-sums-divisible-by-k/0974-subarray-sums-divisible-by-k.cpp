class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, res = 0, addr = k * 10000;
        m[0] = 1;
        
        for(int num : nums) {
            sum = (addr + sum + num) % k;
            cout << sum << " ";
            res += m[sum];
            m[sum]++;
        }
        
        return res; 
    }
};