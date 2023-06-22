//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fv = 0, tn = 0, tt = 0, ct;
        
        for(int bill : bills) {
            if(bill == 5)
                fv++;
            else if(bill == 10)
                tn++;
            else
                tt++;
                
            bill -= 5;
            
            ct = min(bill / 20, tt);
            tt -= ct;
            bill -= ct * 20;
            
            ct = min(bill / 10, tn);
            tn -= ct;
            bill -= ct * 10;
            
            ct = min(bill / 5, fv);
            fv -= ct;
            bill -= ct * 5;
            
            if(bill != 0)
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends