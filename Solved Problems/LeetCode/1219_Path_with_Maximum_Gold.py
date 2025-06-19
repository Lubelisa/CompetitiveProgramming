class Solution:
    maxSumGold = 0

    def calcMaximumGold(self, row, column, grid, path, sum):
        sum += grid[row][column]
        self.maxSumGold = self.maxSumGold if self.maxSumGold > sum else sum
        path.add((row, column))

        neighbors = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        for neighbor in neighbors:
            nextRow = row + neighbor[0]
            nextColumn = column + neighbor[1]
            if (
                nextRow < 0
                or nextRow >= len(grid)
                or nextColumn < 0
                or nextColumn >= len(grid[0])
                or grid[nextRow][nextColumn] == 0
            ):
                continue
            if (nextRow, nextColumn) in path:
                continue
            self.calcMaximumGold(nextRow, nextColumn, grid, path, sum)

        path.remove((row, column))

    def getMaximumGold(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue
                self.calcMaximumGold(i, j, grid, set(), 0)

        return self.maxSumGold

