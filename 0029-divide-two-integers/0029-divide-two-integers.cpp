class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int neg = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long res = 0, dvd = labs(dividend), dvr = labs(divisor);
        while (dvd >= dvr) {
            long m = 1, temp = dvr;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            res += m;
            dvd -= temp;
        }
        return neg * res;
    }
};