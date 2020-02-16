# -*- coding: utf-8 -*-
"""
Created on Fri Jan  3 21:59:55 2020

@author: WWT
"""

class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_1 = []
        self.stack_2 = []        

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.stack_1.append(x)
        

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if len(self.stack_2) != 0:
            ret = self.stack_2.pop(-1)
        else:
            while len(self.stack_1) != 0:
                tmp = self.stack_1.pop(-1)
                self.stack_2.append(tmp)
            ret = self.stack_2.pop(-1)
        return ret
        

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if len(self.stack_2) != 0:
            ret = self.stack_2[-1]
        else:
            while len(self.stack_1) != 0:
                tmp = self.stack_1.pop(-1)
                self.stack_2.append(tmp)
            ret = self.stack_2[-1]
        return ret

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        if len(self.stack_2) + len(self.stack_1) == 0:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()