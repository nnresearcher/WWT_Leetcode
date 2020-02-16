# -*- coding: utf-8 -*-
"""
Created on Fri Jan  3 21:50:53 2020

@author: WWT
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        has_Cycle_Set = set()
        has_Cycle_Set.add(head)
        while(head.next and head.next not in has_Cycle_Set):
            head = head.next
            has_Cycle_Set.add(head)
        if head.next == None:
            return False
        else:
            return True









            