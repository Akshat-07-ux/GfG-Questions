#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int atMostKDistinct(string& s, int k) {
        if (k == 0) return 0;
        int n = s.length();
        vector<int> freq(26, 0); // only lowercase letters
        int left = 0, right = 0, count = 0;
        int distinct = 0;

        while (right < n) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            count += (right - left + 1);
            right++;
        }

        return count;
    }

    int countSubstr(string& s, int k) {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
};
