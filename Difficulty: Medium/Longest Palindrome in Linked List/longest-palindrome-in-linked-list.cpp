/* The Node is defined
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    // Helper to count common nodes (length of palindrome)
    int countCommon(Node* a, Node* b) {
        int count = 0;
        while (a && b && a->data == b->data) {
            ++count;
            a = a->next;
            b = b->next;
        }
        return count;
    }

    int maxPalindrome(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        int result = 0;

        while (curr) {
            Node* next = curr->next;

            // Reverse current node's link
            curr->next = prev;

            // Check for odd length palindrome (centered at curr)
            int oddLen = 2 * countCommon(prev, next) + 1;
            result = std::max(result, oddLen);

            // Check for even length palindrome (center between prev and curr)
            int evenLen = 2 * countCommon(curr, next);
            result = std::max(result, evenLen);

            // Move forward
            prev = curr;
            curr = next;
        }

        return result;
    }
};