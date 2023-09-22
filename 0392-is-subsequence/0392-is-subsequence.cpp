class Solution {
public:
    bool isSubsequence(string s, string t) {
        int iter1 = 0, iter2 = 0;
        int n1 = s.size(), n2 = t.size();
        while(iter1 < n1 && iter2 < n2) {
            if(s[iter1] == t[iter2]) {
                iter1++;
            }
            iter2++;
        }

        return iter1 == n1;
    }
};