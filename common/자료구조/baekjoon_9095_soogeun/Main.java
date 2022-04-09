/**
 * Baekjoon 9095 1,2,3 더하기
 * https://www.acmicpc.net/problem/9095
 */

package baekjoon_9095;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfLines = Integer.parseInt(br.readLine());

        for (int i = 0; i < numOfLines; i++) {
            int input = Integer.parseInt(br.readLine());
            System.out.println(calculateCombinations(input));
        }

        br.close();
    }

    /**
     * input으로 받는 정수를 1, 2, 3의 합으로 나타낼 수 있는 경우의 수를 반환하는 함수
     * 점화식 f(n) = f(n-1) + f(n-2) + f(n-3)으로 풀이
     * < 알고리즘 해석 >
     * f(n)의 케이스는 {1, f(n-1)}, {2, f(n-2)}, {3, f(n-3)}의 경우의 수로 표현할 수 있다.
     */
    static private long calculateCombinations (int input) {
        if (input <= 0) {
            throw new Error("Input should be an positive integer.");
        }

        /**
         * 전역 함수에서 선언된 상수이기 때문에, 함수 밖에 선언되거나 함수 안에 선언되거나의 차이는 없다.
         * (소요된 memory, time에 변화 없음)
         */
        final int SOLUTION_OF_ONE   = 1;    // {1}
        final int SOLUTION_OF_TWO   = 2;    // {1, 1}, {2}
        final int SOLUTION_OF_THREE = 4;    // {1, 1, 1}, {1, 2}, {2, 1}, {3}
        
        if (input == 1) return SOLUTION_OF_ONE;
        if (input == 2) return SOLUTION_OF_TWO;
        if (input == 3) return SOLUTION_OF_THREE;
        
        long[] solArr = new long[input];
        
        solArr[0] = SOLUTION_OF_ONE;  
        solArr[1] = SOLUTION_OF_TWO;  
        solArr[2] = SOLUTION_OF_THREE;  

        for (int i = 3; i < input; i++) {
            solArr[i] = solArr[i - 1] + solArr[i - 2] + solArr[i - 3];
        }

        return solArr[input - 1];
    } 
}
