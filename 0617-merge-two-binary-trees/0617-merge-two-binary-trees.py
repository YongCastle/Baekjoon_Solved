# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        # root2 -> root1 concat
        queue = collections.deque()
        prev_root1 = TreeNode(0, root1, None)
        queue.append((prev_root1, "left", root1, root2))

        while queue:
            prev_node1, direction, node1, node2 = queue.popleft()

            if node2:
                if node1:
                    node1.val = node1.val + node2.val
                    queue.append((node1, "left", node1.left, node2.left))
                    queue.append((node1, "right", node1.right, node2.right))
                else:
                    if direction == "left":
                        prev_node1.left = node2
                    elif direction == "right":
                        prev_node1.right = node2
                    
        return prev_root1.left

                