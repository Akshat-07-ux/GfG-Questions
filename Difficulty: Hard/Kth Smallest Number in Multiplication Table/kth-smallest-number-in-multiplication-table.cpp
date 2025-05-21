class Solution {
 public:
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n); // count numbers ≤ mid in row i
            }
            if (count >= k) {
                ans = mid;         // mid might be the answer
                high = mid - 1;    // look for smaller number
            } else {
                low = mid + 1;     // look for larger number
            }
        }
        return ans;
    }
};
