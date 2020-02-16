# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 23:31:37 2019

@author: WWT
"""

class Solution:
    def numIslands(self, grid) -> int:
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    ret += 1
                    grid[i][j] = "0"
                    grid = self.updateGrid(grid, [[i,j]])
        return ret
    
    def updateTmpAndGrid(self, grid, tmp, i, j) :
        if i >=0 and i < len(grid) and j >=0 and j < len(grid[0]) and grid[i][j] == "1":
            grid[i][j] = "0"
            tmp.append([i, j])
        return grid, tmp

    def updateGrid(self, grid, tmp) :
        while(len(tmp) != 0) :
            [i, j] = tmp.pop(0)
            grid, tmp = self.updateTmpAndGrid(grid, tmp, i-1, j)
            grid, tmp = self.updateTmpAndGrid(grid, tmp, i+1, j)
            grid, tmp = self.updateTmpAndGrid(grid, tmp, i, j-1)
            grid, tmp = self.updateTmpAndGrid(grid, tmp, i, j+1)
        return  grid