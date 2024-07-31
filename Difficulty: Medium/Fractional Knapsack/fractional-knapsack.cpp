//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sorting items based on their value-to-weight ratio
        sort(arr, arr + n, [](Item a, Item b) {
            double r1 = (double)a.value / a.weight;
            double r2 = (double)b.value / b.weight;
            return r1 > r2;
        });

        double maxValue = 0.0; // Variable to store the maximum value in knapsack
        int currentWeight = 0; // Current weight in knapsack

        for (int i = 0; i < n; ++i) {
            if (currentWeight + arr[i].weight <= w) {
                // If the item can be added completely
                currentWeight += arr[i].weight;
                maxValue += arr[i].value;
            } else {
                // If the item can't be added completely, add the fraction
                int remainingWeight = w - currentWeight;
                maxValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
                break; // Knapsack is full
            }
        }

        return maxValue;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends