class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iter1 = 0, iter2 = 1;
        while(iter2 < nums.size()) {
            if(nums[iter2] == nums[iter1])
                ++iter2;
            else
                nums[++iter1] = nums[iter2++];
        }
        return iter1 + 1;
    }
};