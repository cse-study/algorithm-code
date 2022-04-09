/**
 * Leetcode 509: Fibonacci Number
 * https://leetcode.com/problems/fibonacci-number/submissions/
 */

public class Solution {
    public int fib_recurrsive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib_recurrsive(n - 1) + fib_recurrsive(n - 2);
    }
}
