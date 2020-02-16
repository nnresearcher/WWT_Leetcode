# -*- coding: utf-8 -*-
"""
Created on Sun Nov 17 15:31:42 2019

@author: WWT
"""
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        matrix = []
        i = 1
        while(1):
            
            if i == 1 or i == numRows:
                tep = ""
                if (len(s) <= numRows):
                    matrix.append(s+" "*(numRows-len(s)))
                    break
                else:
                    matrix.append(s[0:numRows])
                    s = s[numRows:]
            else:
                tep = " "*(numRows-i)
                tep += s[0]
                s = s[1:]
                tep += " "*(i-1)
                matrix.append(tep)
                if s == "":
                    break
            if i == numRows:
                i = 2
            else:
                i+=1
        
        ret = ""
        for i in range(numRows):
            for strr in matrix:
                if strr[i] != " ":
                    ret += strr[i]
        return ret