class Solution {
public:
    string maximumBinaryString(string binary) {
        int count = 0, j;
        for(int i = 0; i < binary.size(); i++) {
            if(binary[i] == '0') {
                j = i;
                break;
            }
            binary[i] = '1';
        }
        binary[j] = '1';
        for(int i = j + 1; i < binary.size(); i++) {
            if(binary[i] == '0') count++;
            binary[i] = '1';
        }
        binary[j + count] = '0';
        return binary;
    }
};