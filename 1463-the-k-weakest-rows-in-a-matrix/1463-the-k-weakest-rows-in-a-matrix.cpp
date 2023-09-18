class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int n = mat.size(), m = mat[0].size(), sz = 0;

        for(int i = 0 ; i < n ; i++) {
            int count = 0;
            while(count < m && mat[i][count] == 1) {
                count++;
            }

            if(sz == k && pq.top().first > count) {
                pq.pop();
                sz--;
            }

            if(sz < k) {
                pq.push({ count, i });
                sz++;
            }
        }

        vector<int> res(k);
        while(k--) {
            res[k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};