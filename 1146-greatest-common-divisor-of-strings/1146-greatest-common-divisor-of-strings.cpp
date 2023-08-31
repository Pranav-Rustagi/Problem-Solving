class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n1 < n2) {
            return gcdOfStrings(str2, str1);
        }

        int len = __gcd(n1, n2);
        string gcd = str2.substr(0, len);
        while(len > 0) {
            if(n1 % len || n2 % len) {
                len--;
                continue;
            }
            
            bool f = true;
            for(int i = 0 ; i < n1 ; i += len) {
                if(str1.substr(i, len) != gcd) {
                    f = false;
                    break;
                }
            }

            for(int i = len ; i < n2 ; i += len) {
                if(str2.substr(i, len) != gcd) {
                    f = false;
                    break;
                }
            }

            if(f == true)   return gcd;
            len--;
            gcd.pop_back();
        }

        return "";
    }
};