class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) {
            return false;
        }

        stack<int> s;

        int j = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(nums[i] < j) {
                return true;
            }

            while(!s.empty() && s.top() < nums[i]) {
                j = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }

        return false;
    }
};