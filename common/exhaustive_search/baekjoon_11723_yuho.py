"""
Baekjoon 11723. 집합
https://www.acmicpc.net/problem/11723

문제: 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
     add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
     remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
     check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
     toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
     all: S를 {1, 2, ..., 20} 으로 바꾼다.
     empty: S를 공집합으로 바꾼다.

입력: 첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
     둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.
출력: check 연산이 주어질때마다, 결과를 출력한다.

"""
import sys


class BitMasking(object):
    def __init__(self):
        self.S = [False] * 20     # 집합 S

    def __call__(self, command):
        self._dispatch(command)

    def _dispatch(self, command):
        if len(command) == 1:
            cmd = command[0]
            if cmd == "all":
                self.S = [True] * 20
            elif cmd == "empty":
                self.S = [False] * 20
            else:
                self._err(command)
        elif len(command) == 2:
            cmd, num = command[0], int(command[1])
            if command[0] == "add":
                self.S[num - 1] = True
            elif command[0] == "remove":
                self.S[num - 1] = False
            elif command[0] == "check":
                print(int(self.S[num - 1]))
            elif command[0] == "toggle":
                self.S[num - 1] = not self.S[num - 1]
            else:
                self._err(command)
        else:
            self._err(command)

    def _err(self, command):
        raise AssertionError(f"Check the case: {command}")


def main():
    bitmask = BitMasking()
    for _ in range(int(input())):
        command = sys.stdin.readline().split()
        bitmask(command)


if __name__ == "__main__":
    main()
