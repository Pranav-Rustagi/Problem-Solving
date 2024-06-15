class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size(), ind = 0;
        pair<int, int> projects[n];
        
        for(int i = 0 ; i < n ; i++) {
            projects[i].first = capital[i];
            projects[i].second = profits[i];
        }
        
        sort(projects, projects + n);
        priority_queue<int> pq;
        
        while(k--) {
            while(ind < n && w >= projects[ind].first) {
                pq.push(projects[ind].second);
                ind++;
            }
            
            if(pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};