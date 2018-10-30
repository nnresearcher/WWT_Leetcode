# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:30:05 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/3sum/description/
"""
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        mid=0
        right=0
        left=0
        len_num=len(nums)
        if len_num<3:
            return result
        nums.sort()
        while left<len_num-2:
            if nums[left]>0:
                break
            mid=left+1
            right=len_num-1
            if nums[right]<0:
                break
            while mid<right:
                if nums[mid]+nums[right]+nums[left]==0:
                    result.append([nums[left],nums[mid],nums[right]])
                    while mid<right and nums[mid]==nums[mid+1]:
                        mid=mid+1
                    while mid<right and nums[right]==nums[right-1]:
                        right=right-1
                    mid+=1
                    right-=1
                elif nums[mid]+nums[right]<-nums[left]:
                    mid+=1
                else:
                    right-=1
            while left<len_num-2 and nums[left]==nums[left+1]:
                left=left+1
            left+=1
        return result
