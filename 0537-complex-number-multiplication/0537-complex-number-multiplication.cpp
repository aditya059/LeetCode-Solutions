class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int index1 = num1.find('+');
        int index2 = num2.find('+');
        int real1 = stoi(num1.substr(0, index1));
        int real2 = stoi(num2.substr(0, index2));
        int imag1 = stoi(num1.substr(index1 + 1, num1.length() - 1));
        int imag2 = stoi(num2.substr(index2 + 1, num2.length() - 1));
        int real = real1 * real2 - imag1 * imag2;
        int imag = real1 * imag2 + real2 * imag1;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};