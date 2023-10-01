class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            int j = i + 1;
            while(j < n && s[j] != ' ') {
                j++;
            }

            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};