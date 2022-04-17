"""
Leetcode 111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/
"""
from typing import Optional


# Definition for a binary tree node.
class Solution:
    def __init__(self):
        self.min_depth = 10000

    def recursion(self, node, rank):
        # 트리 탐색
        if node.left is not None:
            self.recursion(node.left, rank + 1)
        if node.right is not None:
            self.recursion(node.right, rank + 1)

        # leaf node인 경우, minimum depth 계산
        if node.left is None and node.right is None:
            if rank < self.min_depth:
                self.min_depth = rank

    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root:
            self.recursion(root, 1)
            return self.min_depth
        else:
            return 0    # 빈 트리에 대해서 0 리턴
