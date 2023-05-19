//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        vector<vector<int>> ranges;
        vector<int> count;
        
        for(auto r : range) {
            int prevCount;
            if(ranges.size() == 0 || ranges.back()[1] < r[0]) {
                prevCount = count.size() ? count.back() : 0;
                ranges.push_back(r);
                count.push_back(prevCount + r[1] - r[0] + 1);
            } else {
                prevCount = count.size() > 1 ? count[count.size() - 2] : 0;
                ranges.back()[1] = max(ranges.back()[1], r[1]);
                count.back() = prevCount + ranges.back()[1] - ranges.back()[0] + 1;
            }
        }
        
        vector<int> res;
        for(auto q : queries) {
            auto iter = upper_bound(count.begin(), count.end(), q - 1);
            int ind = iter - count.begin();
            if(ind == ranges.size()) {
                res.push_back(-1);
            } else if(ind == 0) {
                res.push_back(ranges[ind][0] + q - 1);
            } else {
                res.push_back(ranges[ind][0] + (q - count[ind - 1] - 1));
            }
        }
        return res;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends