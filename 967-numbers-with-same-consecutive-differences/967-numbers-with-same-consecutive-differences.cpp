class Solution {
public:
    vector<int> r;
    
    void solve(int n, int& k, int acc) {
        if(n == 0) {
            r.push_back(acc);
        }
        else {
            int dig = acc % 10;
            if(dig + k <= 9)
                solve(n - 1, k, acc * 10 + dig + k);
            if(dig - k >= 0)
                solve(n - 1, k, acc * 10 + dig - k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1 ; i <= 9 ; ++i) {
            if(k) {
                solve(n - 1, k, i);
            }
            else {
                int dup = n, acc = 0;
                while(dup--)
                    acc = acc * 10 + i;
                r.push_back(acc);
            }
        }
        return r;
    }
};