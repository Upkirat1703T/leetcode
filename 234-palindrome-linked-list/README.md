# LeetCode 234 - Palindrome Linked List

## 1. Intuition

The goal is to determine whether a singly linked list reads the same forwards and backwards.

A straightforward solution is to copy the values into an array and use two pointers to check if the array is a palindrome. However, this requires **O(n)** extra space.

A more optimal approach is to use the linked list itself:
- Find the middle of the list using the slow and fast pointer technique.
- Reverse the second half of the list.
- Compare the first half with the reversed second half.

This achieves **O(n)** time complexity while using **O(1)** extra space.

---

## 2. Approach

1. If the list contains zero or one node, it is already a palindrome.
2. Use two pointers:
   - `slow` moves one step at a time.
   - `fast` moves two steps at a time.
3. When `fast` reaches the end, `slow` will point to the middle of the list.
4. Reverse the second half of the linked list starting from `slow`.
5. Compare the nodes of the first half with the nodes of the reversed second half.
6. If any pair of values is different, return `false`.
7. If all corresponding nodes match, return `true`.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)**

---

## 3. Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : next(next), val(x) {}
 * };
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```
