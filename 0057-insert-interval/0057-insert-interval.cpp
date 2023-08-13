class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        
        bool done = false;
        int i = 0;
        while (i < intervals.size()) {
            if (intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
            else if (intervals[i][0] > newInterval[1]) { //Non-overlapping
                res.push_back(newInterval);
                done = true;
                break;
            } else {
                int start = min(intervals[i][0], newInterval[0]);
                int end = max(intervals[i][1], newInterval[1]);
                while (++i < intervals.size() && intervals[i][0] <= end) {
                    end = max(end, intervals[i][1]);
                }
                res.push_back({start, end});
                done = true;
                break;
            }

        }
        
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        
        if (!done) res.push_back(newInterval);
        
        return res;
    }
};