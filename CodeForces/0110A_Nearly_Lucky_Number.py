import sys

def checkNum(n):
    if n is 0:
        return False
    while n > 0 :
        re = n % 10;
        if re is not 4 and re is not 7:
            return False
        n = n / 10
    return True

def main():
    n = sys.stdin.readline().strip()
    sumOfLucky = 0;
    for c in n:
        if c is '4' or c is '7':
            sumOfLucky += 1
    if checkNum(sumOfLucky):
        print "YES"
    else:
        print "NO"

if __name__ == ("__main__"):
    main()
