import sys
import bisect

class Solution:
    def maxWidthRamp(self, A):
        """ 
        :type A: List[int]
        :rtype: int
        """
        stack = []
        res = 0
        for i in range(len(A))[::-1]:
            if len(stack) == 0 or stack[-1][0] < A[i]:
                stack.append([A[i],i])
            else:
                j = stack[bisect.bisect(stack,[A[i],i])][1]
                res = max(res,j-i)
        return res

def main():
    t = Solution()
    print(t.maxWidthRamp([6,0,8,2,1,5]))
       
if __name__ == "__main__":
    main()