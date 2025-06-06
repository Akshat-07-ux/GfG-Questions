// User function template

class Solution {
   public:
    int fun(string &s) {
        const int MOD = 1e9 + 7;
        long long a_count = 0, ab_count = 0, abc_count = 0;

        for (char ch : s) {
            if (ch == 'a') {
                a_count = (2 * a_count + 1) % MOD;
            } else if (ch == 'b') {
                ab_count = (2 * ab_count + a_count) % MOD;
            } else if (ch == 'c') {
                abc_count = (2 * abc_count + ab_count) % MOD;
            }
        }

        return abc_count;
    }
};
