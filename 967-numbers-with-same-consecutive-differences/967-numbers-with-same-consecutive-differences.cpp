class Solution {
public:
    vector<int> r;
    
    void solve(int n, int k, int acc) {
        if(to_string(acc).size() == n) {
            r.push_back(acc);
        }
        else {
            int dig = acc % 10;
            if(dig + k <= 9)
                solve(n, k, acc * 10 + dig + k);
            if(k && dig - k >= 0)
                solve(n, k, acc * 10 + dig - k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1 ; i <= 9 ; ++i) {
            solve(n, k, i);
        }
        
        return r;
    }
};