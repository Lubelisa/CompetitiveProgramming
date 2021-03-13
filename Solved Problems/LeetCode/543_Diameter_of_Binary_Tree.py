# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
        1
    /       \
    2       3
/       \
4       5
/  \    / \
/\  /\
n o     /\
        (...)
        \
         m
         
Complexity of the solution -> O(n)
'''
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.diameter = 0
        
        def diameterSubtree(node: TreeNode) -> int:
            if node is None:
                return 0
            Left = diameterSubtree(node.left)
            Right = diameterSubtree(node.right)
            self.diameter = max(self.diameter, Left + Right)
            return max(Left, Right) + 1
        
        diameterSubtree(root)
        return self.diameter
        