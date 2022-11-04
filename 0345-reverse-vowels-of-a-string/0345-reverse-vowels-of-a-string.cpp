class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> ms = { 'A', 'a', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
        while(i < j) {
            bool fi = ms.count(s[i]), fj = ms.count(s[j]);
            if(fi & fj) {
                swap(s[i++], s[j--]);
            }
            else {
                if(!fi)
                    ++i;
                if(!fj)
                    --j;
            }
        }
        
        return s;
    }
};