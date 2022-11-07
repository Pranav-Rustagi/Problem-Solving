class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> arr(mat.size(), vector<int>(2, 0));
        
        for(int i = 0 ; i < mat.size() ; ++i) {
            arr[i][0] = i;
            for(auto & el : mat[i])
                arr[i][1] += el;
        }
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        
        vector<int> res;
        for(int i = 0 ; i < k ; ++i) {
            res.push_back(arr[i][0]);
        }
        
        return res;
    }
};