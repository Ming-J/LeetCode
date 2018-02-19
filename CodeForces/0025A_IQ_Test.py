import sys

def main():
    number = sys.stdin.readline()
    odd = 0
    lastOdd = 0
    even = 0
    lastEven = 0
    arr = [int(x) for x in sys.stdin.readline().strip().split()]
    for i,n in enumerate(arr):
        if n % 2 == 0:
            even += 1
            lastEven = i
        else:
            odd += 1
            lastOdd = i
    if odd > even:
        print(lastEven + 1)
    else:
        print(lastOdd + 1)

if __name__ == ("__main__"):
    main()
