class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)   swap(m, n);
        int arr[m];
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;

        while(n--)
            for(int i = 1 ; i < m ; i++)
                arr[i] += arr[i - 1];
                
        return arr[m - 1];
    }
};