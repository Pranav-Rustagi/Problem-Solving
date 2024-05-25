#define uss unordered_set<string>
#define vs vector<string> 

class Solution {
public:
    void solve(string s, uss words, string& str, vs& res, int ind = 0) {
        int n = s.size();
        
        if(ind == n) {
            res.push_back(str);
            return;
        }
        
        if(str.empty() == false) {
            str.push_back(' ');
        }
        
        string curw;
        for(int i = ind ; i < n ; i++) {
            curw.push_back(s[i]);
            str.push_back(s[i]);
            
            if(words.count(curw)) {
                solve(s, words, str, res, i + 1);
            }
        }
        
        for(int i = ind ; i < n ; i++) {
            str.pop_back();
        }
        
        if(str.empty() == false && str.back() == ' ') {
            str.pop_back();
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> res;
        string str;
        solve(s, words, str, res);
        return res;
    }
};