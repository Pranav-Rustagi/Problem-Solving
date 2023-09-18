class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0 ; i < mat.size() ; i++) {
            int count = 0;
            while(count < mat[0].size() && mat[i][count] == 1) {
                count++;
            }

            if(pq.size() == k && pq.top().first > count) {
                pq.pop();
            }

            if(pq.size() < k) {
                pq.push({ count, i });
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