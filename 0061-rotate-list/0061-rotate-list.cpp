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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* it = head;
        int size = 1;
        while (it->next) {
            size++;
            it = it->next;
        }

        k = k % size;
        
        if (k == 0) return head;
        it->next = head;
        it = head;
        int pos = size - k - 1;
        while (pos--) it = it->next;
        head = it->next;
        it->next = nullptr;

        return head;

    }
};