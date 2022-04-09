"""
Baekjoon 15965. K번째 소수
https://www.acmicpc.net/problem/15965
"""
import sys


class Eratosthenes(object):
    def __init__(self, upper_bound=7500000):
        self.remainder = [True] * upper_bound
        self.upper_bound = upper_bound
        self.max_num = int(upper_bound ** 0.5) + 1
        self.prime_list = list()
        self.remainder[0] = False
        self.remainder[1] = False

    def _check_prime_number(self, target):
        """ max_num 이하의 소수를 모두 찾는 함수 """
        if self.prime_list:     # Except the number 2 (empty list)
            for i in self.prime_list:
                if target % i == 0:
                    return False
        return True

    def _remove_multiples(self, prime_number):
        """ 에라토스테네스 체 수행 """
        n_iters = self.upper_bound // prime_number
        for i in range(n_iters):
            if i != 0 and i != 1:
                self.remainder[prime_number * i] = False

    def run(self, k):
        for i in range(2, self.max_num):
            if self._check_prime_number(i):
                self.prime_list.append(i)
                self._remove_multiples(i)

        # K 번째 소수 출력
        count = 0
        for i, v in enumerate(self.remainder):
            if v:
                count += 1
            if count == k:
                return i


def main():
    k = int(sys.stdin.readline().split()[0])
    etns = Eratosthenes()
    result = etns.run(k)
    print(result)


if __name__ == "__main__":
    main()
