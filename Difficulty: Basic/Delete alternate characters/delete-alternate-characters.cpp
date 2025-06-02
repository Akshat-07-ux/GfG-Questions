// User function Template for C++
class Solution {
  public:
    string delAlternate(string S) {
        string result = "";
        for (int i = 0; i < S.length(); i += 2) {
            result += S[i];
        }
        return result;
    }
};