class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(i < s.size()) {
            while(j < s.size() && s[j] != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j);
            j = i = j + 1;
        }
        
        return s;
    }
};