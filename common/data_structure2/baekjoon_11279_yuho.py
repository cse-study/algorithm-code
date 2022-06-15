"""
Baekjoon 11279. 최대 힙
https://www.acmicpc.net/problem/11279
문제: 널리 잘 알려진 자료구조 중 최대 힙이 있다. 최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
1. 배열에 자연수 x를 넣는다.
2 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
"""
import sys
import heapq


class MaxHeap(object):
    def __init__(self):
        # heapq가 최소 힙이기 때문에, 최대 힙을 최소힙의 negative 형태로 구현
        self.negative_heap = list()

    def __call__(self, x):
        if x == 0:
            print(-heapq.heappop(self.negative_heap)) if self.negative_heap else print(0)
        else:
            self._push(x)

    def _push(self, x):
        heapq.heappush(self.negative_heap, -x)


def main():
    heap = MaxHeap()
    for _ in range(int(input())):
        x = int(sys.stdin.readline().split()[0])
        heap(x)


if __name__ == "__main__":
    main()
