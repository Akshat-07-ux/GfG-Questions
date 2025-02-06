//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Convert wordList to a set for O(1) lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If target word is not in the set, transformation is impossible
        if (wordSet.find(targetWord) == wordSet.end()) return 0;
        
        // Add startWord to set if not already present
        wordSet.insert(startWord);
        
        // Queue for BFS traversal
        queue<string> q;
        q.push(startWord);
        
        // Distance tracking
        unordered_map<string, int> dist;
        dist[startWord] = 1;
        
        // BFS
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // If target is reached, return distance
            if (curr == targetWord) return dist[curr];
            
            // Try changing each character
            for (int i = 0; i < curr.length(); i++) {
                string temp = curr;
                
                // Try all 26 lowercase letters
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    
                    // If new word exists in set and not visited
                    if (wordSet.find(temp) != wordSet.end() && 
                        dist.find(temp) == dist.end()) {
                        q.push(temp);
                        dist[temp] = dist[curr] + 1;
                    }
                }
            }
        }
        
        // No transformation sequence found
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends