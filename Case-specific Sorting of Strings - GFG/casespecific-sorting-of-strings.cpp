//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n) {
        int arrs[26] = {0};
        int arrc[26] = {0};
        
        for(char ch : str) {
            if(ch >= 'a')
                arrs[ch - 'a']++;
            else
                arrc[ch - 'A']++;
        }
        
        int smIter = 0, lgIter = 0, iter = 0;
        string res = str;
        while(iter < str.size()) {
            if(str[iter] >= 'a') {
                if(arrs[smIter] == 0) {
                    smIter++;
                    continue;
                } else {
                    res[iter++] = 'a' + smIter;
                    arrs[smIter]--;
                }
            } else {
                if(arrc[lgIter] == 0) {
                    lgIter++;
                    continue;
                } else {
                    res[iter++] = 'A' + lgIter;
                    arrc[lgIter]--;
                }
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends