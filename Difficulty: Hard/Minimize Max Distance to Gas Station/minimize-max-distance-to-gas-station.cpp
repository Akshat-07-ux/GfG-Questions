//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canPlaceStations(vector<int> &stations, int k, double maxDist) {
        int requiredStations = 0;
        for (int i = 1; i < stations.size(); ++i) {
            double gap = stations[i] - stations[i - 1];
            requiredStations += (int)(gap / maxDist);
        }
        return requiredStations <= k;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        double left = 0.0;
        double right = stations.back() - stations[0];
        double result = right;

        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (canPlaceStations(stations, k, mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid;
            }
        }

        return round(result * 100) / 100.0;  // Round to 2 decimal places
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends