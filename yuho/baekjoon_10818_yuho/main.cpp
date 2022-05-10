/**
    Baekjoon 10818: 최소 최대 (https://www.acmicpc.net/problem/10818)
    @author Yuho Jeong
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N, number;
    std::cin >> N;
    std::vector<int> arr;

    // User input
    for(int i = 0; i < N; i++){
        std::cin >> number;
        arr.push_back(number);
    }

    // Sorting
    sort(arr.begin(), arr.end());

    // Output
    std::cout << arr.front() << " " << arr.back();
}
