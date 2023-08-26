class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int prev = INT_MIN;
        int count = 0;
        for(auto v : pairs) {
            if(v[0] > prev) {
                count++;
                prev = v[1];
            }
        }
        return count;
    }
};