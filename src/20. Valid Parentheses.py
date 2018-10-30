# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:21:38 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/valid-parentheses/description/
"""


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lens=len(s)
        left=['(','[','{']
        right=[')',']','}']
        temp=[]
        for i in range(lens):
            if s[i] in left:
                temp.append(s[i])
            else:
                if len(temp)==0:
                    return False
                if s[i]==')':
                    if temp[-1]=='(':
                        temp.pop(-1)
                    else:
                        return False
                if s[i]==']':
                    if temp[-1]=='[':
                        temp.pop(-1)
                    else:
                        return False
                if s[i]=='}':
                    if temp[-1]=='{':
                        temp.pop(-1)
                    else:
                        return False
        if len(temp)==0:
            return True
        else:
            return False