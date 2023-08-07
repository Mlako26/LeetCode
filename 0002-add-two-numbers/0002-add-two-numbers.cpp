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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        ListNode* prev = nullptr;

        while (l1 && l2) {
            // Calculating new value
            int value = l1->val + l2->val;
            if (remainder) {
                value++;
                remainder--;
            }
            if (value > 9) {
                value -= 10;
                remainder++;
            }
            
            // Linking new node
            cur = new ListNode(value);
            if (prev) prev->next = cur;
            prev = cur;
            if (!res) res = cur; // First node

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            // Calculating new value
            int value = l1->val;
            if (remainder) {
                value++;
                remainder--;
            }
            if (value > 9) {
                value -= 10;
                remainder++;
            }
            
            // Linking new node
            cur = new ListNode(value);
            if (prev) prev->next = cur;
            prev = cur;

            l1 = l1->next;
        }

        while (l2) {
            // Calculating new value
            int value = l2->val;
            if (remainder) {
                value++;
                remainder--;
            }
            if (value > 9) {
                value -= 10;
                remainder++;
            }
            
            // Linking new node
            cur = new ListNode(value);
            if (prev) prev->next = cur;
            prev = cur;

            l2 = l2->next;
        }

        if (remainder) {
            cur = new ListNode(1);
            prev->next = cur;
        }

        return res;
    }
};