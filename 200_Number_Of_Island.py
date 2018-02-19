import sys

class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        visitedMap = []
        for x in range(len(grid)):
            row = [False]*len(grid[0])
            visitedMap.append(row)
        count = 0
        self.grid = grid
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == '1' and visitedMap[row][col] == False:
                    self.findIsland(visitedMap,row,col)
                    count += 1
        
        return count
        
        
    def findIsland(self,visitedMap,row,col):
        if not -1 < row < len(self.grid) or not  -1 < col < len(self.grid[0]):
            return
        if visitedMap[row][col] == True or self.grid[row][col] == '0':
            return
        else:
            if self.grid[row][col] == '1':  
                visitedMap[row][col] = True
                self.findIsland(visitedMap,row,col+1)
                self.findIsland(visitedMap,row+1,col)
                self.findIsland(self.grivisitedMap,row-1,col)
                self.findIsland(self.grid,visitedMap,row,col-1)
            else:
                return
