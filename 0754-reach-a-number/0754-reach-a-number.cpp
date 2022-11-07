class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        for(int i = 1, sum = 0 ; true ; ++i) {
            sum += i;
            if(sum >= target && (sum - target) % 2 == 0) {
                return i;
            }
        }
        return 0;
    }
};