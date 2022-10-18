class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        queue<int> count, chs;
        for(int i = 0 ; i < prev.size() ; ++i) {
            if(chs.empty() || chs.back() != prev[i] - '0') {
                chs.push(prev[i] - '0');
                count.push(1);
            } else {
                ++count.back();
            }
        }
        
        string res;
        while(!chs.empty()) {
            res += to_string(count.front());
            res.push_back(chs.front() + '0');
            count.pop();
            chs.pop();
        }
        
        return res;
    }
};