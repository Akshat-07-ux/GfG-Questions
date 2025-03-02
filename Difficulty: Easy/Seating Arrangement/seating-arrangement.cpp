//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats) {
        for (int i = 0; i < m; i++) {
            if (seats[i] == 0) {  
                bool left_empty = (i == 0 || seats[i - 1] == 0);
                bool right_empty = (i == m - 1 || seats[i + 1] == 0);

                if (left_empty && right_empty) {  // Valid seat found
                    seats[i] = 1;  // Seat the person
                    n--;  // One person seated
                }
            }
            if (n == 0) return true;  // All people are seated
        }
        return false;  // Not enough seats
    }
};



//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    
cout << "~" << "\n";
}
}

// } Driver Code Ends