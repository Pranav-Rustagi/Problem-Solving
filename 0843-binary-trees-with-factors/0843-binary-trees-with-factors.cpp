class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> m;
        sort(arr.begin(), arr.end());

        int n = arr.size(), mod = 1e9 + 7, count = 0;
        for(int i = 0 ; i < n ; i++) {
            int s = 0, e = i - 1;

            m[arr[i]] = 1;
            while(s <= e) {
                long tr = (long)arr[s] * (long)arr[e];
                if(tr == arr[i]) {
                    int fc = 1 + (s != e);
                    m[arr[i]] = (m[arr[i]] + (fc * m[arr[s]] * m[arr[e]] % mod)) % mod;
                    s++;
                    e--;
                } else if(tr > arr[i]) {
                    e--;
                } else {
                    s++;
                }
            }
            count = (count + m[arr[i]]) % mod;
        }
        return count;
    }
};