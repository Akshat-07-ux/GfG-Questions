//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  private:
    vector<bool> isPrime;
    vector<int> primes;

    void sieve(int maxVal) {
        isPrime.resize(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= maxVal; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    int nearestPrime(int n) {
        if (isPrime[n]) return n;

        int lo = n - 1, hi = n + 1;

        while (lo >= 2 || hi < isPrime.size()) {
            if (lo >= 2 && isPrime[lo]) return lo;
            if (hi < isPrime.size() && isPrime[hi]) return hi;
            --lo;
            ++hi;
        }
        return 2; // default fallback, shouldn't reach here
    }

public:
    Node *primeList(Node *head) {
        sieve(20000); // prime sieve up to 20000 for safety

        Node *curr = head;
        while (curr) {
            curr->val = nearestPrime(curr->val);
            curr = curr->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends