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
    
    int romanToInt(string s) {
        int res = 0;   
        while(!s.empty()) {
            int cur = getNum(s.back());
            res += cur;
            s.pop_back();
            if(!s.empty() && getNum(s.back()) < cur) {
                res -= getNum(s.back());
                s.pop_back();
            }
        }
        
        return res;
    }
};