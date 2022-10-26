class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for(int num: arr) {
            if(!num) count++;
        }
        int i = arr.size() - 1;
        int j = i + count;
        while(j >= 0) {
            if(arr[i]) {
                if(j < arr.size())
                    arr[j] = arr[i];
                j--;
                i--;
            }
            else {
                if(j < arr.size())
                    arr[j] = 0;
                if(j - 1 < arr.size())
                    arr[j - 1] = 0;
                j -= 2;
                i--;
            }
        }
    }
};