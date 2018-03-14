import sys

def gcd(a,b):
    while b % a != 0:
        b %= a
        if a > b:
            t = b
            b = a
            a = t
    return a
            
def games(s, a, stones):
    first = True
    while stones != 0:
        if first:
            check = s
            first = False
        else:
            check = a
            first = True
        if check > stones:
            rem = gcd(check,stones)
        else:
            rem = gcd(stones,check)
        stones -= rem
    if first:
        return 1
    else:x
        return 0

def main():
    s, a, stones = [int(x) for x in sys.stdin.readline().strip().split()]
    print(games(s, a, stones))

if __name__ == ("__main__"):
    main()
