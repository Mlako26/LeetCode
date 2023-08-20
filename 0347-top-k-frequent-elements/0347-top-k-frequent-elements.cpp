class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector<pair<int,int>> app;
        map<int, int> aux;
        for (int x : nums) {
            aux[x]++;
        }
        
        for (pair<int,int> p : aux) {
            app.push_back({p.second, p.first});
        }
        
        sort(app.begin(), app.end(), greater<pair<int,int>>());
        int i = 0;
        while (k--) {
            res.push_back(app[i].second);
            i++;
        }
        
        return res;
    }
};