//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    vector<int> solve(vector<vector<int>>& arr, int i, int j) {
        if(i > j)   return {};
        if(i == j) { return arr[i]; }
        
        int mid = (i + j) >> 1;
        vector<int> left = solve(arr, i, mid);
        vector<int> right = solve(arr, mid + 1, j);
        
        vector<int> res;
        int i1 = 0, i2 = 0;
        while(i1 < left.size() && i2 < right.size()) {
            if(left[i1] < right[i2]) {
                res.push_back(left[i1++]);
            } else {
                res.push_back(right[i2++]);
            }
        }
        
        while(i1 < left.size()) {
            res.push_back(left[i1++]);
        }
        while(i2 < right.size()) {
            res.push_back(right[i2++]);
        }
        
        return res;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        return solve(arr, 0, K - 1);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends