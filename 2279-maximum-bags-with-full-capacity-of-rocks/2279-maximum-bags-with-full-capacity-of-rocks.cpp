class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int res = 0;
        for(int i = 0 ; i < rocks.size() ; ++i) {
            capacity[i] -= rocks[i];
            if(capacity[i] == 0)
                ++res;
        }
        
        sort(capacity.begin(), capacity.end());
        for(int i = 0 ; i < capacity.size() ; ++i) {
            if(capacity[i]) {
                if(capacity[i] > additionalRocks)
                    break;
                ++res;
                additionalRocks -= capacity[i];
            }
        }
        
        return res;
    }
};