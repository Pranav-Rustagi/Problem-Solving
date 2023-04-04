//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int i = 0, j = str.size() - 1, count = 0;
    while(i <= j) {
        char ch = str[i];
        while(i <= j && str[j] == ch) {
            j--;
        }
        while(i <= j && str[i] == ch) {
            i++;
        }
        ++count;
    }
    return count;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends