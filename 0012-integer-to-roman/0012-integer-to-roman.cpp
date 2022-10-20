class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> romans = {
            { "M", 1000 },
            { "CM", 900 },
            { "D", 500 },
            { "CD", 400 },
            { "C", 100 },
            { "XC", 90 },
            { "L", 50 },
            { "XL", 40 },
            { "X", 10 },
            { "IX", 9 },
            { "V", 5 },
            { "IV", 4 },
            { "I", 1 }
        };
        
        string romanStr;
        int i = 0;
        while(i < romans.size()) {
            if(num >= romans[i].second) {
                romanStr += romans[i].first;
                num -= romans[i].second;
            } else {
                ++i;
            }
        }
        
        return romanStr;
    }
};