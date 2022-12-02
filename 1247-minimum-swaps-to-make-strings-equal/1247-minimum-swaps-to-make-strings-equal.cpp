class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int iter = 0, res = 0;
        while(iter < s1.size()) {
            int temp = -1;
            if(s1[iter] != s2[iter]) {
                for(int j = iter + 1 ; j < s1.size() ; ++j) {
                    if(s1[j] != s2[j]) {
                        if(s1[iter] == s1[j]) {
                            ++res;
                            swap(s1[iter], s2[j]);
                            break;
                        } else {
                            temp = j;
                        }
                    }
                }
            }
            
            if(s1[iter] != s2[iter]) {
                if(temp == -1)
                    return -1;
                res += 2;
                swap(s1[iter], s1[temp]);
            }
            ++iter;
        }
        
        if(s1 == s2)
            return res;
        return -1;
    }
};