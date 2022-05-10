/**
    Baekjoon 2739: 구구단 (https://www.acmicpc.net/problem/2739)
    @author Yuho Jeong
*/

#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for(int i = 1; i < 10; i++){
        std::cout << N << " * " << i << " = " << N * i;
        std::cout << std::endl;
    }

    return 0;
}
