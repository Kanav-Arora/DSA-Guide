# Intuition
The problem requires us to create a deep copy of a linked list with random pointers. To achieve this, we need to create new nodes for each original node while maintaining the connections between the nodes in both the `next` and `random` pointers. We can achieve this in three steps:
1. Duplicate each node and insert it after the original node.
2. Assign the random pointers of the duplicated nodes based on the original random pointers.
3. Separate the original and copied linked lists.

# Approach
1. Duplicate each node: Traverse the original linked list, and for each node, create a new node with the same value. Insert the new node after the current node and move to the next node in the original list.

2. Assign random pointers: Traverse the linked list again, but this time, update the random pointers of the copied nodes based on the original random pointers. For each node `temp`, if `temp->random` exists, then the random pointer of the corresponding copied node `temp->next` should point to `temp->random->next`.

3. Separate the lists: Traverse the linked list again, this time separating the original and copied lists by adjusting the `next` pointers of each node. Restore the original list's `next` pointers while keeping the copied list's `next` pointers intact. The copied list's head is the second node of the original list, and the original list's head remains unchanged.

# Complexity
- Time complexity: The algorithm traverses the linked list three times sequentially. Each traversal takes linear time, so the overall time complexity is O(n).
- Space complexity: The space complexity is also O(n) as we are creating n new nodes in the copied linked list.

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
        if(head==NULL)  return NULL;
        Node* temp = head;
        while(temp)
        {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = n->next;
        }

        temp = head;

        while(temp)
        {
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node *newHead = head->next;
        temp = head;

        while(temp)
        {
            Node* n = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            if(temp)
            {
                n->next = temp->next;
            }
            // if (n->next) {
            //     n->next = n->next->next;
            // }
        }

        return newHead;
    }
};
```