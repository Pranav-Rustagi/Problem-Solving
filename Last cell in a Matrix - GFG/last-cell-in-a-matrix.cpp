//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void changeDir(char& d) {
        if(d == 'r')
            d = 'd';
        else if(d == 'l')
            d = 'u';
        else if(d == 'u')
            d = 'r';
        else
            d = 'l';
    }
    pair<int,int> endPoints(vector<vector<int>>& matrix, int R, int C){
        int r = 0, c = 0;
        char d = 'r';
        while(r >= 0 && c >= 0 && r < R && c < C) {
            if(matrix[r][c]) {
                matrix[r][c] = 0;
                changeDir(d);
            }
            
            if(d == 'r') {
                c++;
            } else if(d == 'l') {
                c--;
            } else if(d == 'd') {
                r++;
            } else {
                r--;
            }
        }
        
        return { max(0, min(r, R - 1)), max(0, min(c, C - 1)) };
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends