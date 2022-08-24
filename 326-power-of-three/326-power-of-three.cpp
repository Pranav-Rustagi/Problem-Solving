class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        double f = log10(n) / log10(3);
        return (f == ceil(f));
    }
};