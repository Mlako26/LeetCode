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
        map<Node*, Node*> aux;
        
        Node* it = head;
        while (it) {
            aux[it] = new Node(it->val);
            it = it->next;
        }
        
        it = head;
        while (it) {
            aux[it]->next = aux[it->next];
            aux[it]->random = aux[it->random];
            it = it->next;
        }
        
        return aux[head];
    }
};