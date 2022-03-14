"""
백준 10828번 문제: 스택
https://www.acmicpc.net/problem/10828
"""
import sys


class Stack(object):
    def __init__(self):
        self.data = list()

    def __call__(self, command, X=None):
        if command == "push":
            assert X, "You must pass the number."
            self.data.append(X)

        elif command == "pop":
            if bool(self.data):
                print(self.data.pop())
            else:
                print(-1)

        elif command == "size":
            print(len(self.data))

        elif command == "empty":
            print(int(not bool(self.data)))

        elif command == "top":
            if bool(self.data):
                print(self.data[-1])
            else:
                print(-1)

        else:
            raise AssertionError


def main():
    num_iter = input()
    stack = Stack()

    for i in range(int(num_iter)):
        input_str = sys.stdin.readline().split()
        command = input_str[0]

        if command == "push":
            X = int(input_str[1])
            stack(command, X)
        else:
            stack(command)


if __name__ == "__main__":
    main()
