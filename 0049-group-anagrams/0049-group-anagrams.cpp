class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        vector<pair<string,int>> aux;
        for (int i = 0; i < strs.size(); i++) {
            aux.push_back({strs[i], i});
        }
        
        for (int i = 0; i < aux.size(); i++) {
            sort((aux[i].first).begin(), (aux[i].first).end());
        }
        sort(aux.begin(), aux.end());
        
        vector<string> cur;
        for (int i = 0; i < aux.size() - 1; i++) {
            cur.push_back(strs[aux[i].second]);
            
            if (aux[i].first != aux[i+1].first) {
                res.push_back(cur);
                cur.clear();
            }
        }
        cur.push_back(strs[aux[aux.size() - 1].second]);
        res.push_back(cur);
        
        return res;
    }
};