"""
백준 10866번 문제: 덱
https://www.acmicpc.net/problem/10866
"""
import sys


class Deque(object):
    def __init__(self):
        # Deque list
        self._data = []

    def __call__(self, cmd, X=None):
        # 리턴 할 내용
        elem = None

        # 명령어에 따른 작업 수행
        if cmd == "push_front":
            self._data.insert(0, X)

        elif cmd == "push_back":
            self._data.append(X)

        elif cmd == "pop_front":
            if self._check_data():
                elem = self._data.pop(0)
            else:
                elem = -1

        elif cmd == "pop_back":
            if self._check_data():
                elem = self._data.pop()
            else:
                elem = -1

        elif cmd == "size":
            elem = len(self._data)

        elif cmd == "empty":
            elem = int(not self._check_data())

        elif cmd == "front":
            if self._check_data():
                elem = self._data[0]
            else:
                elem = -1

        elif cmd == "back":
            if self._check_data():
                elem = self._data[-1]
            else:
                elem = -1

        else:
            raise AssertionError

        # elem에 담긴 값 있을 시 해당 값 print
        if elem is not None:
            print(elem)

    def _check_data(self):
        """ Deque에 데이터가 들어있는지 확인하는 함수
        :return: 데이터 존재 시 True, 존재하지 않을 시 False 리턴
        """
        if len(self._data) == 0:
            return False
        else:
            return True


def main():
    num_cmd = input()   # 명령의 수
    deque = Deque()     # Deque object initialize

    for i in range(int(num_cmd)):
        input_str = sys.stdin.readline().split()
        cmd = input_str[0]

        if len(input_str) > 1:
            deque(cmd, int(input_str[1]))
        else:
            deque(cmd)


if __name__ == "__main__":
    main()
