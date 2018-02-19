import sys

def main():
    m, n = [int(x) for x in sys.stdin.readline().strip().split()]
    day = 0
    while m > 0:
        day += 1
        m -= 1
        if day % n is 0:
            m += 1
    print(day)

if __name__ == ("__main__"):
    main()
