class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> aux;
        for (int x : nums) {
            if (aux.count(x)) return true;
            aux[x] = true;
        }
        return false;
    }
};