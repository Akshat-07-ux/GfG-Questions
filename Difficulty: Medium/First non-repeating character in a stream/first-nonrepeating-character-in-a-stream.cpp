//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string FirstNonRepeating(string A) {
        unordered_map<char, int> freq; // Map to store character frequencies
        queue<char> q; // Queue to store characters that are candidates for first non-repeating
        string result; // Result string to store the output

        for (char c : A) {
            // Update the frequency of the current character
            freq[c]++;
            
            // Add the character to the queue if it is appearing for the first time
            if (freq[c] == 1) {
                q.push(c);
            }
            
            // Remove characters from the front of the queue that are no longer non-repeating
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
            
            // If queue is empty, append '#' to the result, else append the front character of the queue
            if (q.empty()) {
                result += '#';
            } else {
                result += q.front();
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends