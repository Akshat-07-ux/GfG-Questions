class Solution {
  public:
    bool cat_hat(string str) {
        int n = str.size();
        int catCount = 0, hatCount = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (str.substr(i, 3) == "cat") {
                catCount++;
            }
            if (str.substr(i, 3) == "hat") {
                hatCount++;
            }
        }

        return catCount == hatCount;
    }
};
