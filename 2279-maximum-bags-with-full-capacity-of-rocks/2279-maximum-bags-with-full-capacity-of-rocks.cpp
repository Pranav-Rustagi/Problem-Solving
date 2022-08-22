class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int res = 0;
        for(int i = 0 ; i < rocks.size() ; ++i) {
            capacity[i] -= rocks[i];
        }
        
        sort(capacity.begin(), capacity.end());
        
        for(int& c : capacity) {
            if(c > additionalRocks)
                break;
            ++res;
            additionalRocks -= c;
        }
        
        return res;
    }
};