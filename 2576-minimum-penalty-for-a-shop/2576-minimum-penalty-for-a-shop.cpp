class Solution {
public:
    int bestClosingTime(string customers) {
        int res = 0, resp = 0;
        int nbp = 0, yap = 0;
        for(char ch : customers) {
            if(ch == 'Y') {
                resp++;
            }
        }

        yap = resp;
        for(int i = 0 ; i < customers.size() ; i++) {
            if(customers[i] == 'Y') {
                yap--;
            } else {
                nbp++;
            }

            if(nbp + yap < resp) {
                resp = nbp + yap;
                res = i + 1;
            }
        }
        return res;
    }
};