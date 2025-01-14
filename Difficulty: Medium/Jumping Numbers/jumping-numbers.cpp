//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long jumpingNums(long long X) {
        if (X <= 9) return X;  // All single-digit numbers are Jumping Numbers

        queue<long long> q;
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }

        long long largestJumpingNum = 0;

        while (!q.empty()) {
            long long num = q.front();
            q.pop();

            if (num <= X) {
                largestJumpingNum = max(largestJumpingNum, num);

                int lastDigit = num % 10;

                // Generate next possible Jumping Numbers
                if (lastDigit > 0) {
                    q.push(num * 10 + (lastDigit - 1));
                }
                if (lastDigit < 9) {
                    q.push(num * 10 + (lastDigit + 1));
                }
            }
        }

        return largestJumpingNum;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends