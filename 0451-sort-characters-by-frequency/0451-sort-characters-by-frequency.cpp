class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v(62, pair<char, int>());
        for(int i = 0 ; i < 26 ; ++i) {
            v[i].first = 'a' + i;
            v[26 + i].first = 'A' + i;
            if(52 + i < 62)
                v[52 + i].first = '0' + i;
        }
        
        for(char ch : s) {
            if(ch >= 'a') {
                v[ch - 'a'].second++;
            } else if (ch <= '9') {
                v[52 + ch - '0'].second++;
            } else {
                v[26 + ch - 'A'].second++;
            }
        }
        
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        
        for(int iter = 0, i = 0 ; i < 62 ; ++i) {
            while(v[i].second--) {
                s[iter++] = v[i].first;
            }
        }
        
        return s;
    }
};