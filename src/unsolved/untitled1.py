# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 23:36:29 2019

@author: WWT
"""

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.all = []
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if word not in self.all:
self.all.append(word)
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if word not in self.all:
            return True
        else:
            return False
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        for word in self.all:
            if word.startswith(prefix):
                return True
            else:
                return False
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)