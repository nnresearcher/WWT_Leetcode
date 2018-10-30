# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:20:45 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/roman-to-integer/description/
"""



class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        a=[str(x) for x in s]
        sp=['IV','IX','XL','XC','CD','CM']
        dic={}
        
        dic['I']=1
        dic['V']=5
        dic['X']=10
        dic['L']=50
        dic['C']=100
        dic['D']=500
        dic['M']=1000
        dic['IV']=4
        dic['IX']=9
        dic['XL']=40
        dic['XC']=90
        dic['CD']=400
        dic['CM']=900
        result=0
        
        while a:
            temp=a.pop(0)
            if len(a)!=0:
                test=temp+a[0]
                if test in sp:
                    result+=dic[test]
                    a.pop(0)
                else:
                    result+=dic[temp]
            else:
                 result+=dic[temp]
        return result