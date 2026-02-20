# 761. Special Binary String
class Solution(object):
    def makeLargestSpecial(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = 0
        i = 0
        res = []
        for j, char in enumerate(s):
            if char == '1':
                count += 1
            else: 
                count -= 1
            if count == 0: 
                res.append('1' + self.makeLargestSpecial(s[i+1:j]) + '0')
                i = j+1
        res.sort(reverse = True)
        return "".join(res)
