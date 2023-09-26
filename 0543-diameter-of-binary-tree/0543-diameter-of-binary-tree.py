# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.diameter = 0

    def dfs(self, node: Optional[TreeNode]) -> int:
        left = self.dfs(node.left) if node.left else 0
        right = self.dfs(node.right) if node.right else 0

        # 한쪽 노드에서 경로만들어지는 것 고려
        if left + right > self.diameter:
            self.diameter = left + right
        
        return 1 + max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.diameter


