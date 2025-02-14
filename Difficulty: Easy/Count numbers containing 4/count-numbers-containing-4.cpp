//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool hasFour(int num) {
        while (num > 0) {
            if (num % 10 == 4) return true;
            num /= 10;
        }
        return false;
    }

    int countNumberswith4(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (hasFour(i)) count++;
        }
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends