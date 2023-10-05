class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = -1, second = -1, fc = 0, sc = 0;
        for(int el : nums) {
            if(second != el && fc == 0) {
                first = el;
            } else if(first != el && sc == 0) {
                second = el;
            } 

            if(first == el) {
                fc++;
            } else if(second == el) {
                sc++;
            } else {
                fc--;
                sc--;
            }
        }


        int total = nums.size() / 3;
        int c1 = 0, c2 = 0;
        for(int el : nums) {
            if(first == el) {
                c1++;
            } else if(second == el) {
                c2++;
            }
        }

        vector<int> res;
        if(c1 > total) {
            res.push_back(first);
        }
        if(c2 > total) {
            res.push_back(second);
        }
        return res;
    }
};