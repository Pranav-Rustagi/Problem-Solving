#define pii pair<int, int>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({ 0, 0 });

        int dist = 0;
        int vis[n], distArr[n];
        for(int i = 0 ; i < n ; i++) {
            vis[i] = false;
            distArr[i] = INT_MAX;
        }

        distArr[0] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second;
            pq.pop();

            if(vis[x] || distArr[x] < d) {
                continue;
            }

            dist += d;
            vis[x] = true;

            for(int i = 0 ; i < n ; i++) {
                if(!vis[i]) {
                    distArr[i] = abs(points[x][0] - points[i][0]) + abs(points[x][1] - points[i][1]);
                    pq.push({ distArr[i], i });
                }
            }

        }
        return dist;
    }
};