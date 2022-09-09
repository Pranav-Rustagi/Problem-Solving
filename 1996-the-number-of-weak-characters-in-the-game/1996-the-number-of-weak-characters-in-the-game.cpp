class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int res = 0, maxDefense = INT_MIN;
        sort(p.begin(), p.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        
        for(auto& v : p) {
            if(maxDefense > v[1])
                ++res;
            else
                maxDefense = v[1];
        }
        return res;
    }
};