# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:21:12 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/longest-common-prefix/description/
"""


class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result=""
        if len(strs)==0:
            return ""
        if len(strs)==1:
            return strs[0]
        min_len=len(strs[0])
 
        for i in range(1,len(strs)):
            lens=len(strs[i])
            if lens<min_len:
                min_len=lens
        if min_len==0:
            return ""
        for i in range(min_len):
            a=strs[0][i]
            for j in range(1,len(strs)):
                if a!=strs[j][i]:
                    return result
            result+=a
        return result