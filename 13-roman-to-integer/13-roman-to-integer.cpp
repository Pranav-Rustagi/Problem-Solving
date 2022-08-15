class Solution {
public:
    int getNum(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    
    int getPrevChar(char ch) {
        switch(ch) {
            case 'V': return 'I';
            case 'X': return 'I';
            case 'L': return 'X';
            case 'C': return 'X';
            case 'D': return 'C';
            case 'M': return 'C';
        }
        return '\0';
    }
    
    int romanToInt(string s) {
        int res = 0;
        
        while(!s.empty()) {
            char prev = getPrevChar(s.back());
            res += getNum(s.back());
            s.pop_back();
            if(!s.empty() && s.back() == prev) {
                s.pop_back();
                res -= getNum(prev);
            }
        }
        
        return res;
    }
};