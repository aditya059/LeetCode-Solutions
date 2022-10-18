class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int index = 0;
        for(int i = 1; i <= chars.size(); i++) {
            if(i < chars.size() && chars[i] == chars[i - 1]) {
                count++;
            }
            else {
                chars[index] = chars[i - 1];
                index++;
                if(count > 1) {
                    for(char ch: to_string(count)) {
                        chars[index++] = ch;
                    }
                }
                count = 1;
            }
        }
        return index;
    }
};