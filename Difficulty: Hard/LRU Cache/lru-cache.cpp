//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
 private:
    int capacity;
    list<pair<int, int>> cacheList; // Doubly linked list to store key-value pairs.
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Hashmap to store key -> list iterator.

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // If the key is not found in the cache, return -1.
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        // Move the key-value pair to the front of the list (most recently used).
        auto it = cacheMap[key];
        int value = it->second;

        // Move the accessed item to the front of the list.
        cacheList.erase(it); // Remove from current position.
        cacheList.push_front({key, value}); // Insert at the front.

        // Update the map with the new position.
        cacheMap[key] = cacheList.begin();

        return value;
    }

    // Function for storing key-value pair.
    void set(int key, int value) {
        // If the key is already in the cache, update the value and move it to the front.
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];

            // Erase the old key-value pair from the list.
            cacheList.erase(it);

            // Insert the updated key-value pair at the front.
            cacheList.push_front({key, value});
        } else {
            // If the cache is full, remove the least recently used item (tail of the list).
            if (cacheList.size() == capacity) {
                int leastUsedKey = cacheList.back().first; // Key of the least recently used item.
                cacheList.pop_back(); // Remove from the list.
                cacheMap.erase(leastUsedKey); // Erase from the map.
            }

            // Insert the new key-value pair at the front of the list.
            cacheList.push_front({key, value});
        }

        // Update the map with the new iterator position.
        cacheMap[key] = cacheList.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends