class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        for(int i = 0 ; i < s.size() ; ++i) {
            if(s[i] != ' ') {
                if(i == 0 || s[i - 1] == ' ')
                    v.push_back("");
                v.back().push_back(s[i]);
            }
        }
        
        reverse(v.begin(), v.end());
        string res = "";
        for(auto & st : v) {
            if(res.size())
                res.push_back(' ');
            res += st;
        }
        
        return res;
    }
};