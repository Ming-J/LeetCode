import sys


def check(n, m, z):
    count = 0
    xn = n
    xm = m
    while xn <= z or xm <= z:
        if xn == xm:
            count += 1
            xn += n
            xm += m
        else:
            if xn < xm:
                xn += n
            else:
                xm = xm + m
    return count


def main():
    n, m, z = map(int, sys.stdin.readline().split())
    print(check(n, m, z))


if __name__ == "__main__":
    main()
