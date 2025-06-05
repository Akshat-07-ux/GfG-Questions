/*Complete the function below
Node is as follows:
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
    struct Node* modifyTheList(struct Node* head) {
        if (!head || !head->next) return head;

        // Step 1: Store node pointers and values in a vector
        vector<Node*> nodes;
        Node* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int n = nodes.size();
        int half = n / 2;

        // Step 2: Store original first half values
        vector<int> firstHalfOriginal;
        for (int i = 0; i < half; ++i) {
            firstHalfOriginal.push_back(nodes[i]->data);
        }

        // Step 3: Modify first half
        for (int i = 0; i < half; ++i) {
            nodes[i]->data = nodes[n - 1 - i]->data - nodes[i]->data;
        }

        // Step 4: Replace second half with original values from first half
        for (int i = 0; i < half; ++i) {
            nodes[n - 1 - i]->data = firstHalfOriginal[i];
        }

        return head;
    }
};