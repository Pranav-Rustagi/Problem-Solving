//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    long long ans = 0;
    int i = 0;
    for(int i = 0 ; i < n ; i++) {
        long long temp = 0;
        int j = i;
        while(j < n && arr[j] == 0) {
            j++;
        }
        
        if(j > i) {
            temp = j - i;
            ans += (temp * (temp + 1)) >> 1;
            i = j - 1;
        }
    }
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends