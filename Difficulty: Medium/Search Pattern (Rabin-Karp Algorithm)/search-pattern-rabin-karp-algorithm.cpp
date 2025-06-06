class Solution {
  public:
    // Function to build LPS array for KMP algorithm
    vector<int> computeLPSArray(string &pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(string &pat, string &txt) {
        int m = pat.length();
        int n = txt.length();
        vector<int> lps = computeLPSArray(pat);
        vector<int> result;

        int i = 0; // index for txt
        int j = 0; // index for pat

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                // Pattern found at index i - j (0-based); add 1 for 1-based index
                result.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};