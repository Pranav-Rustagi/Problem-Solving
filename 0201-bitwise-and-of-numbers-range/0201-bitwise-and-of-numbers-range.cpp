class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) {
            return 0;
        }
        
        int res = 0, diff = right - left + 1;
        for(int i = 0 ; i < 32 ; i++) {
            int cur = (1 << i);
            if(diff <= cur && (left & cur) && (right & cur)) {
                res |= cur;
            }
        }
        
        return res;
    }
};