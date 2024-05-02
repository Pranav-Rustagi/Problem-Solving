class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        // Set to store seen elements
        unordered_set<int> seen; 

        for (int num : nums) { 
            const int abs_num = abs(num);

            // If the absolute value is greater than current max and its negation is in the set
            if (abs_num > ans && seen.contains(-num)) 
                ans = abs_num;
            seen.insert(num); // Insert current element into the set
        }
        return ans; 
    }
};