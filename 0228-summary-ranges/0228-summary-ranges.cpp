class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        for(int i = 0 ; i < nums.size() ; ++i) {
            int j = i;
            while(j + 1 < nums.size() && (long long)(nums[j + 1]) - nums[j] == 1)
                ++j;
            v.push_back(to_string(nums[i]));
            if(i != j) {
                v.back() += "->" + to_string(nums[j]);
                i = j;
            }
        }
        
        return v;
    }
};