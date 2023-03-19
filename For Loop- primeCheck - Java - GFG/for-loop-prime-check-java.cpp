//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

void isPrime(int n) {
    if(n == 1) {
        cout << "No\n";
        return;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        isPrime(n);
    }
    return 0;
}
// } Driver Code Ends