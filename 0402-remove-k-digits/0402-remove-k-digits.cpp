class Solution {
public:
    string removeKdigits(string num, int k) {
        int sz = num.size();
        if (k == sz) {
            return "0";
        }
        
        string res;
        for(char ch : num) {
            while(!res.empty() && res.back() > ch && k > 0) {
                res.pop_back();
                k--;
            }
            
            res.push_back(ch);
        }
        
        while(k > 0) {
            res.pop_back();
            k--;
        }
        
        int i = 0;
        while(i < res.size() && res[i] == '0') {
            i++;
        }
        
        res = res.substr(i);
        
        if(res.empty()) {
            res.push_back('0');
        }
        
        return res;
    }
};