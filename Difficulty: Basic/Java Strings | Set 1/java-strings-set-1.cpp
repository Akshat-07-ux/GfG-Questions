// User function Template for C++
class Solution {
  public:
    string conRevstr(string S1, string S2) {
        string final_s = S1 + S2;
        reverse(final_s.begin(), final_s.end());
        return final_s;
    }
};