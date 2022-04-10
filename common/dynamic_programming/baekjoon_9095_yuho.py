"""
Baekjoon 9095. 1, 2, 3 더하기
https://www.acmicpc.net/problem/9095
"""
import sys


class DynamicOperator(object):
    def __init__(self, target):
        self.target = target
        self.counter = 0
        self.subtractor = [1, 2, 3]

    def _check_end(self, target):
        """ Add 1 to counter when the input number is 0
        :param target: input number
        :return: boolean flag for the recursive function termination
        """
        if target == 0:
            self.counter += 1
            return True
        elif target < 0:
            return True
        else:
            return False

    def _subtract_recursion(self, target):
        if not self._check_end(target):
            for elem in self.subtractor:
                self._subtract_recursion(target - elem)

    def run(self):
        """ Run `subtract_recursion` function recursively and return counter
        :return: counter
        """
        self._subtract_recursion(self.target)
        return self.counter


def main():
    num_test = input()

    for i in range(int(num_test)):
        target = sys.stdin.readline().split()
        dynamic_op = DynamicOperator(int(target[0]))
        output = dynamic_op.run()
        print(output)


if __name__ == "__main__":
    main()
