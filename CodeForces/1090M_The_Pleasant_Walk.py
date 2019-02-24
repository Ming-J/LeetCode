import sys

def check(houses):
    prev = houses[0]
    res = 0
    count = 1
    for i in range(1,len(houses)):
        if prev == houses[i]:
            res = max(res,count)
            count = 1
        else:
            count += 1
        prev = houses[i]
    return max(res,count)
def main():
    n, k = map(int,sys.stdin.readline().split())
    arr = [int(x) for x in sys.stdin.readline().split()]
    print(check(arr))

if __name__ == "__main__":
    main()
