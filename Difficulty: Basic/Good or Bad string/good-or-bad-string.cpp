// User function template for C++

class Solution {
   public:
    int isGoodorBad(string S) {
        int vowelCount = 0, consonantCount = 0;

        for (int i = 0; i < S.length(); ++i) {
            char ch = S[i];
            // Check if character is vowel
            bool isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');

            if (ch == '?') {
                // '?' can be both vowel or consonant
                // So take worst case for both scenarios
                vowelCount++;
                consonantCount++;
            } else if (isVowel) {
                vowelCount++;
                consonantCount = 0;
            } else {
                consonantCount++;
                vowelCount = 0;
            }

            // Check for BAD condition
            if (vowelCount > 5 || consonantCount > 3) {
                return 0; // BAD
            }
        }

        return 1; // GOOD
    }
};