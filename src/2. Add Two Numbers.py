# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 21:16:54 2018

@author: WuWenTao

Email:1664962628@qq.com

https://leetcode-cn.com/problems/add-two-numbers/description/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
def digui(k,c,a,temp2_total):
           if k==c:
                  return None
           a=ListNode(int(temp2_total%(10**(k+1))/(10**(k))))
           k=k+1
           a.next=digui(k,c,a.next,temp2_total)
           return a
class Solution:
    def addTwoNumbers(self, l1, l2):
        temp=l1
        num_1=0
        a=0
        while temp:
                num_1+=temp.val*(10**a)
                a=a+1
                temp=temp.next
    
       
        temp=l2
        num_2=0
        a=0
        while temp:
                num_2+=temp.val*(10**a)
                a=a+1
                temp=temp.next

       
        total=num_1+num_2
        c=0
        temp_total=total
        temp2_total=total
        if temp_total==0:
            l3=ListNode(0)
            return l3
        while temp_total!=0:
                temp_total=int(temp_total/10)
                c +=1
        k=0
        l3=ListNode(int(temp2_total%(10**(k+1))/(10**(k))))
        k=k+1      
        a=ListNode(int(temp2_total%(10**(k+1))/(10**(k))))
        a=digui(k,c,a,temp2_total)
        l3.next=a
            
        return l3
            