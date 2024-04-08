class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int arr[2] = {0}, n = students.size();
        for(int el : students) {
            arr[el]++;
        }
        
        for(int el : sandwiches) {
            if(arr[el] == 0) {
                return n;
            } else {
                arr[el]--;
            }
            n--;
        }
        
        return 0;
    }
};