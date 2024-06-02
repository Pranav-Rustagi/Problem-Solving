class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0, lim = n >> 1 ; i < lim ; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};