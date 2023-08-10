class Solution {
public:
    string countAndSay(int n) {
        int i = 1;
        string res = "1", aux;
        
        if (n == 1) return res;
        
        while (i < n) {
            aux = "";
            char last = res[0];
            int amount = 0;
            for (char c : res) {
                if (c == last) amount++;
                else {
                    aux += to_string(amount);
                    aux.push_back(last);
                    last = c;
                    amount = 1;
                }
            }
            aux += to_string(amount);
            aux.push_back(last);
            res = aux;
            i++;
        }
        
        return res;
    }
};