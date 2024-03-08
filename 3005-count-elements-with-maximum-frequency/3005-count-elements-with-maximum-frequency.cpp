class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[100] = {0}, maxf = 0;
        for(int el : nums)
            maxf = max(maxf, ++arr[el - 1]);
        int res = 0;
        for(int i = 0 ; i < 100 ; i++)
            res += arr[i] == maxf ? maxf : 0;
        return res;
    }
};