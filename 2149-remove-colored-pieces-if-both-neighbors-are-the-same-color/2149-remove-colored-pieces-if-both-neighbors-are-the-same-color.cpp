class Solution {
public:
    bool winnerOfGame(string colors) {
        int ac = 0, bc = 0, n = colors.size(), i = 0;

        while(i < n) {
            int c = 1;
            int j = i + 1;
            while(j < n && colors[i] == colors[j]) {
                c++;
                j++;
            }

            if(colors[i] == 'A') {
                ac += max(0, c - 2);
            } else {
                bc += max(0, c - 2);
            }


            i = j;
        }

        return ac > bc;
    }
};