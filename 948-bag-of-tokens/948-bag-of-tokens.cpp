class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, score = 0;
        while(i < j) {
            if(power >= tokens[i]) {
                power -= tokens[i++];
                ++score;
            } else if(score) {
                --score;
                power += tokens[j--];
            } else {
                break;
            }
        }
        
        if(i == j && power >= tokens[i])
            ++score;
        return score;
    }
};