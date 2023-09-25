class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};

        for(char ch : s)
            ++arr[ch - 'a'];

        for(char ch : t)
            if(--arr[ch - 'a'] == -1)
                return ch;

        return '\0';
    }
};