import sys

def main():
    n = int(sys.stdin.readline().strip())
    sum = n / 2
    if n % 2 != 0:
        sum *= -1;
        sum -= 1;
    print sum

if __name__ == ("__main__"):
    main()
