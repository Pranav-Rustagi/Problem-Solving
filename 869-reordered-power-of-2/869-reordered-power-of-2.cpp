class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int arr1[10] = {0};
        while(n) {
            ++arr1[n % 10];
            n /= 10;
        }
        
        for(int i = 0 ; i < 31 ; ++i) {
            int arr2[10] = {0};
            int num = 1 << i;
            
            while(num) {
                ++arr2[num % 10];
                num /= 10;
            }
            
            for(int j = 0 ; j < 10 ; ++j) {
                if(arr1[j] != arr2[j]) {
                    num = 1;
                    break;
                }
            }
            
            if(num == 0)
                return true;
        }
        
        return false;
    }
};