class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end)
            return 0;
        
        unordered_map<string, unordered_set<string>> m;
        bank.push_back(start);
        for(auto & b : bank) {
            if(m.find(b) != m.end())
                continue;
            for(auto & bt : bank) {
                int diff = 0;
                for(int i = 0 ; i < 8 ; ++i) {
                    if(b[i] != bt[i])
                        ++diff;
                }
                if(diff == 1)
                    m[b].insert(bt);
            }
        }
        
        
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        int res = 0;
        while(!q.empty()) {
            int n = q.size();
            ++res;
            while(n--) {
                for(auto & str : m[q.front()]) {
                    if(visited.find(str) != visited.end())
                        continue;
                    if(str == end)
                        return res;
                    q.push(str);
                }
                visited.insert(q.front());
                q.pop();
            }
        }
        
        return -1;
    }
};