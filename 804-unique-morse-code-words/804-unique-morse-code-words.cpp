class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        string map[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto& w : words) {
            string temp;
            for(auto& c : w) {
                temp += map[c - 'a'];
            }
            
            s.insert(temp);
        }
        
        return s.size();
    }
};