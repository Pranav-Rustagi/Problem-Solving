class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0, n = words.size();

        for(int i = 0 ; i < n ; i++) {
            int n1 = words[i].size();
            for(int j = i + 1 ; j < n ; j++) {
                int n2 = words[j].size();

                if (n1 > n2) {
                    continue;
                }

                bool flag = true;
                for(int k = 0 ; k < n1 ; k++) {
                    if(words[j][k] != words[i][k] || words[j][n2 - n1 + k] != words[i][k]) {
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    count++;
                }
            }
        }

        return count;       
    }
};