class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        int res = 0, n = profit.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        sort(workers.begin(), workers.end());
        
        for(int i = 0 ; i < n ; i++) {
            pq.push({ difficulty[i], profit[i] });
        }
        
        int max_prof = 0;
        
        for(int worker : workers) {
            while(!pq.empty() && pq.top().first <= worker) {
                max_prof = max(max_prof, pq.top().second);
                pq.pop();
            }
            
            res += max_prof;
        }
        
        return res;
    }
};