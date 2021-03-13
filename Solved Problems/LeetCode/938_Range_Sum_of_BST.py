# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
complexity: O(n)
'''

class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        self.ans = 0
        def calcSum(root: TreeNode, low: int, high: int) -> None:
            if root.val < low:
                if root.right is not None:
                    calcSum(root.right, low, high)
            elif root.val > high:
                if root.left is not None:
                    calcSum(root.left, low, high)
            else:
                self.ans+=root.val
                # print(root.val, self.ans)
                if root.left is not None:
                    calcSum(root.left, low, high)
                if root.right is not None:
                    calcSum(root.right, low, high)
        
        calcSum(root, low, high)
        return self.ans