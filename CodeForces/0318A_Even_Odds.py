import sys

def calK(num,kth):
    if num % 2 == 0:
        if kth > num/2 :
            return 2 * (kth - num//2)
        else:
            return 1 + 2 * (kth - 1)
    else:
        if kth > (num//2 + 1) :
            return 2 * (kth - (num//2 +1))
        else:
            return 1 + 2 * (kth - 1)
        
def main():
    n, k = map(int, sys.stdin.readline().strip().split())
    print (calK(n, k))

if __name__ == ("__main__"):
    main()
