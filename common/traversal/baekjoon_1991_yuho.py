import sys


class Traversal(object):
    def __init__(self, tree):
        self.tree = tree
        self.result = ""

    def _preorder(self, parent):
        self.result += parent
        if self.tree[parent][0] != ".":
            self._preorder(self.tree[parent][0])
        if self.tree[parent][1] != ".":
            self._preorder(self.tree[parent][1])

    def preorder(self):
        self.result = ""
        self._preorder("A")
        print(self.result)

    def _inorder(self, parent):
        if self.tree[parent][0] != ".":
            self._inorder(self.tree[parent][0])
        self.result += parent
        if self.tree[parent][1] != ".":
            self._inorder(self.tree[parent][1])

    def inorder(self):
        self.result = ""
        self._inorder("A")
        print(self.result)

    def _postorder(self, parent):
        if self.tree[parent][0] != ".":
            self._postorder(self.tree[parent][0])
        if self.tree[parent][1] != ".":
            self._postorder(self.tree[parent][1])
        self.result += parent

    def postorder(self):
        self.result = ""
        self._postorder("A")
        print(self.result)


def main():
    N = int(sys.stdin.readline().split()[0])
    tree_dict = dict()

    # Make binary tree
    for i in range(N):
        user_input = sys.stdin.readline().split()
        tree_dict[user_input[0]] = [user_input[1], user_input[2]]

    # Run algorithm
    traversal = Traversal(tree_dict)
    traversal.preorder()
    traversal.inorder()
    traversal.postorder()


if __name__ == "__main__":
    main()
