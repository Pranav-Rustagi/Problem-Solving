class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size() + 1, 0), res(2, -1);
        
        for(int& el : nums)
            ++v[el];
        
        for(int i = 1 ; i < v.size() ; ++i) {
            if(v[i] == 2) {
                res[0] = i;
            } else if(v[i] == 0) {
                res[1] = i;
            }
            
            if(min(res[0], res[1]) != -1)
                break;
        }
        
        return res;
    }
};