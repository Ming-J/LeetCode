import sys

"""
Can be completed by the following solution

ans = a + b + c
ans = max( (a + b) * c , ans)
ans = max( a * (b + c) , ans)
ans = max( a * b * c , ans)
"""
def main():
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    c = int(sys.stdin.readline().strip())
    sum = 0
    if a > b and a > c and b * c < b + c:
        sum = a * (b + c)
    elif c > b and c > a and a * b < a + b:
        sum = c * (a + b)
    elif a == 1 and c == 1:
        sum = a + b + c
    elif a == 1 :
        sum = (a + b) * c
    elif c == 1:
        sum = a * (b + c)
    elif b == 1:
        sum = (a + b) * c
    else:
        sum =  a * b * c

    print sum    

if __name__ == ("__main__"):
    main()
