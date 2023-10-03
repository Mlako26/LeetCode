class Solution {
public:
vector<int> visited;

vector<int> dfs(vector<vector<int>>& g, int i) {
    vector<int> topSort;
    visited[i] = 0;
    for (int j : g[i]) {
        if (visited[j] == 0) return {};
        if (visited[j] == -1) {
            vector<int> aux = dfs(g,j);
            if (!aux.size()) return {};
            for (int x : aux) topSort.push_back(x);
        }
    }
    visited[i] = 1;
    topSort.push_back(i);
    return topSort;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    visited.resize(numCourses, -1); 

    for (int i = 0; i < prerequisites.size(); i++) {
        if (prerequisites[i][1] == prerequisites[i][0]) return {};
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    
    vector<int> ans;
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == -1) {
            vector<int> aux = dfs(g,i);
            if (!aux.size()) return {};
            for (auto x : aux) ans.push_back(x);
        }
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
};