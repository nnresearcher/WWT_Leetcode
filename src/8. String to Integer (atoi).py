# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:19:28 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/string-to-integer-atoi/description/
"""

class Solution:
    def myAtoi(self, sstr):
        """
        :type str: str
        :rtype: int
        """
        lists=sstr
        num=['1','2','3','4','5','6','7','8','9','0']
        fuhao=['+','-']
        result=[]
        begin=True
        chenzi=1
        num_result=0
        for one_str in lists:
            if (one_str not in num) and (one_str not in fuhao) and (one_str!=' ') and begin:
                return 0
            if one_str==' ' and begin:
                continue
            if ((one_str==' ') or (one_str in fuhao)) and begin==False:
                break
            #if (one_str in fuhao):
               # if one_str == fuhao[0]:
                #    chenzi=chenzi*1
                #else:
                #    chenzi=chenzi*(-1)\
            if one_str in fuhao and begin:
                result.append(one_str)
                begin=False
                continue
            if one_str in fuhao and begin==False:
                return 0
                continue
                
            if ((one_str in num) or (one_str in fuhao)) :
                result.append(one_str)
                begin=False
                continue
            if (one_str not in num) and (one_str not in fuhao) and (one_str!=' '):
                break
        if result!=[]:
            if result[0]==fuhao[1]:
                chenzi=chenzi*(-1)
                result.pop(0)
            if result==[]:
                return num_result
            if result[0]==fuhao[0]:
                result.pop(0)
            if result==[]:
                return num_result
            a=len(result)
            for i in range(a):
                num_result+=int(result[i])*(10**(a-1))
                a=a-1

            num_result=num_result*chenzi
            if num_result<-2147483648:
                num_result=-2147483648
            if num_result>2147483647:
                num_result=2147483647
        else:
            num_result=0
        return num_result
