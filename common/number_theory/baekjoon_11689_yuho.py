"""
Baekjoon 11689. GCD(n, k) = 1
https://www.acmicpc.net/problem/11689
"""


class EulerPhi(object):
    def __init__(self, n):
        self.n = n              # 입력 n
        self.remainder = n      # n의 약수로 계속해서 나눠 줄 변수
        self.result = n         # 오일러파이 결과

    def run(self):
        for i in range(2, int(self.n ** 0.5) + 1):
            if self.remainder % i == 0:             # 소인수 분해
                self.result *= 1 - (1 / i)          # 오일러파이 식 적용
                while self.remainder % i == 0:      # 중복 소인수 제거
                    self.remainder = self.remainder // i

        # n이 소수인 경우
        if self.remainder != 1:
            self.result *= 1 - (1 / self.remainder)

        return int(self.result)


def main():
    n = int(input())
    ephi = EulerPhi(n)
    print(ephi.run())


if __name__ == "__main__":
    main()
