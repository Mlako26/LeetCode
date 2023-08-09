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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev, *cur = head, *aux;        
        head = head->next;
        
        while (cur && cur->next) {
            prev = cur;
            cur = cur->next;
            
            prev->next = cur->next;
            cur->next = prev;
            cur = prev->next;
            if (cur && cur->next) prev->next = cur->next;
        }
        
        return head;
    }
};