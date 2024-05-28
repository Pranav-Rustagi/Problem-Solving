class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, i = 0, j = 0, n = s.size(), curcost = 0;
        while(j < n) {
            curcost += abs(s[j] - t[j]);
            
            j++;
            
            while(curcost > maxCost) {
                curcost -= abs(s[i] - t[i]);
                i++;
            }
            
            res = max(res, j - i);
        }
        
        return res;
    }
};