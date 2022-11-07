class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0 ; i < 32 ; ++i) {
            int temp = 0;
            for(auto & el : nums) {
                temp += ((el >> i) & 1);
            }
            
            if(temp % 3)
                res |= (1 << i);
        }
        
        return res;
    }
};