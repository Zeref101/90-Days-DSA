# Approach
<!-- Describe your approach to solving the problem. -->
## length1 function:
The function first defines a helper function called  length1  that takes a pointer to the head of the list as input and returns the length of the list. The function initializes a variable  len  to 0 and iterates through the list, incrementing  len  for each node in the list. Once the end of the list is reached (i.e.,  head  is null), the function returns  len .
## main:
* The main function then calculates the index of the middle node by dividing the length of the list by 2. It then iterates through the list  mid  times, where  mid  is the index of the middle node. During each iteration, it moves the  head  pointer to the next node in the list. Once the  head  pointer has been moved  mid  times, it points to the middle node of the list.
* Finally, the function returns the head pointer, which points to the middle node of the list.
# Complexity
- Time complexity:$$O(n)$$
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
    int length1(ListNode *head)
    {
        int len = 0;
        while(head!=NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int mid = length1(head)/2;
        while(mid)
        {
            head = head->next;
            mid--;
        }
        return head;
    }
};
```