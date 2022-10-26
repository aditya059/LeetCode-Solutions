class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for(int num: arr) {
            if(!num) count++;
        }
        int j = arr.size() + count;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(--j < arr.size())
                arr[j] = arr[i];
            if(arr[i] == 0 && --j < arr.size())
                arr[j] = 0;
        }
    }
};