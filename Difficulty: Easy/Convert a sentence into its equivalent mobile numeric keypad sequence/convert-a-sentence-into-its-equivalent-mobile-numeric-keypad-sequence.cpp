//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends

string printSequence(string S)
{
    // Mapping characters to their mobile keypress sequence
    vector<string> keypad(26);
    keypad['A' - 'A'] = "2";
    keypad['B' - 'A'] = "22";
    keypad['C' - 'A'] = "222";
    keypad['D' - 'A'] = "3";
    keypad['E' - 'A'] = "33";
    keypad['F' - 'A'] = "333";
    keypad['G' - 'A'] = "4";
    keypad['H' - 'A'] = "44";
    keypad['I' - 'A'] = "444";
    keypad['J' - 'A'] = "5";
    keypad['K' - 'A'] = "55";
    keypad['L' - 'A'] = "555";
    keypad['M' - 'A'] = "6";
    keypad['N' - 'A'] = "66";
    keypad['O' - 'A'] = "666";
    keypad['P' - 'A'] = "7";
    keypad['Q' - 'A'] = "77";
    keypad['R' - 'A'] = "777";
    keypad['S' - 'A'] = "7777";
    keypad['T' - 'A'] = "8";
    keypad['U' - 'A'] = "88";
    keypad['V' - 'A'] = "888";
    keypad['W' - 'A'] = "9";
    keypad['X' - 'A'] = "99";
    keypad['Y' - 'A'] = "999";
    keypad['Z' - 'A'] = "9999";
    
    string result = "";
    
    for (char ch : S) {
        if (ch == ' ') {
            result += "0";
        } else {
            result += keypad[ch - 'A'];
        }
    }
    
    return result;
}