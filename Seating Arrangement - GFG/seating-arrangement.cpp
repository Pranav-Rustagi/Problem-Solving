//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        for(int i = 0 ; i < m ; i++) {
            if(seats[i] == 1) {
                continue;
            }
            
            int ct = 1;
            int j = i + 1;
            while(j < m && seats[j] == 0) {
                j++;
                ct++;
            }
            
            if(i > 0 && seats[i - 1] == 1) {
                ct--;
            }
            
            if(j < m && seats[j] == 1) {
                ct--;
            }
            n -= (ct + 1) >> 1;
            if(n <= 0) {
                return true;
            }
            i = j;
        }
        return n <= 0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends