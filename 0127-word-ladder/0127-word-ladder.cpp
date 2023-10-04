class Solution {
public:

vector<int> bfs(vector<vector<int>>& adj, int i) {
    vector<int> visited(adj.size(), -1);
    visited[i] = 0;
    list<int> q;
    q.push_back(i);

    while (q.size()) {
        int v = q.front();
        q.pop_front();
        for (auto u : adj[v]) {
            if (visited[u] == -1) {
                visited[u] = visited[v] + 1;
                q.push_back(u);
            }
        }
    }
    return visited;
}

bool dist(string& s, string& t) {
    bool ans = false;
    for (int k = 0; k < s.size(); k++) {
        if (s[k] != t[k]) {
            if (ans) return false;
            else ans = true;
        }
    }
    return ans;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int n = wordList.size(), pos = -1;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        string s = wordList[i];
        if (s == endWord) pos = i;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            string t = wordList[j];
            bool d = dist(s,t);
            if (d) adj[i].push_back(j);
        }
    }
    
    if (pos == -1) return 0;
    vector<int> ans = bfs(adj, n-1);
    return ans[pos] + 1;
}
};