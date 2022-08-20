class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<vector<int>> arr;
        for(int i = 0 ; i < nums.size() ; ++i) {
            if(arr.size() == 0 || arr.back().back() < nums[i] - 1 || arr.back().back() == nums[i])
                arr.push_back({ nums[i] });
            else {
                for(int j = arr.size() - 1 ; j >= 0 && i < nums.size() && arr[j].back() + 1 == nums[i] ; --j, ++i) {
                    arr[j].push_back(nums[i]);
                }
                --i;
            }
        }
        
        for(auto & v : arr)
            if(v.size() < 3)
                return false;
        return true;
    }
};
