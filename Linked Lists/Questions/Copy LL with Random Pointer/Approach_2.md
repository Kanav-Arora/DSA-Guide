# Intuition
The problem requires us to create a deep copy of a linked list with random pointers. To achieve this, we can use a hashmap to keep track of the mapping between original nodes and their corresponding copied nodes. This way, we can efficiently connect the `next` and `random` pointers of the copied nodes based on the mapping. 

# Approach
1. Check if the `head` is NULL: If the given `head` is NULL, it means the linked list is empty, so we return NULL for the copied linked list.

2. Create a copy of the `head`: Create a new node `clonehead` with the same value as `head` to serve as the head of the copied linked list. Also, create two pointers `temp` and `temp2`, initialized to `head` and `clonehead`, respectively.

3. Duplicate each node and build the copied linked list: Traverse the original linked list using the `temp` pointer. For each node in the original list, create a new node with the same value, and connect it to the copied list by setting `temp2->next` to the new node. Move both `temp` and `temp2` to their next nodes.

4. Build the mapping between original and copied nodes: Use an unordered map `mapping` to store the mapping between original nodes and their corresponding copied nodes. Traverse the original list again using the `temp` pointer, and for each node, insert the mapping into the `mapping` hash table with the original node as the key and the copied node as the value. Move both `temp` and `temp2` to their next nodes.

5. Connect the random pointers: Traverse the original list again using the `temp` pointer, and for each node, find the corresponding copied node using the `mapping` hash table. Set the `random` pointer of the copied node (`temp2->random`) to the copied node corresponding to the original node's `random` pointer (`mapping[temp->random]`). Move both `temp` and `temp2` to their next nodes.

6. Return the copied linked list: Now, the copied linked list is ready with all connections, including `next` and `random` pointers, based on the original linked list.

# Complexity
- Time complexity: The algorithm traverses the original linked list three times sequentially. Each traversal takes linear time, so the overall time complexity is O(n).
- Space complexity: The space complexity is O(n) because we use an unordered map to store the mapping between original and copied nodes, which can have a maximum of n entries.

The code provided above implements this approach and provides a deep copy of the given linked list with random pointers.

# Code
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        return NULL;

    Node *clonehead = new Node(head->data);
    Node *temp = head->next;
    Node *temp2 = clonehead;

    while (temp != NULL)
    {
        Node *n = new Node(temp->data);
        temp2->next = n;
        temp2 = temp2->next;
        temp = temp->next;
    }

    unordered_map<Node *, Node *> mapping;
    temp = head;
    temp2 = clonehead;
    while (temp != NULL)
    {
        mapping[temp] = temp2;

        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = clonehead;

    while (temp != NULL)
    {
        temp2->random = mapping[temp->random];

        temp = temp->next;
        temp2 = temp2->next;
    }

    return clonehead;
    }
};
```