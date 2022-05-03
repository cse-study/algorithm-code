"""
Baekjoon 1427. 소트인사이드
https://www.acmicpc.net/problem/1427
문제: 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
입력: 첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.
출력: 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
"""


class DecimalSort(object):
    def __init__(self, number: int):
        self.num_decimal = self._set_num_decimal(number)        # 자릿수
        self.decimal_coef = self._set_decimal_coef(number)      # 각 자릿수의 숫자

    @staticmethod
    def _set_num_decimal(number: int) -> int:
        """ 입력 숫자가 몇 자리인지 계산
        Ex) 2134 -> 4
        """
        counter = 0
        while number != 0:
            number = int(number / 10)
            counter += 1
        return counter

    def _set_decimal_coef(self, number: int) -> list:
        """ 입력 숫자의 각 자리 계수 저장
        Ex) 2134 -> [2, 1, 3, 4]
        """
        decimal_coef = [0] * self.num_decimal
        current_value = number

        for i in range(self.num_decimal):
            next_value = int(current_value / 10)
            current_coef = int(current_value - next_value * 10)

            idx = - i - 1
            decimal_coef[idx] = current_coef
            current_value = next_value

        return decimal_coef

    def run(self):
        self.decimal_coef.sort()    # 정렬 내장 함수
        result = 0
        decimal = 1

        for i in range(self.num_decimal):
            result += self.decimal_coef[i] * decimal
            decimal *= 10

        print(result)


def main():
    algorithm = DecimalSort(int(input()))
    algorithm.run()


if __name__ == "__main__":
    main()
