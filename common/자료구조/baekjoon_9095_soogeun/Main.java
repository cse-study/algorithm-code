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
            System.out.println(input);
        }

        br.close();
    }
}
