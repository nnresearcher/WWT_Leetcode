# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:22:34 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/rotated-digits/description/
"""

class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        good_num=['2','5','9','6']
        better_num1=[2,5,6,9,1,8]
        better_num=[2,5,6,9,0,1,8]
        all_better_num=[]
        num=0
        for i in range(len(better_num1)):
            all_better_num.append(better_num1[i])
        for i in range(len(better_num1)):
            for j in range(len(better_num)):
                all_better_num.append(better_num1[i]*10+better_num[j])
        for i in range(len(better_num1)):
            for j in range(len(better_num)):
                for k in range(len(better_num)):
                    all_better_num.append(better_num1[i]*100+better_num[j]*10+better_num[k])
        for i in range(len(better_num1)):
            for j in range(len(better_num)):
                for k in range(len(better_num)):
                    for p in range(len(better_num)):
                        all_better_num.append(better_num1[i]*1000+better_num[j]*100+better_num[k]*10+better_num[p])
        #
        for i in range(len(all_better_num)-1,-1,-1):
            key=True
            strs=str(all_better_num[i])
            if strs[0]=='0':
                all_better_num.pop(i)
                continue
            for j in range(len(strs)):
                if strs[j] in good_num:
                    key=False
            if key:
                all_better_num.pop(i)
        all_better_num=sorted(all_better_num)   
        for i in range(len(all_better_num)):
            if all_better_num[i]<=N:
                num=num+1
        return num