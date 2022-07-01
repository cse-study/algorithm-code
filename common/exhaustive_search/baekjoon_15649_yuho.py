"""
Baekjoon 15649. N과 M (1)
https://www.acmicpc.net/problem/15649

문제: 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
     - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

입력: 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
출력: 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
     수열은 사전 순으로 증가하는 순서로 출력해야 한다.

"""
import sys


class Backtracking(object):
    def __init__(self, N, M):
        self.N = N      # 자연수 최대값
        self.M = M      # 수열의 길이

    def run(self, except_list):
        if len(except_list) < self.M:
            for i in range(1, self.N + 1):
                if i not in except_list:
                    next_except_list = except_list[:]
                    next_except_list.append(i)
                    self.run(next_except_list)
        else:
            print(*except_list)


def main():
    user_input = sys.stdin.readline().split()
    N, M = int(user_input[0]), int(user_input[1])
    backtracking = Backtracking(N, M)
    backtracking.run([])


if __name__ == "__main__":
    main()
