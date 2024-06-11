class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int arr[1001] = {0}, i = 0;
        for(auto el : arr1) {
            arr[el]++;
        }
        
        for(int el : arr2) {
            while(arr[el]--) {
                arr1[i++] = el;
            }
        }
        
        for(int j = 0 ; j < 1001 ; j++) {
            while(arr[j]-- > 0) {
                arr1[i++] = j;
            }
        }
        
        return arr1;
    }
};