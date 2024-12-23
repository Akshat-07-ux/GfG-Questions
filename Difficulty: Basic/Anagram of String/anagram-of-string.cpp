//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
// Function to calculate the minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2) {
    // Frequency arrays for each character (a-z)
    vector<int> freq1(26, 0), freq2(26, 0);

    // Count frequency of characters in str1
    for (char c : str1) {
        freq1[c - 'a']++;
    }

    // Count frequency of characters in str2
    for (char c : str2) {
        freq2[c - 'a']++;
    }

    // Calculate the total deletions required
    int deletions = 0;
    for (int i = 0; i < 26; ++i) {
        deletions += abs(freq1[i] - freq2[i]);
    }

    return deletions;
}