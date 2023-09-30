# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        queue = collections.deque([root])

        while queue:
            node = queue.popleft()
            
            if node:
                # Invert
                node.left, node.right = node.right, node.left
                # None이 추가되도, if node:에서 걸러짐
                queue.append(node.left)
                queue.append(node.right)
        
        return root