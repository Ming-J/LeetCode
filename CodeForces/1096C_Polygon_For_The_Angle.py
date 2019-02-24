import sys
import math

def funct(angel):
    min_angel = math.gcd(180,angel)
    n = 180 // min_angel
    if angel / 180 == (n-1)/n :
        n *= 2
    return n

def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        angel = int(sys.stdin.readline())
        print(funct(angel))

if __name__ == "__main__":
    main()