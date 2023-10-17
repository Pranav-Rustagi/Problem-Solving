class DSU {
public:
    int *arr;
    int n;

    DSU(int n) {
        this -> n = n;
        arr = new int[n];
        iota(arr, arr + n, 0);
    }

    bool add(int node, int par) {
        if(arr[node] != node || arr[par] == node) {
            return false;
        }

        while(arr[par] != par) {
            par = arr[par];
        }
        arr[node] = par;
        return true;
    }

    int countDS() {
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            count += arr[i] == i;
        }
        return count;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);

        for(int i = 0 ; i < n ; i++) {
            if(leftChild[i] != -1) {
                if(!dsu.add(leftChild[i], i)) {
                    return false;
                }
            }
            if(rightChild[i] != -1) {
                if(!dsu.add(rightChild[i], i)) {
                    return false;
                }
            }
        }

        return dsu.countDS() == 1;
    }
};