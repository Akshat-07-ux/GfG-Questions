class Solution {
   public:
    bool isAdditiveSequence(string n) {
        int len = n.length();
        for (int i = 1; i < len; ++i) {
            for (int j = 1; i + j < len; ++j) {
                string num1 = n.substr(0, i);
                string num2 = n.substr(i, j);
                
                // Skip if num1 or num2 has leading zeros (but allow "0")
                if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0'))
                    continue;

                if (check(num1, num2, i + j, n))
                    return true;
            }
        }
        return false;
    }

  private:
    // Helper to add two numbers represented as strings
    string addStrings(const string& a, const string& b) {
        string res;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int digitA = i >= 0 ? a[i--] - '0' : 0;
            int digitB = j >= 0 ? b[j--] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum / 10;
            res += (sum % 10 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string num1, string num2, int pos, const string& n) {
        while (pos < n.size()) {
            string sum = addStrings(num1, num2);
            if (n.substr(pos, sum.size()) != sum)
                return false;
            pos += sum.size();
            num1 = num2;
            num2 = sum;
        }
        return true;
    }
};
