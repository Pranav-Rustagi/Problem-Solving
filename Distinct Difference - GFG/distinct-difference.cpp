//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for(int i = 0 ; i < N ; i++) {
            m[A[i]]++;
        }
        
        
        vector<int> v;
        for(int i = 0 ; i < N ; i++) {
            m[A[i]]--;
            if(m[A[i]] == 0)
                m.erase(A[i]);
                
            int left = s.size();
            int right = m.size();
            v.push_back(left - right);
            s.insert(A[i]);
        }
        return v;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends