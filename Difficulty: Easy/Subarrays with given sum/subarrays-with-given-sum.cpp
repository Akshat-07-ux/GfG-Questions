class Solution {
  public:
    int subArraySum(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0, count = 0;

        prefixSumCount[0] = 1; // for subarrays starting from index 0

        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];

            // If there exists a prefix sum that we can subtract to get k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Record the current prefix sum
            prefixSumCount[sum]++;
        }

        return count;
    }
};