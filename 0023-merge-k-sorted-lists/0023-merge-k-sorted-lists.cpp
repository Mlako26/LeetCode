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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left && !right) return nullptr;
        if (!right) return left;
        if (!left) return right;
        
        ListNode* prev, *head;
        if (left->val < right->val) {
            prev = left;
            left = left->next;
        } else {
            prev = right;
            right = right->next;
        }
        head = prev;
        
        while (left && right) {
            if (left->val < right->val) {
                prev->next = left;
                left = left->next;
                prev = prev->next;
            } else {
                prev->next = right;
                right = right->next;
                prev = prev->next;
            }
        }
        
        if (left) prev->next = left;
        if (right) prev->next = right;
        
        return head;
    }
    
    ListNode* solve(vector<ListNode*>& lists, int i, int j) {
        if (i == j) return lists[i];
        ListNode* left = solve(lists, i, (i + j) / 2);
        ListNode* right = solve(lists, (i + j) / 2 + 1, j);
        
        ListNode* head = merge(left, right);
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return solve(lists, 0, lists.size() - 1);
    }
};