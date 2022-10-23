class Solution {
public:
    string thousands[4] = {"", "Thousand", "Million", "Billion"};
    string tens[11] = {"Ten", "Twenty", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string belowTwenty[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string to_word(int num) {
        if(!num)
            return "";
        string ans = "";
        if(num < 20) 
            ans += belowTwenty[num] + " ";
        else if(num < 100)
            ans += tens[num / 10] + " " + to_word(num % 10);
        else
            ans += belowTwenty[num / 100] + " Hundred " + to_word(num % 100);
        return ans;
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        int i = 0;
        string ans = "";
        while(num > 0) {
            int d = num % 1000;
            if(d)
                ans = to_word(d) + thousands[i] + " " + ans;  
            num /= 1000;
            i++;
        }
        for(i = ans.length() - 1; i >= 0; i--) {
            if(ans[i] != ' ')
                break;
        }
        return ans.substr(0, i + 1);
    }
};