//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(long long num, long long X, int count) {
        if(count == 0)
            return num <= X ? num : INT_MIN;
            
        long long res = INT_MIN;
        long long count2 = count / 10;
        
        if(num) {
            int last = num % 10;
            if(last < 9)
                res = max(res, solve(num * 10 + last + 1, X, count2));
            if(last > 0)
                res = max(res, solve(num * 10 + last - 1, X, count2));
        } else {
            num = X / count;
            res = solve(num, X, count2);
            if(num - 1 > 0)
                res = max(res, solve(num - 1, X, count2));
            else
                res = max(res, solve(9, X, count2 / 10));
        }
        
        if(res > X)
            return INT_MIN;
        return res;
    }
    
    long long jumpingNums(long long X) {
        long long dup = X, count = 1;
        while(dup) {
            count *= 10;
            dup /= 10;
        }
        
        long long res = solve(0, X, count / 10);
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends