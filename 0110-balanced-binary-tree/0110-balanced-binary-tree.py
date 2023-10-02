# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.bool_isBalanced = True

        def H(node) -> int:
            if not self.bool_isBalanced:
                return 0

            L, R = 1, 1
            if node.left:
                L = 1 + H(node.left)
            if node.right:
                R = 1 + H(node.right)
            
            if abs(L - R) > 1:
                self.bool_isBalanced = False

            return max(L, R)

        if root:
            H(root)
            return self.bool_isBalanced
        else:
            return True