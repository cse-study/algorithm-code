#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
/*
    Programmers 입국심사 (https://programmers.co.kr/learn/courses/30/lessons/43238)

    Description: n명이 입국심사를 위해 줄을 서서 기다리고 있습니다. 각 입국심사대에 있는 심사관마다 심사하는데 걸리는 시간은 다릅니다.
    처음에 모든 심사대는 비어있습니다. 한 심사대에서는 동시에 한 명만 심사를 할 수 있습니다.
    가장 앞에 서 있는 사람은 비어 있는 심사대로 가서 심사를 받을 수 있습니다.
    하지만 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사를 받을 수도 있습니다.
    모든 사람이 심사를 받는데 걸리는 시간을 최소로 하고 싶습니다.
    입국심사를 기다리는 사람 수 n, 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times가 매개변수로 주어질 때,
    모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하도록 solution 함수를 작성해주세요.

    @author Yuho Jeong
 */

#include <iostream>
#include <vector>


long long solution(int n, std::vector<int> times) {
    long long answer = 0;
    long long max_time = 1e+18;
    long long min_time = 1;

    while (min_time <= max_time) {
        long long max_n = 0;
        long long mid_time = (max_time + min_time) / 2;

        for (int time: times) {
            max_n += mid_time / time;
        }

        // Update answer
        if (max_n >= n) {
            answer = mid_time;
            max_time = mid_time - 1;
        }
        else {
            min_time = mid_time + 1;
        }
    }

    return answer;
}


int main() {
    int n;
    int num_judge; int time;
    std::vector<int> times;

    // User input
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "num_judge: ";
    std::cin >> num_judge;
    std::cout << "times: ";
    for (int i = 0; i < num_judge; i++){
        std::cin >> time;
        times.push_back(time);
    }

    // Output
    std::cout << solution(n, times) << std::endl;
    return 0;
}
