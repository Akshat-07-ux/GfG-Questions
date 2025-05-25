class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // Since 1 <= arr[i] <= 1000, max square is 1,000,000
        unordered_set<int> nums(arr.begin(), arr.end());

        // Iterate a and b such that a^2 + b^2 is a perfect square and in nums
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int a2 = arr[i] * arr[i];
                int b2 = arr[j] * arr[j];
                int c2 = a2 + b2;
                int c = (int)sqrt(c2);

                if (c * c == c2 && nums.count(c)) {
                    // ensure indices are different and c is present
                    if (c != arr[i] && c != arr[j]) return true;

                    // if c == arr[i] or arr[j], ensure there's at least another one
                    int count = 0;
                    if (arr[i] == c) count++;
                    if (arr[j] == c) count++;
                    if (count < count_if(arr.begin(), arr.end(), [c](int x){ return x == c; }))
                        return true;
                }
            }
        }
        return false;
    }
};
