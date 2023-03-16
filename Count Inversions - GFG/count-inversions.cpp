//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long start, long long end, long long& count) {
        if(start >= end)
            return;
        long long mid = (start + end) >> 1;
        merge(arr, start, mid, count);
        merge(arr, mid + 1, end, count);
        vector<long long> temp(end - start + 1);
        long long iter1 = start, iter2 = mid + 1, i = 0;
        while(iter1 <= mid && iter2 <= end) {
            if(arr[iter1] <= arr[iter2]) {
                temp[i++] = arr[iter1++];
            } else {
                count += (mid - iter1 + 1);
                temp[i++] = arr[iter2++];
            }
        }
        
        while(iter1 <= mid)
            temp[i++] = arr[iter1++];
        while(iter2 <= end)
            temp[i++] = arr[iter2++];
        i = 0;
        while(i < temp.size()) {
            arr[start + i] = temp[i];
            i++;
        }
    }
    
    long long int inversionCount(long long arr[], long long N) {
        long long count = 0;
        merge(arr, 0, N - 1, count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends