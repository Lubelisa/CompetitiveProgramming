# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        nodes = []
        children = []
        nodes.append(root)
        
        averages = []
        
        while(len(nodes) > 0):
            sum_ = 0.0
            for i in range(len(nodes)):
                sum_ += nodes[i].val
                if nodes[i].left is not None:
                    children.append(nodes[i].left)
                if nodes[i].right is not None:
                    children.append(nodes[i].right)
                    
            av = sum_/len(nodes)
            averages.append(av)
            
            nodes = children[:]
            children = []
            
        return averages
            
                