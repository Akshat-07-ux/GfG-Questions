// User function template for C++
class Solution {
    public:
    int kSubstrConcat(int n, string s, int k) {
        if (n % k != 0) return 0;
        
        unordered_map<string, int> freq;
        int total = n / k;
        
        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            freq[sub]++;
        }
        
        int maxFreq = 0;
        for (auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }

        // If all are same, or only one is different
        if ((total - maxFreq) <= 1) return 1;

        return 0;
    }
};