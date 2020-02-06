# https://leetcode-cn.com/problems/integer-to-roman/submissions/


class Solution:
    def intToRoman(self, num):
        ret = self.thousand(num) + self.hundred(num) +self.ten(num) + self.one(num)
        return ret
    def thousand(self, num):
        ret = ""
        if(int(num/1000) != 0):
            ret = ret + "M"*int(num/1000)
        return ret
    
    def hundred(self, num):
        ret = ""
        tmp = int(num%1000/100)
        if(tmp != 0):
            if(tmp == 4):
                ret = "CD"
            elif(tmp == 9):
                ret = "CM"
            elif(tmp == 5):
                ret = "D"
            elif(tmp<4):
                ret = "C"*tmp
            elif(tmp>5):
                ret = "D"+(tmp-5)*"C"
        return ret
    
    def ten(self, num):
        ret = ""
        tmp = int(num%100/10)
        if(tmp != 0):
            if(tmp == 4):
                ret = "XL"
            elif(tmp == 9):
                ret = "XC"
            elif(tmp == 5):
                ret = "L"
            elif(tmp<4):
                ret = "X"*tmp
            elif(tmp>5):
                ret = "L"+(tmp-5)*"X"
        return ret
            
    def one(self, num):
        ret = ""
        tmp = int(num%10)
        if(tmp != 0):
            if(tmp == 4):
                ret = "IV"
            elif(tmp == 9):
                ret = "IX"
            elif(tmp == 5):
                ret = "V"
            elif(tmp<4):
                ret = "I"*tmp
            elif(tmp>5):
                ret = "V"+(tmp-5)*"I"
        return ret      
