//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        double res = 0;
        sort(arr, arr + n, [](const Item & a, const Item & b) {
            return (double(a.value) / a.weight) > (double(b.value) / b.weight);
        });
        
        int i = 0;
        while(i < n) {
            if(arr[i].weight <= W) {
                W -= arr[i].weight;
                res += arr[i].value;
                i++;
            } else {
                res += (double(arr[i].value) / arr[i].weight) * W;
                break;
            }
        }
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends