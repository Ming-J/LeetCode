import sys
import math
"""
4 * 3 / 2 = 10
 10 - 1 -2 - 4 - 1 - 2 - 4
"""


def powertwoSum(n):
    total = n * (n+1) // 2
    sum = 0
    for i in range(30):
        power = pow(2, i)
        if power > n:
            break
        else:
            sum += power
    return total - sum - sum


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        x = int(sys.stdin.readline())
        print(powertwoSum(x))


if __name__ == "__main__":
    main()
