class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        int count = 0;
        while(n) {
            res.push_back(n%10 + '0');
            n /= 10;
            if((++count % 3) == 0)
                res.push_back('.');
        }
        if(res.back() == '.') res.pop_back();
        reverse(res.begin(), res.end());
        return res.size() ? res : "0";
    }
};