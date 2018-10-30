# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:18:48 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/reverse-integer/description/
"""


class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        fuhao='+'
        strr=str(x)
        new_str=''
        smallest=-2**31
        largest=(2**31)-1
        if strr[0]=='-':
            strr=strr[1:]
            fuhao='-'
        for i in range(len(strr)-1,-1,-1):
            new_str+=strr[i]
        new_str=fuhao+new_str
        num=int(new_str)
        if num<smallest:
            num=0
        if num>largest:
            num=0
        return num