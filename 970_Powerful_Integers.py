import sys
import math


class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        dic = set()
        for i in range(20):
            for j in range(20):
                sum = x**i + y**j
                if sum <= bound:
                    dic.add(sum)
        return list(dic)


def main():
    t = Solution()
    print(t.powerfulIntegers(1, 2, 100))


if __name__ == "__main__":
    main()
