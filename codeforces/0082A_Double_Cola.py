import sys
import math
def main():
    n = int(sys.stdin.readline().strip())
    x = 0
    cokes = 5 * (math.pow(2,x+1) - 1)
    while  cokes < n:
        x += 1
        cokes = 5 * (math.pow(2,x+1) - 1)
    n -= 5 * (math.pow(2,x) - 1)
    ppl = (n-1) // math.pow(2,x)
    names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
    print(names[int(ppl)])
    

if __name__ ==("__main__"):
    main()
