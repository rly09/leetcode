class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Handle overflow case directly
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        quotient = sign ? quotient : -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        return (int)quotient;
    }
};
