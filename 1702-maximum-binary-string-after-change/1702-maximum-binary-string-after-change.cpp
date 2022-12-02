class Solution {
public:
    string maximumBinaryString(string binary) {
        int count = 0, j = -1;
        for(int i = binary.size() - 1; i >= 0; i--) {
            if(binary[i] == '0') {
                count++;
                j = i;
            }
            binary[i] = '1';
        }
        if(j != -1)
            binary[j + count - 1] = '0';
        return binary;
    }
};