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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* it = head;
        while (it) {
            size++;
            it = it->next;
        }
        it = head;
        
        int fromhead = size - n;        
        ListNode* prev = nullptr;
        while (fromhead > 0) {
            prev = it;
            it = it->next;
            fromhead--;
        }
        
        if (!prev) {
            it = it->next;
            delete head;
            head = it;
        } else if (!it->next) {
            delete it;
            prev->next = nullptr;
        } else {
            prev->next = it->next;
            delete it;
        }
        
        return head;
    }
};