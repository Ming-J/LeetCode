import sys


def point(l1, l2, r1, r2):
    if l1 == r1 and l2 == r2:
        print(l1, l2)
        return
    x1 = l1 if l1 == r1 else min(l1, r1)
    x2 = l2 if l2 == r2 else max(l2, r2)
    while x1 == x2:
        if l1 != r1:
            x1 += 1
        else:
            x2 += 1
    print(x1, x2)
    return


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        l1, r1, l2, r2 = map(int, sys.stdin.readline().split())
        point(l1, l2, r1, r2)


if __name__ == "__main__":
    main()
