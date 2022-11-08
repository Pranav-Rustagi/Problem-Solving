class Solution {
public:
    string makeGood(string s) {
        string r;
        int diff = 'a' - 'A';
        for(auto & ch : s) {
            bool f = r.size() && (r.back() == ch + diff || r.back() == ch - diff);
            if(f)
                r.pop_back();
            else
                r.push_back(ch);
        }
        return r;
    }
};