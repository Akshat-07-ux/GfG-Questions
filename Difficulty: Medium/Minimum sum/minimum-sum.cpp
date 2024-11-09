//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
public:
    std::string minSum(std::vector<int>& arr) {
        int count[10] = {0};
        
        for (int x : arr) count[x]++;
        
        std::string num1, num2;
        bool toggle = true;
        
        for (int i = 1; i < 10; i++) {
            while (count[i] > 0) {
                if (toggle) {
                    num1 += std::to_string(i);
                } else {
                    num2 += std::to_string(i);
                }
                toggle = !toggle;
                count[i]--;
            }
        }
        
        std::string sumResult;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            sumResult += (sum % 10) + '0';
            carry = sum / 10;
        }

        std::reverse(sumResult.begin(), sumResult.end());
        sumResult.erase(0, sumResult.find_first_not_of('0'));
        
        return sumResult.empty() ? "0" : sumResult;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends