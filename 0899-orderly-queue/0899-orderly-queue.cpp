class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = s;
        if(k == 1) {
            for(int i = 1 ; i < s.size() ; ++i) {
                res = min(res, s.substr(i, s.size()) + s.substr(0, i));
            }
        } else {
            sort(res.begin(), res.end());
        }
        return res;
    }
};