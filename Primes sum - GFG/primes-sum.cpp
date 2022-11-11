//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isPrime(int N) {
        if(N < 2)
            return false;
        else if(N < 4)
            return true;
        else if(N % 2 == 0 || N % 3 == 0)
            return false;
        for(int i = 5 ; i <= sqrt(N) ; ++i)
            if(N % i == 0)
                return false;
        return true;
    }
    
    string isSumOfTwo(int N){
        for(int i = 2 ; i <= N ; ++i)
            if(isPrime(i) && isPrime(N - i))
                return "Yes";
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends