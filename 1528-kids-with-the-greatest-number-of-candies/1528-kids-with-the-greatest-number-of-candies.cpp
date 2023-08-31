class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n);
        int maxel = *max_element(candies.begin(), candies.end());
        for(int i = 0 ; i < n ; i++)
            res[i] = candies[i] + extraCandies >= maxel;
        return res;
    }
};