// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    unordered_map<string, bool> memo;

    bool isScramble(string S1, string S2) {
        // Base cases
        if (S1 == S2) return true;
        if (S1.length() != S2.length()) return false;

        string key = S1 + "_" + S2;
        if (memo.find(key) != memo.end())
            return memo[key];

        int n = S1.length();

        // Check if both strings have the same character counts
        string sorted1 = S1, sorted2 = S2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2)
            return memo[key] = false;

        // Try all split positions
        for (int i = 1; i < n; ++i) {
            // Case 1: No swap
            if (isScramble(S1.substr(0, i), S2.substr(0, i)) &&
                isScramble(S1.substr(i), S2.substr(i)))
                return memo[key] = true;

            // Case 2: Swap
            if (isScramble(S1.substr(0, i), S2.substr(n - i)) &&
                isScramble(S1.substr(i), S2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
};