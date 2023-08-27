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
    ListNode* cur;
    bool done;
    void changeBack(ListNode* it) {
        if (!it) return;

        changeBack(it->next);

        if (done) return;
        if (cur == it || it == cur->next) {
            it->next = nullptr;
            done = true;
        } else {
            ListNode* aux = cur->next;
            cur->next = it;
            cur = aux;
            it->next = cur;
        }
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        cur = head;     
        done = false;
        changeBack(head);
    }
};