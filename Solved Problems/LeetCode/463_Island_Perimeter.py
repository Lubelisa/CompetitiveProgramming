class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        self.perimeter = 0
        pos = -1
        for i in range(len(grid)):
            if 1 in grid[i]:
                pos = grid[i].index(1)
                pos = (i, pos)
                break
                
        def calcPerimeter(grid: List[List[int]], x: int, y: int) -> None:
            edges = 4
            grid[x][y] = 2
            
            if x-1 >= 0 and grid[x-1][y] > 0:
                edges-=1
                if grid[x-1][y] == 1:
                    calcPerimeter(grid,x-1,y)
            if y-1 >= 0 and grid[x][y-1] > 0:
                edges-=1
                if grid[x][y-1] == 1:
                    calcPerimeter(grid,x,y-1)
            if x+1 < len(grid) and grid[x+1][y] > 0:
                edges-=1
                if grid[x+1][y] == 1:
                    calcPerimeter(grid,x+1,y)
            if y+1 < len(grid[0]) and grid[x][y+1] > 0:
                edges-=1
                if grid[x][y+1] == 1:
                    calcPerimeter(grid,x,y+1)
                    
            self.perimeter += edges
            
        calcPerimeter(grid, pos[0], pos[1])
        return self.perimeter