class Solution {
  public:
    int getCount(vector<int> &arr, int num1, int num2) {
        int n = arr.size();
        int left = -1, right = -1;

        // Find leftmost index of num1 and rightmost index of num2
        for (int i = 0; i < n; i++) {
            if (arr[i] == num1 && left == -1) {
                left = i;
            }
            if (arr[i] == num2) {
                right = i;
            }
        }

        // If either num1 or num2 is not found, or order is invalid
        if (left == -1 || right == -1 || left >= right) {
            return 0;
        }

        // Count elements between left and right (excluding boundaries)
        return right - left - 1;
    }
};
