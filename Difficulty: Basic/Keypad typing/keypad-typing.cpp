// User function template for C++

// User function template for C++
string printNumber(string s, int n) {
    // Mapping each character to its corresponding number
    string mapping[26] = {
        "2", "2", "2",      // a b c
        "3", "3", "3",      // d e f
        "4", "4", "4",      // g h i
        "5", "5", "5",      // j k l
        "6", "6", "6",      // m n o
        "7", "7", "7", "7", // p q r s
        "8", "8", "8",      // t u v
        "9", "9", "9", "9"  // w x y z
    };

    string result = "";
    for (int i = 0; i < n; ++i) {
        result += mapping[s[i] - 'a'];
    }

    return result;
}
