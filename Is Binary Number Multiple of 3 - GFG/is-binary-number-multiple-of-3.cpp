//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int n = s.size();
	    int sum = 0;
	    for(int i = n - 1 ; i >= 0 ; i--) {
	        sum = sum * 2 + (s[i] - '0');
	        sum %= 3;
	    }
	    
	    return sum == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends