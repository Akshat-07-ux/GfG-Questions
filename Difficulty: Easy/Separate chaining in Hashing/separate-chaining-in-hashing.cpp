class Solution {
  public:
    // Function to insert elements of array in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hashSize, int arr[], int sizeOfArray) {
        vector<vector<int>> hashTable(hashSize); // Initialize hash table with empty chains
        
        for (int i = 0; i < sizeOfArray; ++i) {
            int index = arr[i] % hashSize; // Get hash index
            hashTable[index].push_back(arr[i]); // Insert into the appropriate chain
        }
        
        return hashTable;
    }
};