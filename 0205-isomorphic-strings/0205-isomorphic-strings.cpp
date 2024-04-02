class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        
        unordered_map<char, char> map1, map2;
        int n = s.size();
                        
        for (int i = 0 ; i < n ; i++) {
            if(!map1.count(s[i])) {
                map1[s[i]] = t[i];
            } 
            
            if(!map2.count(t[i])) {
                map2[t[i]] = s[i];
            }
               
            if (map1[s[i]] != t[i] || map2[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};