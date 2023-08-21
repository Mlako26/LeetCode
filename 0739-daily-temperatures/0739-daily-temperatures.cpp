class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<pair<int,int>> waiting;
        waiting.push_back({temperatures[0], 0});
        for (int i = 1; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            if (waiting.back().first >= temp) waiting.push_back({temp, i});
            else {
                while (waiting.size() && waiting.back().first < temp) {
                    res[waiting.back().second] = i - waiting.back().second;
                    waiting.pop_back();
                }
                waiting.push_back({temp, i});
            }
        }

        return res;
    }

};