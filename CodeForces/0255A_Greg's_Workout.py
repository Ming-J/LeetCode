"""
gfdgs
n exercise
chest bi and back
"""

import sys


def check(exs):
    chest, bi, back = 0, 0, 0
    for i, x in enumerate(exs):
        module = i % 3
        if module == 0:
            chest += x
        elif module == 1:
            bi += x
        else:
            back += x
    if chest > bi and chest > back:
        print("chest")
    elif bi > chest and bi > back:
        print("biceps")
    else:
        print("back")


def main():
    n = int(sys.stdin.readline())
    arr = map(int, sys.stdin.readline().split())
    check(arr)


if __name__ == "__main__":
    main()
