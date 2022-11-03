class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for(string& s : words)
            ++m[s];
        
        int res = 0;
        bool hasOdd = false;
        for(auto & p : m) {
            if(p.first[0] < p.first[1]) {
                string opp = p.first;
                swap(opp[0], opp[1]);
                if(m.find(opp) != m.end())
                    res += (min(p.second, m[opp])) << 2;
            }
            else if(p.first[0] == p.first[1]) {
                if(p.second & 1)
                    hasOdd = true;
                res += (p.second - (p.second & 1)) << 1;
            }
        }
        
        if(hasOdd)
            res += 2;
        return res;
    }
};