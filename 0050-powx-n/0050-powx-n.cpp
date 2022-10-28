class Solution {
public:
    double myPow(double x, long int n) {
        if(n < 0)
            x = 1 / x;
        n = abs(n);
        double r = 1;
        while(n) {
            if(n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        
        return r;
    }
};