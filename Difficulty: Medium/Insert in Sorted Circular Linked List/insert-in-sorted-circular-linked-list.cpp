/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
    public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
        
        // Case: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;
        Node* nextNode = head->next;

        // Special case: insert before head (new smallest or largest element)
        if (data <= head->data || data >= getTail(head)->data) {
            // Insert before head or after tail
            Node* tail = getTail(head);
            tail->next = newNode;
            newNode->next = head;

            // If data is smaller than head, update head
            if (data < head->data)
                return newNode;
            else
                return head;
        }

        // General case: insert in middle
        while (curr->next != head && !(curr->data <= data && data <= curr->next->data)) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        return head;
    }

  private:
    Node* getTail(Node* head) {
        Node* curr = head;
        while (curr->next != head)
            curr = curr->next;
        return curr;
    }
};