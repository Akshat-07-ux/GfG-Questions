
class Solution {
 public:
    int extractMaximum(string S) {
        int maxNum = -1;
        int num = 0;
        bool foundDigit = false;

        for (char ch : S) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Build the current number
                foundDigit = true;
            } else {
                if (foundDigit) {
                    maxNum = max(maxNum, num);
                    num = 0;
                    foundDigit = false;
                }
            }
        }

        // Check for a number at the end of the string
        if (foundDigit) {
            maxNum = max(maxNum, num);
        }

        return maxNum;
    }
};