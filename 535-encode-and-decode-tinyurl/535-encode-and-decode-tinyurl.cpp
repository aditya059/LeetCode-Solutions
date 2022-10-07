class Solution {
public:
    unordered_map<string, string> Map1;
    unordered_map<string, string> Map2;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans = "http://tinyurl.com/" + to_string(count); 
        Map1[longUrl] = ans;
        Map2[ans] = longUrl;
        count++;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return Map2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

/*
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};
*/