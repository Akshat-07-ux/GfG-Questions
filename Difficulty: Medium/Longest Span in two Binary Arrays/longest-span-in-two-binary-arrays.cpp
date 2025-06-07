class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> m;  // map to store prefix_sum -> first index
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            // Replace with difference of elements
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            if (prefixSum == 0) {
                maxLen = i + 1;
            }

            if (m.find(prefixSum) != m.end()) {
                maxLen = max(maxLen, i - m[prefixSum]);
            } else {
                m[prefixSum] = i;
            }
        }

        return maxLen;
    }
};