//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(targetWord) == wordSet.end()) return {}; // If targetWord is not in wordList, return empty
        
        queue<vector<string>> q; // BFS queue storing paths
        q.push({startWord});
        
        unordered_set<string> visited; // To store words visited at current level
        bool found = false;
        
        while (!q.empty() && !found) {
            int levelSize = q.size();
            unordered_set<string> currentLevelWords; // Track words visited in this BFS level
            
            while (levelSize--) {
                vector<string> path = q.front();
                q.pop();
                string lastWord = path.back();
                
                for (int i = 0; i < lastWord.size(); i++) {
                    string temp = lastWord;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[i] = ch;
                        if (wordSet.find(temp) != wordSet.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            if (temp == targetWord) {
                                found = true;
                                result.push_back(newPath);
                            } else {
                                q.push(newPath);
                                currentLevelWords.insert(temp);
                            }
                        }
                    }
                }
            }
            
            // Remove words that were visited in this level to prevent longer paths
            for (const string& word : currentLevelWords) {
                wordSet.erase(word);
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends