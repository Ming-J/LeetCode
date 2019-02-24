import sys
import math


def square(n):
    sqr = math.sqrt(n)
    upper = int(math.ceil(sqr))
    lower = int(math.floor(sqr))
    if upper == lower:
        return lower * 2
    else:
        if lower * lower + lower >= n:
            return lower * 2 + 1
        else:
            return upper*2


def main():
    n = int(sys.stdin.readline())
    print(square(n))


if __name__ == "__main__":
    main()
