class Solution {
public:
    bool isUgly(int n) {
        int dup = n;
        while(n && !(n & 1)) {
            n >>= 1;
        }
        
        while(n && !(n % 3)) {
            n /= 3;
        }
        
        while(n && !(n % 5)) {
            n /= 5;
        }
        
        return (n == 1);
    }
};