class Solution {
public:
    int reverse(int x) {
        long res = 0;

        while (x) {
            res *= 10;
            int aux = x % 10;
            res += aux;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;
        return int(res);
    }
};