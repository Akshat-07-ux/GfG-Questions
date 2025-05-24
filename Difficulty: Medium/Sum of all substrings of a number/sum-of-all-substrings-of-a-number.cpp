class Solution {
 public:
    int sumSubstrings(string &s) {
        int n = s.length();
        long long res = 0;
        long long prev = 0;
        int mod = 1e9 + 7; // Not needed as the sum is guaranteed to fit in 32-bit int, but for safety in larger variations

        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';
            prev = prev * 10 + num * (i + 1);
            res += prev;
        }

        return (int)res;
    }
};