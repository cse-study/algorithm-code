# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def subtree_to_root(self, start, end):
        if start > end:
            return None

        root_value = self.preorder[self.preorder_idx]   # 현재 탐색중인 preorder 노드의 value
        inorder_idx = self.inorder_hash[root_value]     # 현재 탐색중인 value에 대해 inorder index 확인

        self.preorder_idx += 1  # preorder 탐색 한칸 이동

        # Create node
        root = TreeNode(root_value)
        root.left = self.subtree_to_root(start, inorder_idx - 1)    # 현재 노드 기준으로 왼쪽 subtree에 대해 함수 실행
        root.right = self.subtree_to_root(inorder_idx + 1, end)     # 현재 노드 기준으로 오른쪽 subtree에 대해 함수 실행

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Hashmap for inoder list
        self.inorder_hash = dict()
        for i in range(len(inorder)):
            self.inorder_hash[inorder[i]] = i

        self.preorder = preorder
        self.preorder_idx = 0
        return self.subtree_to_root(0, len(inorder) - 1)
