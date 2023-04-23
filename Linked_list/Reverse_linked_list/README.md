
# Recursive approach
<!-- Describe your approach to solving the problem. -->
* The function takes a pointer to the head of the list as input and returns a pointer to the new head of the reversed list.
* The function first checks if the list is empty or has only one element. If so, it returns the head as it is already reversed. Otherwise, it recursively calls the function with the next node as the new head.
* Once the recursive call returns, the function updates the next pointer of the next node to point to the current node (head), effectively reversing the link between the two nodes. It then sets the next pointer of the current node (head) to NULL to terminate the reversed list.
* Finally, the function returns the new head of the reversed list, which is the same as the head of the original list's last node.

# Complexity
- Time complexity:$$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:$$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *rev_head = reverseList(head->next);
        head->next->next  = head;
        head->next = NULL;
        return rev_head;
    }
};
```
# Iterative approach
<!-- Describe your approach to solving the problem. -->
* The function takes a pointer to the head of the list as input and returns a pointer to the new head of the reversed list.
* The function first checks if the list is empty or has only one element. If so, it returns the head as it is already reversed. Otherwise, it initializes three pointers - curr, prev, and forward. The curr pointer points to the current node being processed, prev points to the previous node, and forward points to the next node.
## The function then iterates through the list, updating the pointers as follows:

- Store the next node in the forward pointer.
- Set the next pointer of the current node to point to the previous node.
- Update the prev pointer to point to the current node.
- Update the curr pointer to point to the next node (stored in the forward pointer).
Once the iteration is complete, the prev pointer will be pointing to the new head of the reversed list, so the function returns it.
# Complexity
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:$$O(1)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *forward = NULL;

            while(curr != NULL)
            {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
    }
};
```