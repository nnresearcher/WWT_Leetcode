# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:20:04 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/palindrome-number/description/
"""

class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        str_a=str(x)
        lena=len(str_a)
        for i in range(lena):
            if str_a[i]!=str_a[lena-1-i]:
                return False
        return True
        