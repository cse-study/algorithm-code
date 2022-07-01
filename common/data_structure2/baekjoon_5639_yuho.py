"""
Baekjoon 5639. 이진 검색 트리
https://www.acmicpc.net/problem/5639
문제: 이진 검색 트리는 다음과 같은 세 가지 조건을 만족하는 이진 트리이다.
1. 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
2. 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
3. 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.
전위 순회 (루트-왼쪽-오른쪽)은 루트를 방문하고, 왼쪽 서브트리, 오른쪽 서브 트리를 순서대로 방문하면서 노드의 키를 출력한다.
후위 순회 (왼쪽-오른쪽-루트)는 왼쪽 서브트리, 오른쪽 서브트리, 루트 노드 순서대로 키를 출력한다.
예를 들어, 위의 이진 검색 트리의 전위 순회 결과는 50 30 24 5 28 45 98 52 60 이고, 후위 순회 결과는 5 28 24 45 30 60 52 98 50 이다.
이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.
"""
import sys
import heapq
sys.setrecursionlimit(10**6)    # Recursive error 방지


class BinarySearchTree(object):
    def __init__(self):
        self.nodes = list()

    def __len__(self):
        return len(self.nodes)

    def push(self, x):
        self.nodes.append(x)

    def _traversal(self, start_idx, end_idx, root):
        left_start_idx, left_end_idx = None, None
        right_start_idx, right_end_idx = None, None

        if not end_idx < start_idx:
            for node_idx in range(start_idx, end_idx+1):
                if self.nodes[node_idx] < root:
                    if not left_start_idx:
                        left_start_idx = node_idx
                    left_end_idx = node_idx
                else:
                    if not right_start_idx:
                        right_start_idx = node_idx
                    right_end_idx = node_idx

        # Post-order
        if left_start_idx:
            self._traversal(left_start_idx + 1, left_end_idx, self.nodes[left_start_idx])
        if right_start_idx:
            self._traversal(right_start_idx + 1, right_end_idx, self.nodes[right_start_idx])
        print(root)

    def pre2post(self):
        """ Main algorithm
        Recursive 돌면서 node 끝까지 탐색하고,
        자식 노드가 이미 탐색을 끝낸 노드이거나, 말단 노드인 경우에 해당 노드 print
        """
        self._traversal(start_idx=1, end_idx=len(self.nodes)-1, root=self.nodes[0])
        pass


def main():
    tree = BinarySearchTree()
    while True:
        try:
            num = int(input())
            tree.push(num)
        except:
            break

    tree.pre2post()


if __name__ == "__main__":
    main()
