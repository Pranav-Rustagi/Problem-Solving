class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int lim = min(int(nums.size()), k + 1);
        for(int i = 0 ; i < lim ; ++i) {
            if(++m[nums[i]] > 1)
                return true;
        }
        
        for(int i = lim ; i < nums.size() ; ++i) {
            --m[nums[i - lim]];
            if(++m[nums[i]] > 1)
                return true;
        }
        
        return false;
    }
};