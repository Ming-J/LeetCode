import sys


def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()
    cost = list(map(int, sys.stdin.readline().split()))
    no_h, no_ha, no_har, no_hard = 0, 0, 0, 0
    for i in range(n):
        if s[i] == 'h':
            no_h += cost[i]
        if s[i] == 'a':
            no_ha = min(no_ha+cost[i], no_h)
        if s[i] == 'r':
            no_har = min(no_har+cost[i], no_ha)
        if s[i] == 'd':
            no_hard = min(no_hard + cost[i], no_har)
    print(no_hard)


if __name__ == "__main__":
    main()
