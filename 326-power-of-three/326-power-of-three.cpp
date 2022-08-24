class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        return int(pow(3, floor(log(INT_MAX) / log(3)))) % n == 0;
    }
};