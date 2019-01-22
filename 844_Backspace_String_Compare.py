import sys

class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s_i = len(S) - 1
        t_i = len(T) - 1
        while s_i >= 0 or t_i >= 0:
            s_char, t_char = "",""
            if s_i >= 0:
                s_char, s_i = self.getChar(S, s_i) 
            if t_i >= 0:
                t_char, t_i = self.getChar(T, t_i)
            if s_char != t_char:
                return False
        return True

    def getChar(self, str, ind):
        char = "" 
        count = 0
        while ind >= 0 and not char:
            if str[ind] == "#":
                count += 1
            elif count == 0:
                char = str[ind]
            else:
                count -= 1
            ind -= 1      
        return char, ind

def main():
    t = Solution()
    print(t.backspaceCompare("nzp#o#g","b#nzp#o#g"))

if __name__ == ("__main__"):
    main()