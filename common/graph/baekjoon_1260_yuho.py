"""
Baekjoon 1260. DFS와 BFS
https://www.acmicpc.net/problem/1260
"""
import sys
import copy
from typing import Dict, List


class Node(object):
    def __init__(self):
        self.adj_indices = list()   # 인접 노드
        self.visit = False          # 해당 노드를 방문 했는지의 여부


class Graph(object):
    def __init__(self, inputs: List[str]):
        self.n_vertices = int(inputs[0])        # 정점의 개수
        self.n_edges = int(inputs[1])           # 간선의 개수
        self.v_idx = int(inputs[2])             # 탐색을 시작할 정점의 번호
        self.nodes = self.init_node()           # 노드 초기화

    def _insert_edge(self, target_node: int, adj_node: int):
        # 인접 노드 추가
        self.nodes[target_node].adj_indices.append(adj_node)

    def update_edge(self, first_node: int, second_node: int):
        # 양 방항에 대해 모두 인접 노드 정보 추가
        self._insert_edge(first_node, second_node)
        self._insert_edge(second_node, first_node)

    def init_node(self) -> Dict:
        # 노드 개수만큼 그래프 내 노드 객체 초기화
        node_dict = dict()
        for i in range(self.n_vertices):
            node_dict[i + 1] = Node()
        return node_dict


class DFS(object):
    def __init__(self):
        self.result = list()    # 결과 저장을 위한 변수

    def run(self, node_dict: Dict, idx: int):
        # idx: 현재 탐색중인 노드 번호
        node_dict[idx].visit = True     # 방문 처리
        self.result.append(idx)

        # 인접 노드 중에서 아직 방문하지 않은 노드를 당장 방문
        for adj_idx in node_dict[idx].adj_indices:
            if not node_dict[adj_idx].visit:
                self.run(node_dict, adj_idx)

    def print(self):
        # 결과 출력
        print(*self.result)


class BFS(object):
    def __init__(self):
        self.result = list()    # 결과 저장을 위한 변수
        self.queue = list()     # 대기열

    def run(self, node_dict: Dict, start_idx: int):
        self.queue.append(start_idx)
        node_dict[start_idx].visit = True
        idx = start_idx

        while self.queue:
            self.queue.pop(0)       # 대기열에서 현재 탐샥중인 노드 번호 제거
            self.result.append(idx)

            # 인접 노드 중에서 아직 방문하지 않은 노드를 대기열에 추가
            for adj_idx in node_dict[idx].adj_indices:
                if not node_dict[adj_idx].visit:
                    self.queue.append(adj_idx)
                    node_dict[adj_idx].visit = True  # 방문 처리

            # 대기열의 첫번째 노드 방문
            if self.queue:
                idx = self.queue[0]

    def print(self):
        # 결과 출력
        print(*self.result)


def main():
    graph = Graph(input().split())

    # 간선 정보 추가
    for i in range(int(graph.n_edges)):
        edges = sys.stdin.readline().split()
        graph.update_edge(int(edges[0]), int(edges[1]))

    # 노드 순서 정렬
    for node in graph.nodes.values():
        node.adj_indices.sort()

    # 깊이 탐색 알고리즘
    dfs = DFS()
    dfs.run(copy.deepcopy(graph.nodes), graph.v_idx)
    dfs.print()

    # 너비 탐색 알고리즘
    bfs = BFS()
    bfs.run(copy.deepcopy(graph.nodes), graph.v_idx)
    bfs.print()


if __name__ == "__main__":
    main()
