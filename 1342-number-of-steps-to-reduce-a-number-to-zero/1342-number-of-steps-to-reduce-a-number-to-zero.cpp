class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while(num) {
            ++res;
            if(num & 1)
                --num;
            else
                num >>= 1;
        }
        return res;
    }
};