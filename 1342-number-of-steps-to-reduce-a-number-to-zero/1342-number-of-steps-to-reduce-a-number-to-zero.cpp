class Solution {
public:
    int numberOfSteps(int num) {
        if(num)
            return 1 + numberOfSteps((num & 1) ? (num - 1) : (num >> 1));
        return 0;
    }
};