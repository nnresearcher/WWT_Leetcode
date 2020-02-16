# -*- coding: utf-8 -*-
"""
Created on Fri Jan  3 21:31:40 2020

@author: WWT
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        pre = head
        head_next = head.next
        head.next = None
        while (head_next.next):
            tmp = head_next.next
            head_next.next = pre
            pre = head_next
            head_next = tmp
        head_next.next = pre
        return head_next
