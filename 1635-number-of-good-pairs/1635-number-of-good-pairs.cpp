class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[100] = {0};
        for(int el : nums) {
            arr[el - 1]++;
        }

        int res = 0;
        for(int i = 0 ; i < 100 ; i++) {
            if(arr[i] > 1) {
                res += (arr[i] * (arr[i] - 1)) >> 1;
            }
        }
        return res;
    }
};