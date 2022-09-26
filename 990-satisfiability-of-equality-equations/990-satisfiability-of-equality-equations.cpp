class Solution {
public:
    int group = 1;
    unordered_map<char, int> m;
    
    bool equationsPossible(vector<string>& equations) {
        for(string& eq : equations) {
            if(eq[1] == '=') {
                int temp1 = max(m[eq[0]], m[eq[3]]);
                if(temp1) {
                    int temp2 = min(m[eq[0]], m[eq[3]]);
                    m[eq[0]] = m[eq[3]] = temp1;
                    if(temp2) {
                        for(auto & p : m) {
                            if(p.second == temp2)
                                p.second = temp1;
                        }
                    }
                } else {
                    m[eq[0]] = m[eq[3]] = ++group;
                }
            } else if(eq[0] == eq[3]) {
                return false;
            }
        }
        
        for(string& eq : equations) {
            if(eq[1] == '!' && m[eq[0]] && m[eq[0]] == m[eq[3]])
                return false;
        }
        
        return true;
    }
};