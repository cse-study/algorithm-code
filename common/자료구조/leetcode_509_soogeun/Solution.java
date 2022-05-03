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

    public int fib_array(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int[] solArr = new int[n + 1];
        solArr[0] = 0;
        solArr[1] = 1;

        for (int i = 2; i <= n; i++) {
            solArr[i] = solArr[i - 1] + solArr[i - 2];
        }

        return solArr[n];
    }
}
