class Solution {
public:
    int fib(size_t n) {
        if(n < 1)
            return 0;
        int prev = 0;
        int curr = 1;
        for(size_t i = 2; i <= n; i++) {
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};