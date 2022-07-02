"""
Baekjoon 5557. 1학년
https://www.acmicpc.net/problem/5557

문제: 상근이가 1학년 때, 덧셈, 뺄셈을 매우 좋아했다.
상근이는 숫자가 줄 지어있는 것을 보기만 하면, 마지막 두 숫자 사이에 '='을 넣고, 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만들며 놀고 있다.
예를 들어, "8 3 2 4 8 7 2 4 0 8 8"에서 등식 "8+3-2-4+8-7-2-4-0+8=8"을 만들 수 있다.
상근이는 올바른 등식을 만들려고 한다. 상근이는 아직 학교에서 음수를 배우지 않았고, 20을 넘는 수는 모른다.
따라서, 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다.
예를 들어, "8+3+2-4-8-7+2+4+0+8=8"은 올바른 등식이지만, 8+3+2-4-8-7이 음수이기 때문에, 상근이가 만들 수 없는 등식이다.
숫자가 주어졌을 때, 상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오.
"""
import sys


class EquationCasesCounter(object):
    def __init__(self, total_sequence):
        self.num_cases = 0
        self.total_left_sequence = total_sequence[:-1]
        self.right_eq_result = total_sequence[-1]

    def _recursion(self, left_eq_result, remaining_sequence):
        if len(remaining_sequence) == 0:
            if left_eq_result == self.right_eq_result:
                self.num_cases += 1
        else:
            if 0 <= left_eq_result <= 20:
                self._recursion(left_eq_result + remaining_sequence[0], remaining_sequence[1:])
                self._recursion(left_eq_result - remaining_sequence[0], remaining_sequence[1:])

    def fit(self):
        self._recursion(self.total_left_sequence[0], self.total_left_sequence[1:])
        return self.num_cases


def main():
    # Get user input
    num = int(input())
    sequence = [int(token) for token in sys.stdin.readline().split()]
    counter = EquationCasesCounter(sequence)
    num_cases = counter.fit()

    # Print results
    print(num_cases)


if __name__ == "__main__":
    main()
