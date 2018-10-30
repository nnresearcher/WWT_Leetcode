# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:15:08 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/two-sum/description/
"""

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                total=nums[i]+nums[j]
                if total==target:
                    return [i,j]