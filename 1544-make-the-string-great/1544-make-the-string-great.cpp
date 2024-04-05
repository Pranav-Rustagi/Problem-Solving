class Solution {
public:
    bool isMatch(char a, char b) {
        return abs(a - b) == 32;
    }
    
    string makeGood(string s) {
        int n = s.size();
        string res;
        
        for(char ch : s) {
            if(res.empty() || !isMatch(res.back(), ch)) {
                res.push_back(ch);
            } else {
                res.pop_back();
            }
        }
        
        return res;
    }
};