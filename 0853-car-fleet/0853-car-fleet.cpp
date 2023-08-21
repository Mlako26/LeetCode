class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> aux;
        int n = position.size();
        
        for (int i = 0; i < n; i++) aux.push_back({position[i],(double)(target-position[i])/speed[i]});
        sort(aux.begin(), aux.end(), greater<pair<int,int>>());
        
        double slowest = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (aux[i].second > slowest) {
                slowest = aux[i].second;
                res++;
            }
        }
        return res;
    }
};