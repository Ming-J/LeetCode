import sys

'''
A and B
GCD(A!,B!)
'''

def calFac(n):
    x = 1
    for i in range(1,n+1):
        x *= i
    return x

def main():
    a, b = [int(x) for x in sys.stdin.readline().split()]
    print(calFac(min(a,b)))

if __name__ == ("__main__"):
    main()
