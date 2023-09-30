/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> visited;
    Node* dfs(Node* node) {
        Node* v = new Node(node->val);
        visited[node->val] = v;
        for (auto u : node->neighbors) {
            if (!visited[u->val]) dfs(u);
            v->neighbors.push_back(visited[u->val]);
        }
        return v;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        visited.resize(101, nullptr);
        return dfs(node);
    }
};