class Solution {
public:
    int solve(string w, unordered_map<string, int>& m) {
        if(m[w] == -1) {
            m[w] = 1;
            for(int i = 0 ; i < w.size() ; i++) {
                string nw = w.substr(0, i) + w.substr(i + 1);
                if(m.count(nw)) {
                    m[w] = max(m[w], 1 + solve(nw, m));
                }
            }
        }
        return m[w];
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        for(string& w : words) {
            m[w] = -1;
        }

        int res = 0;
        for(string & w : words) {
            res = max(res, solve(w, m));
        }
        return res;
    }
};