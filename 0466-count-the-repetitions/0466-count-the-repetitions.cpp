class Solution {
public:
    int getMaxRepetitions(string s1, int m1, string s2, int m2) {
        int n1 = s1.size(), n2 = s2.size();

        vector<pair<int, int>> primerAparicion(n1, {-1, -1});
        primerAparicion[0] = {0, 0};

        int i_final = -1;
        int dist_ciclo = 1;
        int counts_ciclo = 0;
        int actual = 0, count = 0;

        int mn = n1 * min(m1, n2 * n1);
        for(int i = 0; i < mn; ++i) {
            char c = s1[i % n1];
            if(s2[actual] == c) {
                actual = (actual + 1) % n2;
                if(!actual) {
                    ++count;
                    int pos = (i+1) % n1;
                    if(primerAparicion[pos].first != -1) {
                        i_final = i+1;
                        dist_ciclo = (i+1) - primerAparicion[pos].first;
                        counts_ciclo = count - primerAparicion[pos].second;
                        break;
                    } 
                    primerAparicion[pos] = {i+1, count};
                } 
            }
        }

        count += ((n1 * m1 - i_final)/dist_ciclo) * counts_ciclo;
        
        actual = 0;
        for(int i = 0; i < (n1 * m1 - i_final) % dist_ciclo; ++i) {
            int pos = (i_final + i) % n1;
            char c = s1[pos];
            if(s2[actual] == c) {
                actual = (actual + 1) % n2;
                if(!actual) ++count;
            }
        }

        return count / m2;
    }
};
