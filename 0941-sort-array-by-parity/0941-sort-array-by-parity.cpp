class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j) {
            if((nums[i] & 1) == 0) {
                i++;
            } else if(nums[j] & 1) {
                j--;
            } else {
                swap(nums[i++], nums[j--]);
            }
        }

        return nums;
    }
};