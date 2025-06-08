class Solution {
   public:
    // Helper function to add two numeric strings
    string stringAdd(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        return result;
    }

    // Recursive check for sum-string starting at index with two initial lengths
    bool isSumStringUtil(string &s, int start, int len1, int len2) {
        string s1 = s.substr(start, len1);
        string s2 = s.substr(start + len1, len2);
        
        // If either has leading zeros (but not '0'), it's invalid
        if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
            return false;

        string sum = stringAdd(s1, s2);
        int nextIndex = start + len1 + len2;
        
        if (nextIndex + sum.size() > s.size()) return false;

        string s3 = s.substr(nextIndex, sum.size());

        if (sum != s3) return false;

        // If reached end, it's valid
        if (nextIndex + sum.size() == s.size()) return true;

        // Recur with next segments
        return isSumStringUtil(s, start + len1, len2, sum.size());
    }

    bool isSumString(string &s) {
        int n = s.size();
        // Try every possible combination of first two numbers
        for (int len1 = 1; len1 <= n / 2; ++len1) {
            for (int len2 = 1; len2 <= (n - len1) / 2; ++len2) {
                if (isSumStringUtil(s, 0, len1, len2))
                    return true;
            }
        }
        return false;
    }
};