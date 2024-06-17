class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 1, addr = 3, lim = c / 2;
        while(i <= lim) {
            int j = sqrt(c - i);
            if(j * j == c - i) {
                return true;
            }
            i += addr;
            addr += 2;
        }
        
        int full = sqrt(c);
        if(full * full == c) {
            return true;
        }
        return false;
    }
};