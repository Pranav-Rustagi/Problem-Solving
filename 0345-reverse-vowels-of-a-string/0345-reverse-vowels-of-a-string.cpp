class Solution {
public:
    bool check(char& ch) {
        switch(ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        for(int i = 0, j = s.size() - 1 ; i < j ; ) {
            if(check(s[i])) {
                if(check(s[j])) {
                    swap(s[i++], s[j--]);
                } else {
                    --j;
                }
            } else {
                ++i;
            }
        }
        
        return s;
    }
};