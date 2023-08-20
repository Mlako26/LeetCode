class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res;
        int divisor = 2*k + 1;
        
        if (nums.size() < divisor) {
            for (int i = 0; i < nums.size(); i++) res.push_back(-1);
            return res;
        }
            
        int i = 0;
        while (i - k < 0) {
            res.push_back(-1);
            i++;
        }
        
        long long sum = 0;
        for (int j = i - k; j <= i + k; j++) sum += nums[j];
        res.push_back(int(sum / divisor));
        i++;
        while (i + k < nums.size()) {
            sum -= nums[i-k-1];
            sum += nums[i+k];
            res.push_back(int(sum / divisor));
            i++;
        }
        
        while (i < nums.size()) {
            res.push_back(-1);
            i++;
        }
        
        return res;
    }
};