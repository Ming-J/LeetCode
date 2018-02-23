import sys
import math
def main():
    n = 1802
    x = 0
    while 5 * (math.pow(2,x+1) - 1) < n:
        x += 1
    n -= 5 * (math.pow(2,x) - 1)
    print(n)
    print(x)
    print((n-1) // (x+1))
    

if __name__ ==("__main__"):
    main()
