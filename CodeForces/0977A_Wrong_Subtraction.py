import sys

def main():
    n, k = [int(x) for x in sys.stdin.readline().split()]
    for x in range(k):
        if n % 10 != 0 :
            n -= 1
        else:
            n //= 10
    print("{:d}".format(n))

if __name__ == ("__main__"):
    main()
