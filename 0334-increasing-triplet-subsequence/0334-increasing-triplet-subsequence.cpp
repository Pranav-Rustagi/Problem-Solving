class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1 = INT_MAX, max2 = INT_MAX;
        for(int& el : nums) {
            if(el <= max1)
                max1 = el;
            else if(el <= max2)
                max2 = el;
            else
                return true;
        }
        
        return false;
    }
};