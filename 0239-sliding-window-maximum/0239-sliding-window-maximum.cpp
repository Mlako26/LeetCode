class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> used;
        vector<int> heap, res;
        int i = 0;

        while (i < k) {
            heap.push_back(nums[i]);
            i++;
        }
        make_heap(heap.begin(), heap.end());
        res.push_back(heap.front());

        while (i < nums.size()) {
            heap.push_back(nums[i]); push_heap(heap.begin(), heap.end());
            used[nums[i-k]]++;
            while (used[heap.front()]) {
                used[heap.front()]--;
                pop_heap(heap.begin(), heap.end()); heap.pop_back();
            }
            res.push_back(heap.front());
            i++;
        }
        
        return res;
    }
};