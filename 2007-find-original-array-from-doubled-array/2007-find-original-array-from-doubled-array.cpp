class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> temp(100001, 0), res;
        for(auto & el : changed)
            ++temp[el];
        
        if(temp[0] & 1)
            return {};
        while(temp[0]) {
            res.push_back(0);
            temp[0] -= 2;
        }
        
        for(long i = 1 ; i < temp.size() ; ++i) {
            if(temp[i]) {
                if((i << 1) > 100000 || temp[i] > temp[i << 1])
                    return {};
                else {
                    temp[i << 1] -= temp[i];
                    while(temp[i]--) {
                        res.push_back(i);
                    }
                }
            }
        }
        
        return res;
    }
};
// [100000,100000,100000,100000,100000,100000,100000,100000,100000]
// [1,3,4,2,6,8]
// [6,3,0,1]
// [1]
// [4,2,0]