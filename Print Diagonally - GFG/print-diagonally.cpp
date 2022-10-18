//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A) {
	    int i = 0, j = 0;
	    vector<int> v;
	    while(i < N) {
	        int dupI = i, dupJ = j;
	        while(dupI < N && dupJ >= 0) {
    	        v.push_back(A[dupI++][dupJ--]);
	        }
	        if(j < N - 1) {
	            ++j;
	        } else {
	            ++i;
	        }
	    }
	    
	    return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends