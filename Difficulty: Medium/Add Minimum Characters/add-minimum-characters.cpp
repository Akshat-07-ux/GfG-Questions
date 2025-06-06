// User function Template for C++

class Solution {
    public:
    int addMinChar(string str) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        string temp = str + "$" + rev;
        int n = temp.length();

        // Build LPS array (KMP)
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while (len > 0 && temp[i] != temp[len]) {
                len = lps[len - 1];
            }
            if (temp[i] == temp[len]) {
                len++;
            }
            lps[i] = len;
        }

        return str.length() - lps.back();  // Minimum chars to add at front
    }
};